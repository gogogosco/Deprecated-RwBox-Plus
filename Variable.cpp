//---------------------------------------------------------------------------

#pragma hdrstop

#include "Variable.h"
//---------------------------------------------------------------------------


bool CloseGame = false;
/* �����C������ */
char LoginerPath[255];
/* �n�J���Ҧb���| */
char GameAccount[255];
/* �C���b�� */
HWND hWndMS;
/* �����������y�� */
HWND hWndLoginer;
DWORD GameThreadId = 0;
/*
MOV EAX,DWORD PTR FS:[0x18]
MOV EBX,DWORD PTR DS:[EAX+0x24]
EBX=THREADID
*/
int LoginServer = 17;
int LoginChannel = 5;
int LoginChar = 0;
/* �۰ʵn�J�Ѽ� */

int HP_Now = 0;
int HP_Max = 0;
int MP_Now = 0;
int MP_Max = 0;
long long EXP_Now = 0;
long long EXP_Max = 0;

/* ����O�@��T */
int AutoGuagi_Start =  0;
int AutoGuagi_OnOff = 0;
int AutoGuagi_X = 0;
int AutoGuagi_Y = 0;
int AutoGuagi_MapId = 0;
int AutoGuagi_Status = 0;
/* �۰ʱ�����T */

int AutoKey_HP_Value = 0;
int AutoKey_MP_Value = 0;



int AutoKey_Pick_Time = 100;
int AutoKey_Pick_Ticket = 0;
int AutoKey_Att_Time = 100;
int AutoKey_Att_Ticket = 0;
int AutoKey_Skill_Time[] = {60,60,60,60};
int AutoKey_Skill_Ticket[] = {0,0,0,0};

unsigned char AutoKey_Att_Key = 0;
unsigned char AutoKey_Pick_Key = 0;
unsigned char AutoKey_Skill_Key[] = {0,0,0,0};

int AutoKey_HP_OnOff = 0;
int AutoKey_MP_OnOff = 0;
int AutoKey_Pick_OnOff = 0;
int AutoKey_Att_OnOff = 0;
int AutoKey_Skill_OnOff[] = {0,0,0,0};


/* �۰ʫ����T */

int Taxi_OnOff = 0;
/* �p�{����T */
HICON hIcon1;



int Data_MobCount;
int Data_RedCount;
int Data_CharLR;


#pragma package(smart_init)