//---------------------------------------------------------------------------

#pragma hdrstop

#include "Script.h"
#include "Pointer.h"
#include "Variable.h"
#include "FormMain.h"
#include "Function.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
/* 完全無敵 */

int GodMode_OnOff = 1;

DWORD GodMode_ICS_Addr = 0x012B32FC;
DWORD GodMode_ICS_Value = R(GodMode_ICS_Addr);

DWORD GodMode_Main_Addr = (DWORD)GodMode_Main;

SCRIPT_START(GodMode_Entry)

	Cmp [GodMode_OnOff],0
	Je Return

	Cmp [Esp],0x00CFC7A0
	Je GodeMode
	Cmp [Esp],0x0079788D
	Je NoBack
	
	Return:
	AJUMP(GodMode_ICS_Value)

	GodeMode:
	AMOVESP(0,GodMode_Main_Addr)
	Jmp Return
	NoBack:
	Mov [Esp+0xAC],0x38FFFFFF
	Jmp Return
	 
SCRIPT_END


SCRIPT_START(GodMode_Main)
		Push Eax
		ACALL(0x0087a6e6)
		Push [Ebx+0x00000460]
		Mov [Ebp-0x3C],Eax
		Mov [Ebp-0x28],Edi
		Mov [Ebp-0x48],Edi
		Mov [Ebp-0x000000A0],Edi
		Mov [Ebp-0x00000094],Edi
		Mov [Ebp-0x00000090],Edi
		Mov [Ebp-0x000000B4],Edi
		Mov [Ebp-0x2C],Edi
		Mov [Ebp-0x000000B0],Edi
		Mov [Ebp-0x000000A4],Edi
		Mov [Ebp-0x0000008B],Edi
		ACALL(0x004d710b)
		Push [Ebx+0x00000464]
		Mov [Ebp-0x64],Eax
		ACALL(0x004d710b)
		Add Esp,0x14
		Mov [Ebp-0x70],Eax
		Cmp [ebp+0x58],Edi
		AJUMP(0x00CFECB2)   
SCRIPT_END

//---------------------------------------------------------------------------
/* 攻擊不停 */
int CSX_OnOff = 0;

DWORD CSX_ICS_Addr = 0x012B96B0;
DWORD CSX_ICS_Value = R(CSX_ICS_Addr);


SCRIPT_START(CSX_Entry)
	Cmp [CSX_OnOff],0
	Je Normal
	Push Ebp
	Mov Ebp,Esp
	Push Ebx
	Push Esi
	Mov Esi,[Ebp+0x08]
	Xor Ebx,Ebx
	Push Edi
	Cmp [Esi+0x70],Ebx
	Jne Label_00D85589
	//8B 46 ** 3B C3 ** ** 68 ** ** ** ** E8 ** ** ** ** 83 EC ** 8B 08
	mov ecx,[0x015487d0]
	ACALL(0x00d85554)
	mov [ebp+0x08],eax
	fild dword ptr [ebp+0x08]
	mov edi,[ebp+0x0c]
	fdiv qword ptr [0x011c6bd0]
	fstp qword ptr [ebp+0x34]
	Cmp edi,ebx
	Je Label_00D8560A
	fld qword ptr [esi+0x00000094]
	Push ecx
	fsub qword ptr [esi+0x74]
	Push ecx
	fmul qword ptr [ebp+0x34]
	fadd qword ptr [esi+0x74]
	fstp qword ptr [esp]
	ACALL(0x005afaaa)
	pop ecx
	pop ecx
	Push Eax 
	Mov Eax,[PeopleBase] 
	Mov Eax,[Eax+PeopleSkillCount]
	Cmp Eax,0xA 
	Pop Eax 
	Jl CSXReturn
	Push Eax
	Mov Eax,[PeopleBase]
	Mov Eax,[Eax+PeopleSkillCount]
	Cmp Eax,0xA
	Pop Eax 
	Add Eax,0x0a 
	Jmp CSXReturn 

	CSXReturn: 
	Mov [Edi],Eax 
	Mov edi,[Ebp+0x10] 
	AJUMP(0x00D855E9) 
	//3B FB 74 ** DD 86 ** ** 00 00 51 DC [1/4]
	Label_00D85589:
	AJUMP(0x00D85589)
	Label_00D8560A:
	AJUMP(0x00D8560A)
	Normal:
	AJUMP(CSX_ICS_Value)
