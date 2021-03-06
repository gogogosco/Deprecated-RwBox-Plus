//---------------------------------------------------------------------------

#ifndef VariableH
#define VariableH
#include <windows.h>
//---------------------------------------------------------------------------
#define WM_PING      (WM_USER+123)
extern int LoginServer;
extern int LoginChannel;
extern int LoginChar;

extern bool CloseGame;

extern char GameAccount[255];
extern char LoginerPath[255];
extern HWND hWndLoginer;
extern HWND hWndMS;
extern DWORD GameThreadId;

extern int HP_Now;
extern int HP_Max;
extern int MP_Now;
extern int MP_Max;
extern long long EXP_Now;
extern long long EXP_Max;



extern int AutoKey_HP_Value;
extern int AutoKey_MP_Value;



extern int AutoKey_Pick_Time;
extern int AutoKey_Pick_Ticket;
extern int AutoKey_Att_Time;
extern int AutoKey_Att_Ticket;
extern int AutoKey_Skill_Time[];
extern int AutoKey_Skill_Ticket[];

extern unsigned char AutoKey_Pick_Key;
extern unsigned char AutoKey_Att_Key;
extern unsigned char AutoKey_Skill_Key[];

extern int AutoKey_HP_OnOff;
extern int AutoKey_MP_OnOff;
extern int AutoKey_Pick_OnOff ;
extern int AutoKey_Att_OnOff ;
extern int AutoKey_Skill_OnOff[];

extern int AutoGuagi_OnOff;
extern int AutoGuagi_X;
extern int AutoGuagi_Y;
extern int AutoGuagi_MapId;
extern int AutoGuagi_Status;
extern int AutoGuagi_Start;


extern HICON hIcon1;
extern int Taxi_OnOff;
#endif
