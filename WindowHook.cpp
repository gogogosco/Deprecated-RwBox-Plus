//---------------------------------------------------------------------------

#pragma hdrstop
#include "FormMain.h"

#include <windows.h>
#include <string.h>
#include <wchar.h>
#include "DllMain.h"
#include "Script.h"
#include "WindowHook.h"
#include "Variable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

DWORD tid;


BOOL CALLBACK MyEnumProc(HWND hwnd, LPARAM lParam)
{
	DWORD pid;
	TCHAR tmpClassName[255];
	tid = GetWindowThreadProcessId(hwnd, &pid);
	if (IsWindowEnabled(hwnd) && IsWindowVisible(hwnd) && GetCurrentProcessId() == pid)
	{
		GetClassName(hwnd, tmpClassName, 255);
		if (!_tcscmp(tmpClassName, _T("StartUpDlgClass")))
		{
			PostMessage(hwnd, WM_KEYDOWN, VK_ESCAPE, 0x00010001);
			PostMessage(hwnd, WM_KEYUP, VK_ESCAPE, 0x0C010001);
			hWndMS = NULL;
		}
		else if (!_tcscmp(tmpClassName, _T("MapleStoryClass")))
		{
			hWndMS = hwnd;
		}
		return false;
	}

	return true;
}

//---------------------------------------------------------------------------

HHOOK hKeyHook;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	bool bKeyUp = lParam & (1 << 31);
	if (nCode == HC_ACTION && bKeyUp)
	{
		switch (wParam)
		{
			case VK_F1:
				frmMain->ck_func_godmode->IsChecked = !frmMain->ck_func_godmode->IsChecked;
				break;
			case VK_F2:
				frmMain->WalkSpeedUpSwitch();
				break;
			case VK_F3:
				frmMain->OpenTaxiWindow();
				break;
			case VK_F9:
				AutoGuagi_OnOff = AutoGuagi_OnOff == 0 ? AutoGuagi_OnOff = 1 : AutoGuagi_Status = -2;
			default:
				break;
		}
	}
    return CallNextHookEx(hKeyHook, nCode, wParam, lParam);
}
//---------------------------------------------------------------------------

void InstallWindowHook()
{

#ifdef AUTO_PLAY
    Sleep(1000);
	EnumWindows((WNDENUMPROC)MyEnumProc, 0);
	hWndMS = NULL;
	Sleep(5000);
#endif

	while (hWndMS == NULL)
		EnumWindows((WNDENUMPROC)MyEnumProc, 0);


	hKeyHook = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)KeyboardProc, hinstDll, tid);
	if (hKeyHook == NULL) {
		TerminateProcess(GetCurrentProcess(),0);
	}
}
//---------------------------------------------------------------------------

void UninstallHook()
{
	if (!hKeyHook)
	{
		UnhookWindowsHookEx(hKeyHook);
		hKeyHook = NULL;
	}
}