SCRIPT_END

//---------------------------------------------------------------------------
/* 超級定怪 */

int SuperDiagua_OnOff = 0;

DWORD SuperDiagua_ICS_Addr = 0x012B8968;
DWORD SuperDiagua_ICS_Value = R(SuperDiagua_ICS_Addr);

SCRIPT_START(SuperDiagua_Entry)
	Cmp [SuperDiagua_OnOff],0
	Je Back
	Cmp [Esp],0x00D7F070 
	//85 C0 ** ** FF 74 24 ** 8B 06
	Jne Back
	Mov [Esp],0x00D7F087
	Back:
	AJUMP(0x00D7F08F)
SCRIPT_END
//---------------------------------------------------------------------------
/* 超級笨怪 */
DWORD GetLastError_Addr = (DWORD)GetProcAddress(GetModuleHandle(_T("Kernel32.dll")), "GetLastError");

int SuperMobStupid_OnOff = 0;
DWORD SuperMobStupid_ICS_Addr = 0x0106317C;
DWORD SuperMobStupid_ICS_Value = R(SuperMobStupid_ICS_Addr);
DWORD SuperMobStupid_Main_Addr = (DWORD)SuperMobStupid_Main;



SCRIPT_START(SuperMobStupid_Entry)
	Cmp [SuperMobStupid_OnOff],0
	Je Return
	Cmp [Esp+0x38],0x00D8904B
	Jne Return
	AMOVESP(0x38,SuperMobStupid_Main_Addr)
	Return:
	AJUMP(GetLastError_Addr)
SCRIPT_END

SCRIPT_START(SuperMobStupid_Main)
	Xor Edi,Edi
	AJUMP(0x00D89052)
SCRIPT_END
//---------------------------------------------------------------------------
/* 移除背景 */
int NoBkImg_OnOff = 0;
//---------------------------------------------------------------------------
DWORD GetInfo_ICS_Addr = 0x010632A0;
DWORD GetInfo_ICS_Value = R(GetInfo_ICS_Addr);



SCRIPT_START(GetInfo_Entry)
    /* 移除背景 */
	Cmp [NoBkImg_OnOff],0
	Je NoBkReturn
	Cmp [Esp+0x08],0x007488B7 //83 C4 ** 3B DE 74 ** F6 C3 ** 75 1C E8
	Jne NoBkReturn
	Mov [Esp+0x08],0x0074896C // 007488D9 - 0f 84 8d 00 00 00          - je 0074896c & 0074896C - 8b 45 50                   - mov eax,[ebp+50]
	//-----------------------
	NoBkReturn:
	cmp [Esp+0x08],0x00BB5BE4
	je GetHpMp
	Return:
	AJUMP(GetInfo_ICS_Value)
	GetHpMp:
	push eax
	push ecx
	mov eax,[ebp+0x08]
	mov [HP_Now],eax
	mov eax,[ebp+0x0C]
	mov [HP_Max],eax
	mov eax,[ebp+0x10]
	mov [MP_Now],eax
	mov eax,[ebp+0x14]
	mov [MP_Max],eax
	mov eax,[ebp+0x18]
	lea ecx,EXP_Now
	mov [ecx],eax
	mov eax,[ebp+0x1C]
	add ecx,4
	mov [ecx],eax
	mov eax,[ebp+0x20]
	lea ecx,EXP_Max
	mov [ecx],eax
	mov eax,[ebp+0x24]
	add ecx,4
	mov [ecx],eax
	pop ecx
	pop eax
	ret 0004
