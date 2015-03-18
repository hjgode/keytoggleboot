# History and usage KeyToggleBoot #

## Function ##

Define a key sequence to bring up a dialog to enable the user to Shutdown/Reboot a CN50

## Configuration ##

Configuration is done by registry
```
				REGEDIT4

				[HKEY_LOCAL_MACHINE\Software\Intermec\KeyToggleBoot]
				"ForbiddenKeys"=hex:\
					  00
					list of vk_ values of forbidden keys
				"RebootText"="Neustart"
					text on the Reboot button
				"QuestionText"="Sie haben den Reboot-Dialog geöffnet. Was möchten Sie?"
					text for the message
				"CancelText"="Abbrechen"
					text for the cancel button
				"ShutdownText"="Herunterfahren"
					text for the shutdown button
				"SuspendText"="Standby"
					text for the standby button
				"KeySeq"="***"
					char sequence to trigger the app
				"Timeout"=dword:00000003
					time allowed to enter char sequence
				"LEDid"=dword:00000001
					ID of the LED to toggle when the sequence is triggered
```

## Command Line arguments ##

You can use "KeyToggleBoot.exe -writereg" to get the default
registry entries written to the registry

## Hardware ##

Tested with 700 color and CN3 / WM5, CN50 / WM 6.1

## History ##
> 3.3.2		added registry keys
> > RebootExt
> > RebootExtApp
> > RebootExtParms
> > added code to start external app instead of showing internal dialog


> 3.3.1		changed reboot code:
> > BOOL ResetPocketPC()
> > {
> > > SetSystemPowerState(NULL, POWER\_STATE\_RESET, 0);
> > > return 0;
> > > //DWORD dwRet=0;
> > > //return KernelIoControl(IOCTL\_HAL\_REBOOT, NULL, 0, NULL, 0, &dwRet);

> > }
> > For whatever reason KernelIOCtl does not work anymore


> 3.3.0		added code to read button texts from Registry
> > REGEDIT4


> [HKEY\_LOCAL\_MACHINE\Software\Intermec\KeyToggleBoot]
> "ForbiddenKeys"=hex:\
> > 00

> "RebootText"="Neustart"
> "QuestionText"="Sie haben den Reboot-Dialog geöffnet. Was möchten Sie?"
> "CancelText"="Abbrechen"
> "ShutdownText"="Herunterfahren"
> "SuspendText"="Standby"
> "KeySeq"="**"
> "Timeout"=dword:00000003
> "LEDid"=dword:00000001
> font in dialog changed to Tahoma 8pt and resized buttons
> changed registry.h and splitted to registry.h and cpp**

> 3.2.0		imported to VS2008 and fixed some pointer bugs
> > added Suspend option


> 3.1.1		fixed pForbiddenKeyList size recognition by adding 0x00 as end marker
> > cannot use sizeof(pForbiddenKeyList) as this returns size of pointer


> 3.1.0		added ForbiddenKeyList to code and registry
> > [HKEY\_LOCAL\_MACHINE\Software\Intermec\KeyToggleBoot]
> > "KeySeq"=string:"**.#"
> > > "LEDid"=dword:00000001
> > > "Timeout"=dword:00000003

> > "ForbiddenKeys"=hex:\
> > > 72,73

> > ForbiddenKeys is a binary list of byte codes. These byte codes define
> > the VK values to be catched and consumed by KeyToggleBoot
> > in example, the VK code for F3 and F4 is 0x72 and 0x73. So KeyToggleBoot
> > will not forward these two keys, neither WM\_KEYDOWN nor WM\_KEYUP will be
> > send.**


> 3.0.0		first release of coding to KeyToggleBoot
> > added LEDid code
> > LEDid defines the ID of the LED to use for showing sticky state
> > > [HKEY\_LOCAL\_MACHINE\Software\Intermec\KeyToggleBoot]
> > > "KeySeq"=string:"**.#"
> > > > "LEDid"=dword:00000001
> > > > "Timeout"=dword:00000003**


> 2.1.1		~
> > changed code to catch sticky key

> 2.1		+
> > Added Registry code to read vars from Reg
> > [HKEY\_LOCAL\_MACHINE\SOFTWARE\Intermec\KeyToggleBoot]
> > StickyKey = DWORD	defines the VK_Value for the Sticky Key, default is VK\_NUMLOCK is 0x90
> > Timeout = DWORD		defines the time the sticky key is active, specify in seconds!, default is 3
> > autoFallback = DWORD	defines, if the sticky state is reset after a number key is pressed
> > +
> > Added code for LEDs
> > -

> 2.0		initial release, started from iHook3_