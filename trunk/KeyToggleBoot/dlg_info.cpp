//dlg_info.cpp

#include "dlg_info.h"
#include "resource.h"

HWND g_hDlgInfo;
//forward declaration
BOOL CALLBACK InfoDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);

HWND createDlgInfo(HWND hwnd, TCHAR* szMsg){
	g_hDlgInfo = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DLGINFO), hwnd, InfoDlgProc);
    if(g_hDlgInfo != NULL)
    {
		SetWindowPos(g_hDlgInfo, HWND_TOPMOST, 0,0,0,0, SWP_NOSIZE | SWP_NOMOVE | SWP_SHOWWINDOW);
        ShowWindow(g_hDlgInfo, SW_HIDE);
    }
    else
    {
        DEBUGMSG(1, (L"CreateDialog returned NULL\nhwnd=0x%08x, error=%i\n", hwnd, GetLastError()));
    }
	return g_hDlgInfo;
}

BOOL CALLBACK InfoDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_BUTTON1:
                    MessageBox(hwnd, L"Hi!", L"This is a message", 
                        MB_OK | MB_ICONEXCLAMATION);
                break;
                case ID_BUTTON2:
                    MessageBox(hwnd, L"Bye!", L"This is also a message", 
                        MB_OK | MB_ICONEXCLAMATION);
                break;
            }
        break;
        default:
            return FALSE;
    }
    return TRUE;
}