SCRIPT_END
//---------------------------------------------------------------------------
/* 全圖打怪 */
HINSTANCE OLEAUT32Inst = ::LoadLibrary(_T("OleAut32.dll"));
DWORD OLEAUT32_VariantInit = (DWORD) GetProcAddress(OLEAUT32Inst,"VariantInit");

int FullMap_OnOff = 0;

DWORD FullMap_ICS_Addr = 0x010632AC;
DWORD FullMap_ICS_Value = R(FullMap_ICS_Addr);

DWORD FullMap_Bypass_Addr = (DWORD)FullMap_Bypass;
DWORD FullMap_Main_Addr = (DWORD)FullMap_Main;

SCRIPT_START(FullMap_Entry)
	FlllMapAtt_ICS:
	Cmp [FullMap_OnOff],0
	Je Return
	Cmp [Esp+0xC],0x00798E46 //8B 8E ** ** ** ** C7 45 FC ** ** ** ** 3B CB 0F 84 ** ** ** ** 8D 85
	Je FlllMapAttByPass
	Cmp [Esp+0xC],0x00798C71 //8B 8E ** ** ** ** C7 45 FC ** ** ** ** 3B CB 75 0A 68 [2/2]
	Je FlllMapAttack
	Return:
	Jmp OLEAUT32_VariantInit
	FlllMapAttByPass:
	Push [FullMap_Bypass_Addr]
    Pop [Esp+0x0C]
	Jmp Return
	FlllMapAttack:
	Push [FullMap_Main_Addr]
	Pop [Esp+0x0C]           //這裡做HOOK ESP
	Jmp Return
SCRIPT_END


SCRIPT_START(FlllMapAttackCall)
	push esi
	push edi
	mov edi,[esp+0x0C]
	pushad
	mov ecx,[PeopleBase] //人物基址
	add ecx, 0x04
	push edi
	ACALL(0x0054A0F8) //55 8B EC 51 51 8D 45 ** 50 81 [5/16]
	popad
	AJUMP(0x0048CC6C)
SCRIPT_END


SCRIPT_START(FullMap_Main)
	mov ecx,[esi+0x000001b4]
	mov [ebp-0x04],0xE
	lea eax,[ebp-0x00000098]
	push eax
	push ebx
	push ebx
	push ebx
	push ebx
	push ebx
	push ebx
	lea eax,[ebp-0x5C]
	push eax
	lea eax,[ebp-0x60]
	push eax
	ACALL(0x0048b297)
	or dword ptr [ebp-0x04],0xFFFFFFFF
	lea eax,[ebp-0x00000098]
	push eax
	ACALL(0x0044f532)
	pop ecx
	lea eax,[ebp-0x60]
	push eax
	mov ecx,edi
	call FlllMapAttackCall
	AJUMP(0x00798CD1)
SCRIPT_END

SCRIPT_START(FullMap_Bypass)
	mov ecx,[esi+0x000001B4]
	mov [ebp-0x04],0xF
	lea eax,[ebp-0x00000098]
	push eax
	push ebx
	push ebx
	push ebx
	push ebx
	push ebx
	push ebx
	lea eax,[ebp-0x5C]
	push eax
	lea eax,[ebp-0x60]
	push eax
	ACALL(0x0048B297)
	or dword ptr [ebp-0x04],0xFFFFFFFF
	lea eax,[ebp-0x00000098]
	push eax
	ACALL(0x0044F532)
	pop ecx
	lea eax,[ebp-0x60]
	push eax
	lea ecx,[esi+0x000007F4]
	ACALL(0x00764793)
	test eax,eax
	AJUMP(0x00798e9c)
SCRIPT_END
//---------------------------------------------------------------------------
/* 全圖吸物 */
int ItemVac_OnOff = 0;
DWORD PtInRect_Addr = (DWORD)GetProcAddress(GetModuleHandle(_T("User32.dll")), "PtInRect");
DWORD ItemVac_ICS_Addr = 0x01556A44;
DWORD ItemVac_ICS_Value = R(ItemVac_ICS_Addr);


