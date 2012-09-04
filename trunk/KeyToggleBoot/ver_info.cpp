//ver_info.cpp

#include "ver_info.h"

BOOL myGetVersionInfo(HMODULE hLib, TCHAR* csEntry, TCHAR* szVersion)
{
	BOOL bRet = FALSE;
	
	if(hLib==NULL)
		hLib = GetModuleHandle(NULL);

	HRSRC hVersion = FindResource( hLib, 
	MAKEINTRESOURCE(VS_VERSION_INFO), RT_VERSION );
	if (hVersion != NULL)
	{
		HGLOBAL hGlobal = LoadResource( hLib, hVersion ); 
		if ( hGlobal != NULL)  
		{  
			LPVOID versionInfo  = LockResource(hGlobal);  
			if (versionInfo != NULL)
			{
				DWORD vLen,langD;
				BOOL retVal;    

				LPVOID retbuf=NULL;

				static TCHAR fileEntry[256];

				wsprintf(fileEntry,L"\\VarFileInfo\\Translation");
				retVal = VerQueryValue(versionInfo, fileEntry, &retbuf, (UINT *)&vLen);
				if (retVal && vLen==4) 
				{
					memcpy(&langD,retbuf,4);            
					wsprintf(fileEntry, L"\\StringFileInfo\\%02X%02X%02X%02X\\%s",
						  (langD & 0xff00)>>8,langD & 0xff,(langD & 0xff000000)>>24, 
						  (langD & 0xff0000)>>16, csEntry);            
				}
				else 
				  wsprintf(fileEntry, L"\\StringFileInfo\\%04X04B0\\%s", 
					GetUserDefaultLangID(), csEntry);

				if (VerQueryValue(versionInfo,fileEntry,&retbuf,(UINT *)&vLen)) {
					wsprintf(szVersion, L"%s", retbuf);
					bRet=TRUE;
				}
			}
		}

		// UnlockResource( hGlobal );  
		//FreeResource( hGlobal );  
	}
	return bRet;
}