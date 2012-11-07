//idleBeeper.cpp

#include "stdafx.h"

#include <itc50.h>
#pragma comment (lib, "itc50.lib")

//events to control beeper and idle thread
//	Idle thread control
HANDLE	h_resetIdleThread=NULL;	//event handle
HANDLE	h_stopIdleThread=NULL;	//event handle
HANDLE	h_IdleThread=NULL;		//thread handle
DWORD	threadIdleID=0;			//thread ID

//	Beeper thread control
HANDLE	h_stopBeeperThread=NULL;	//event handle
HANDLE	h_BeeperThread=NULL;		//thread handle
DWORD	threadBeeperID=0;			//thread ID

//HANDLE hBeeperThread=NULL;

//forward declarations
DWORD WINAPI beeperThread(LPVOID lParam);
DWORD WINAPI idleThread(LPVOID lParam);

//
BOOL isACpower(){
	DWORD lpdwLineStatus=0;
	DWORD lpdwBatteryStatus=0;
	DWORD lpdwBackupStatus=0;
	UINT puFuelGauge=0;
	HRESULT hr = ITCPowerStatus (&lpdwLineStatus,&lpdwBatteryStatus,&lpdwBackupStatus,&puFuelGauge);
	if(hr==ITC_SUCCESS){
		if(lpdwLineStatus==ITC_ACLINE_CONNECTED)
			return TRUE;
		else
			return FALSE;
	}
	else
		return FALSE;
}

///start a timer with a interval of x seconds
void startIdleThread(UINT iTimeOut){
	DEBUGMSG(1,(L"startIdleThread entered\n"));
#ifdef DEBUG
	iTimeOut=5*1000;	//we need seconds
#else
	iTimeOut=iTimeOut*1000;	//we need seconds
#endif
	//init event HANDLES
	h_resetIdleThread=CreateEvent(NULL, FALSE, FALSE, L"h_resetIdleThread");
	h_stopIdleThread=CreateEvent(NULL, FALSE, FALSE, L"h_stopIdleThread");
	h_stopBeeperThread=CreateEvent(NULL, FALSE, FALSE, L"h_stopBeeperThread");

	h_IdleThread = CreateThread(NULL, 0, idleThread, (LPVOID)iTimeOut, 0, &threadIdleID);
	DEBUGMSG(1, (L"idle thread started with handle=0x%x\n", h_IdleThread));
}


void stopIdleThread(){
	DEBUGMSG(1, (L"stopTimer entered\n"));
	if(h_IdleThread==NULL)	//is thread running
		return;	//no timer running
	SetEvent(h_stopIdleThread);	
}

void stopBeeper(){
	DEBUGMSG(1, (L"stopBeeper entered\n"));
	if(h_BeeperThread==NULL)	//is thread running
		return;	//no timer running
	SetEvent(h_stopBeeperThread);	
}

void resetIdleThread(){
	DEBUGMSG(1, (L"resetIdleThread entered\n"));
	if(h_IdleThread==NULL)	//is thread running
		return;	//no timer running
	SetEvent(h_resetIdleThread);	
}

DWORD WINAPI beeperThread(LPVOID lParam){
	DEBUGMSG(1, (L"beeperThread entered\n"));
	BOOL bStopThread=FALSE;
	HANDLE waitHandles[1];
	waitHandles[0]=h_stopBeeperThread;
	do{
		DWORD dwWait = WaitForMultipleObjects(1, waitHandles, FALSE, 5000);
		switch(dwWait){
			case WAIT_OBJECT_0:
				//stop
				DEBUGMSG(1,(L"beeperThread stop signaled\n"));
				bStopThread=TRUE;
				break;
			case WAIT_TIMEOUT:
				DEBUGMSG(1,(L"beeperThread timeout. Beeping\n"));
				//issue some sound
#ifdef DEBUG
				MessageBeep(MB_ICONASTERISK);
				Sleep(700);
				MessageBeep(MB_ICONASTERISK);
				Sleep(300);
				MessageBeep(MB_ICONERROR);
				Sleep(700);
				MessageBeep(MB_ICONERROR);
#else
				if( ITCIsAudioToneSupported() )
				{
					HRESULT hr;
					hr = ITCAudioPlayTone( 2400, 200, ITC_GetToneVolumeVeryLoud() );
					hr = ITCAudioPlayTone( 1200, 200, ITC_GetToneVolumeVeryLoud() );
					hr = ITCAudioPlayTone( 2400, 200, ITC_GetToneVolumeVeryLoud() );
					hr = ITCAudioPlayTone( 0, 1000, 0 );
					hr = ITCAudioPlayTone( 2400, 200, ITC_GetToneVolumeVeryLoud() );
					hr = ITCAudioPlayTone( 1200, 200, ITC_GetToneVolumeVeryLoud() );
					hr = ITCAudioPlayTone( 2400, 200, ITC_GetToneVolumeVeryLoud() );
				}
				else{
					MessageBeep(MB_ICONASTERISK);
					Sleep(300);
					MessageBeep(MB_ICONERROR);
				}
#endif
				break;
		}
	}while(!bStopThread);
	DEBUGMSG(1,(L"beeperThread stopped\n"));
	h_BeeperThread=NULL;
	return 0;
}

DWORD WINAPI idleThread(LPVOID lParam){
	HANDLE waitHandles[2];
	waitHandles[0]=h_resetIdleThread;
	waitHandles[1]=h_stopIdleThread;
	BOOL bStopThread=FALSE;
	DWORD dwTimeout=(DWORD) lParam;
	DEBUGMSG(1,(L"idleThread starting with %i\n", dwTimeout));
	do{
		DWORD dwWait = WaitForMultipleObjects(2, waitHandles, FALSE, dwTimeout);
		switch(dwWait){
			case WAIT_OBJECT_0:
				//reset idle, do nothing
				DEBUGMSG(1,(L"idleThread reset signaled\n"));
				break;
			case WAIT_OBJECT_0+1:
				DEBUGMSG(1,(L"idleThread stop signaled\n"));
				bStopThread=TRUE;
				break;
			case WAIT_TIMEOUT:
				//is on AC power?
				if(! isACpower() ){
					//start beeper if not running
					DEBUGMSG(1,(L"idleThread timeout...\n"));
					if(h_BeeperThread==NULL){
						DEBUGMSG(1,(L"idleThread Create Beeper Thread...\n"));
						h_BeeperThread = CreateThread(NULL, 0, beeperThread, NULL, 0, &threadIdleID);
					}
					else
						DEBUGMSG(1,(L"idleThread Beeper Thread already running\n"));
				}
				else
					DEBUGMSG(1, (L"idleThread timeout, skipped start beeper as on AC power\n"));
				break;
		}
	}while (!bStopThread);
	h_IdleThread=NULL;
	DEBUGMSG(1,(L"idleThread ended\n"));
	return 0;
}