SCRIPT_START(ItemVac_Entry)
	Cmp [ItemVac_OnOff],0
	Je Return
	Cmp [Esp],0x005B155B //85 C0 75 18 83 4D FC ** 8D 4D
	Je SetItemXY
	Cmp [Esp],0x005B0787 //85 C0 74 07 39 5D ** 75 DE
	Jne Return
	Mov [Esp],0x005B078B //39 5D ** 75 ** EB ** 6A ** 8B CF
	Return:
	Jmp PtInRect_Addr
	SetItemXY:
	Jmp ItemVac_Main
SCRIPT_END

SCRIPT_START(ItemVac_Main)
	Push Eax
	Mov Eax,[Esp+0x0C]
	Mov [Ebx],Eax
	Mov Eax,[Esp+0x10]
	Mov [Ebx+0x04],Eax
	Pop Eax
	Mov [Esp],0x005B1577 //33 C0 39 46 ** 75 0E FF 76
	Jmp PtInRect_Addr
SCRIPT_END
//---------------------------------------------------------------------------
/* 人物面向控制 */

int FaceLR_OnOff = 0;
int FaceLR_Value = 0;

DWORD FaceLR_ICS_Addr = 0x012B32AC;
DWORD FaceLR_ICS_Value = R(FaceLR_ICS_Addr);

DWORD FaceLR_Main_Addr = (DWORD)FaceLR_Main;

SCRIPT_START(FaceLR_Entry)
	Cmp [FaceLR_OnOff],0
	Je Return
	Cmp [Esp],0x00C544C6 //8B C8 E8 ** ** ** ** 85 C0 74 0D 8B
	Jne Return
	AMOVESP(0,FaceLR_Main_Addr)
	Return:
	AJUMP(FaceLR_ICS_Value)
SCRIPT_END

SCRIPT_START(FaceLR_Main)
	mov ecx,eax
	ACALL(0x00406426)
	test eax,eax
	Jne Label_Back
	mov eax,[FaceLR_Value]
	AJUMP(0x00C544E1)
	Label_Back:
	AJUMP(0x00C544D1)
SCRIPT_END

//---------------------------------------------------------------------------
/* 技能動畫消除 */

int NoSkillAni_OnOff = 0;

DWORD NoSkillAni_ICS_Addr = 0x012B32A8;
DWORD NoSkillAni_ICS_Value = R(NoSkillAni_ICS_Addr);

SCRIPT_START(NoSkillAni_Entry)
	Cmp [NoSkillAni_OnOff],0
	Je Return
	Cmp [Esp],0x00C76F5E //88 45 ** 8B 06 8B CE FF 50 68 [1/7]
	Jne Return
	Mov [Esp],0x00C7E371
	Return:
	AJUMP(NoSkillAni_ICS_Value)
SCRIPT_END
//---------------------------------------------------------------------------
/* 連跳不耗魔 */

int UltimateJmp_OnOff = 0;

DWORD UltimateJmp_ICS_Addr = 0x011DC238;
DWORD UltimateJmp_ICS_Value = R(UltimateJmp_ICS_Addr);

SCRIPT_START(UltimateJmp_Entry)
	Cmp [Esp+0x0C],0x00D1B175 // f6 80 f4 02 00 00 02 0f ? ? ? 00 00 ff 33
	Jne Return
	Mov Edi, [Ebp+0x08]
	Mov Ecx, [Edi]
	Mov [Esp+0x0C], 0x00D1B196  // mov ecx,esi
	Return:
	AJUMP(UltimateJmp_ICS_Value)
SCRIPT_END
//---------------------------------------------------------------------------
/* 走路加速 */

int WalkSpeedUp_OnOff = 0;
int WalkSpeedUp_Speed = 3;

DWORD WalkSpeedUp_FakeTime = 0;

DWORD WalkSpeedUp_ICS_Addr = 0x012B954C;
DWORD WalkSpeedUp_ICS_Value = R(WalkSpeedUp_ICS_Addr);

