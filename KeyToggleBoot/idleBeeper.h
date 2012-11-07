// idleBeeper.h
#include "stdafx.h"

#ifndef _IDLE_BEEPER_H_
#define _IDLE_BEEPER_H_

void startIdleThread(UINT iTimeOut);
void stopIdleThread();
void resetIdleThread();
void stopBeeper();

#endif