SCRIPT_START(WalkSpeedUp_Entry)
	cmp [WalkSpeedUp_OnOff],0
    Je Return
	cmp [esp],0x00D03328 //8B ** ** 00 00 00 8B 4D ** 83 C0 ** 89 45
	jne Return
	Add Esp,0x4
	Push Esi
	Mov Esi,[WalkSpeedUp_Speed]
	SpeedChk:
	test esi,esi
	je Normal
	dec esi
	Pushad
	Mov Ecx,[WalkSpeedUp_FakeTime]
	Mov Eax,[SystemTimeBase] //系統時間
	Lea Eax,[Eax+SystemTimeOffset]
	Add [Eax],Ecx
	Popad
	push esi
	push ecx
	push eax
	call dword ptr [eax]
	pop eax
	pop ecx
	pop esi
	Pushad
	Mov Ecx,[WalkSpeedUp_FakeTime]
	Mov Eax,[SystemTimeBase] //系統時間
	Lea Eax,[Eax+SystemTimeOffset]
	Sub [Eax],Ecx
	Add [WalkSpeedUp_FakeTime],0x000002FE
	Popad
	jmp SpeedChk
	Normal:
	pop esi
	AJUMP(0x00D03328) //8B ** ** 00 00 00 8B 4D ** 83 C0 ** 89 45 ** 8B 01
	Return:
	AJUMP(WalkSpeedUp_ICS_Value)
SCRIPT_END
//---------------------------------------------------------------------------
/* 物品過濾 */

DWORD __stdcall CheckItem(bool IsMoney, DWORD ItemID)
{

	return frmMain->CheckItem(IsMoney,ItemID);
}

DWORD ItemFilter_ICS_Addr = 0x01519184;
DWORD ItemFilter_ICS_Value = R(ItemFilter_ICS_Addr);

DWORD ItemFilter_Main_Addr = (DWORD)ItemFilter_Main;

SCRIPT_START(ItemFilter_Entry)
		Cmp [Esp+0x6C],0x005B537D //8B 45 ** 8B 75 ** 88
		Jne ICSBack
		Push [ItemFilter_Main_Addr]
		Pop [Esp+0x6C]
		ICSBack:
		AJUMP(0x008FB3D6)
SCRIPT_END

SCRIPT_START(ItemFilter_Main)
		mov eax,[ebp+0x44]
		mov esi,[ebp+0x38]
		mov [esi+0x20],al
		cmp eax,0x01
		DB 0x74, 0x09
		cmp eax,0x02
		DB 0x74, 0x04
		xor al,al
		DB 0xEB, 0x02
		mov al,0x01
		mov [esi+0x21],al
		mov [esi+0x24],edi
		mov edi,[ebp+0x7C]
		mov ecx,edi //楓幣
		ACALL(0x0040711e)
		movzx eax,al
		mov ecx,edi
		mov [esi+0x34],eax
		ACALL(0x004071d5)
		Pushad
		Cmp Eax, 0xC350
		Jg NotMoney
		Push Eax
		Push 01 //is money
		Call CheckItem
		Mov [Esi+0x34], Eax
		Mov [Esi+0x38], Eax
		Jmp Back

		NotMoney:
		Push Eax
		Push 00
		Call CheckItem
		Mov [Esi+0x38], Eax
		Jmp Back

		Back:
		Popad
		Mov Ecx, Edi
		AJUMP(0x005B53B8)
SCRIPT_END

//---------------------------------------------------------------------------

int AutoLR_OnOff = 0;
int AutoLR_Position = 0;
int AutoLR_Range = 30;
int AutoLR_Step = 0;
int AutoLR_WaitTime = 5000;
int AutoLR_NextTime = 0;
int AutoLR_Value = 0;

DWORD AutoLR_ICS_Addr = 0x01556aa0;
DWORD AutoLR_ICS_Value = R(AutoLR_ICS_Addr);
DWORD AutoLR_Main_Addr = (DWORD)AutoLR_Main;
DWORD GetFocus_Addr = (DWORD)GetProcAddress(GetModuleHandle(_T("user32.dll")), "GetFocus");
SCRIPT_START(AutoLR_GetX)
		Mov Eax,[MapBase]
		Mov Eax,[Eax+MapCharXOffset]
		Ret
SCRIPT_END

int __stdcall AutoLR_Distance( int x , int x2)
{
	return x>x2 ? x-x2+1: x2-x +1;
}

SCRIPT_START(AutoLR_Entry)
	Cmp   [AutoLR_OnOff], 0
	Je    AutoLR_Return
	Cmp   [Esp],0x00D92BE0
	Jne   AutoLR_Return
	Push  Eax
	AMOVESP(0,AutoLR_Main_Addr)
	AutoLR_Return:
	Push  [GetFocus_Addr]
	Ret
SCRIPT_END



SCRIPT_START(AutoLR_Main)

		Cmp   [AutoLR_OnOff], 0
		Je    AutoLR_Back
		Mov Eax, [Esp]
		Cmp [Eax], 0x850FC63B
		Jne AutoLR_Back
		Mov Eax, [MapBase]
		Test Eax, Eax
		Je AutoLR_Back

		Push  Eax
		Cmp   [AutoLR_Step],2
		Jle   Control_Stop
		Mov   Eax,[SystemTimeBase]
		Mov   Eax,[Eax+SystemTimeOffset]
		Sub   Eax,[AutoLR_WaitTime]
		Cmp   Eax,[AutoLR_NextTime]
		Jbe   AutoLR_GoStop
		Mov   Eax,[SystemTimeBase]
		Mov   Eax,[Eax+SystemTimeOffset]
		Add   Eax,[AutoLR_WaitTime]
		Mov   [AutoLR_NextTime],Eax
		//---------------------------------
		Control_LR:
		Cmp [AutoLR_Step],3
		Je  Control_Left
		Cmp [AutoLR_Step],4
		Je  Control_Right

		Control_Left:
		Mov [AutoLR_Step],1
		Jmp Control_Stop

		Control_Right:
		Mov [AutoLR_Step],2
		Jmp Control_Stop

		Control_Stop:
		Cmp [AutoLR_Step],1
		Je  AutoLR_Left
		Cmp [AutoLR_Step],2
		Je  AutoLR_Right
		Jmp AutoLR_GoStop

		AutoLR_Left:
		/*call AutoLR_GetX
		push eax
		push [AutoLR_Position]
		call AutoLR_Distance
		mov  [AutoLR_Value],eax   */
		INC [AutoLR_Value]
		Mov   Eax,[AutoLR_Range]
		Cmp   [AutoLR_Value],Eax
		Jle   AutoLR_GoLeft
		Mov   [AutoLR_Step],4
		Mov   [AutoLR_Value],0
		Jmp   AutoLR_GoRight

		AutoLR_Right:
		INC [AutoLR_Value]
		Mov   Eax,[AutoLR_Range]
		Cmp   [AutoLR_Value],Eax
		Jle   AutoLR_GoRight
		Mov   [AutoLR_Step],3
		Mov   [AutoLR_Value],0
		Jmp   AutoLR_GoLeft

		AutoLR_GoLeft:
		Mov   [Ebp-04], 0xFFFFFFFF
		Pop   Eax
		Jmp   AutoLR_Exit

		AutoLR_GoRight:
		Mov   [Ebp-04], 00000001
		Pop   Eax
		Jmp   AutoLR_Exit

		AutoLR_GoStop:
		Mov   [Ebp-04], 00000000
		Pop   Eax
		Jmp   AutoLR_Exit

		AutoLR_Exit:
		//AJUMP(0x00d92ffb) // 0x00982F3B
 		Mov Eax, [Esp]
		Add Eax, 0x4
		Mov Eax, [Eax]
		Add [Esp], Eax
		Add [Esp], 0x8
		Jmp AutoLR_Back

		AutoLR_Back:
		Push 00
		Push [GetFocus_Addr]
		Add [Esp], 2
		Ret
		//AJUMP(AutoLR_Main_Addr)// 0x00982C68

SCRIPT_END
//---------------------------------------------------------------------------
/* 全圖吸怪CS */
int CSMobVac_OnOff = 0;
DWORD CSMobVac_ICS_Addr = 0x012B8908;
DWORD CSMobVac_ICS_Value = R(CSMobVac_ICS_Addr);

SCRIPT_START(CSMobVac_Entry)
	Cmp [CSMobVac_OnOff],0
	Je Return
	Push Ebp
	Mov Ebp,Esp
	Push Ebx
	Push Esi
	Mov Esi,[Ebp+0x08]
	Xor Ebx,Ebx
	Push Edi
	cmp [esi+0x70],ebx
	jne Label1
	//8B 0D ** ** ** ** E8 ** ** ** ** 89 45 ** DB
	mov ecx,[0x015487d0]
	ACALL(0x00d85554)
	mov [ebp+0x08],eax
	fild dword ptr [ebp+0x08]
	mov edi,[ebp+0x0c]
	fdiv qword ptr [0x011c6bd0]
	fstp qword ptr [ebp+0x34]
	cmp edi,ebx
	je Label3
	fld qword ptr [esi+0x00000094]
	push ecx
	fsub qword ptr [esi+0x74]
	push ecx
	fmul qword ptr [ebp+0x34]
	fadd qword ptr [esi+0x74]
	fstp qword ptr [esp]
	ACALL(0x005afaaa)
	pop ecx
	pop ecx
	////////////////////////////

	Mov Eax, [PeopleBase] //CharBase
	Mov Eax, [AutoGuagi_X] //UberX
	mov [edi],eax
	mov edi,[ebp+0x10]
	cmp edi,ebx
	je Label2
	fld qword ptr [esi+0x0000009C]
	push ecx
	fsub qword ptr [esi+0x7C]
	push ecx
	fmul qword ptr [ebp+0x34]
	fadd qword ptr [esi+0x7C]
	fstp qword ptr [esp]
	ACALL(0x005afaaa);
	pop ecx
	pop ecx
	Mov Eax, [PeopleBase] //CharBase
	Mov Eax, [AutoGuagi_Y] //UberY
	AJUMP(0x00D8562C)
	Label1:
    AJUMP(0x00D855CC)
	Label2:
	AJUMP(0x00d8562e)
	Label3:
	AJUMP(0x00d8560a)
	Return:
	AJUMP(CSMobVac_ICS_Value)
SCRIPT_END

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

/*
SCRIPT_START()
SCRIPT_END
*/
void __stdcall InstallScript()
{
	FPHook(SuperMobStupid_ICS_Addr,SuperMobStupid_Entry);
	*(DWORD*)0x01519184 = (DWORD)ItemFilter_Entry;
	FPHook(CSMobVac_ICS_Addr,CSMobVac_Entry);
	FPHook(GetInfo_ICS_Addr,GetInfo_Entry);
	FPHook(GodMode_ICS_Addr,GodMode_Entry);
	AsmJump(GetFocus_Addr-5, AutoLR_Main, 0); //左右走
	WriteByte(GetFocus_Addr, 0xEB);
	WriteByte(GetFocus_Addr+1, 0xF9);

	FPHook(ItemVac_ICS_Addr,ItemVac_Entry);
	FPHook(FaceLR_ICS_Addr,FaceLR_Entry);
	FPHook(NoSkillAni_ICS_Addr,NoSkillAni_Entry);
	FPHook(UltimateJmp_ICS_Addr,UltimateJmp_Entry);
	FPHook(WalkSpeedUp_ICS_Addr,WalkSpeedUp_Entry);
	FPHook(FullMap_ICS_Addr,FullMap_Entry);

	FPHook(SuperDiagua_ICS_Addr,SuperDiagua_Entry);
	FPHook(CSX_ICS_Addr,CSX_Entry);
}

