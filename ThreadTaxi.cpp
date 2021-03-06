//---------------------------------------------------------------------------

#pragma hdrstop
#include "Map.h";
#include "ThreadTaxi.h"
#include "Pointer.h"
#include "Function.h"
#include "WindowHook.h"
//---------------------------------------------------------------------------
TThreadTaxi* ThreadTaxi ;
__fastcall TThreadTaxi::TThreadTaxi(bool CreateSuspended ,long sMap,long eMap , MLPROC proc)
	: TThread(CreateSuspended)
{
	this->proc = proc;
	isRunning = true;
	this->sMap = sMap;
	this->eMap = eMap;
}
void __fastcall TThreadTaxi::Start()
{

}


void __fastcall TThreadTaxi::TaxiGo(long sMap , long eMap)
{
	this->sMap = sMap;
	this->eMap = eMap;
	status = TaxiStart;  

}

TThreadTaxi::TaxiStatus TThreadTaxi::GetTaxiStatus()
{
	return this->status;

}
void __fastcall TThreadTaxi::TaxiControl( long* & tmp)
{

	long cmap = ReadPointer(MapBase,MapIDOffset);
	long hp;
	POINT pt;
	if( (*tmp) == sMap) // FirstTime
	{
		GetTeleportPoint(*tmp,*(tmp+1),pt);
		proc(1,*tmp,*(tmp+1));
		TeleXY(true,pt.x,pt.y-5);
		tmp++;
		GetTeleportPoint(*tmp,*(tmp+1),pt);
		SetXY(true,pt.x,pt.y);
		Sleep(200);
		SendKey(hWndMS, VK_UP);
		while( *(DWORD*)PeopleBase != 0 && this->isRunning)
		{
			SetXY(true,pt.x,pt.y);
			SendKey(hWndMS, VK_UP);
			Sleep(100);
		}
		if(! this->isRunning)
			return;
		while( *(DWORD*)PeopleBase == 0 && this->isRunning)
			Sleep(100);
		if(! this->isRunning)
			return;
		if(*tmp != eMap)
			tmp++;
		Sleep(500);
	}
	else
	{

			GetTeleportPoint(*tmp,*(tmp+1),pt);
			proc(1,*tmp,*(tmp+1));
			SetXY(true,pt.x,pt.y);
			Sleep(200);
			while( *(DWORD*)PeopleBase == 0 && this->isRunning)
				Sleep(100);
			if( cmap != *(tmp-1))
			{
				delete tmp;
				sMap = cmap;
				tmp = SearchMapPath(sMap, eMap);
				Sleep(100);
				return;
			}
			SendKey(hWndMS, VK_UP);
			SetXY(true,pt.x,pt.y);
			Sleep(200);
			while( *(DWORD*)PeopleBase != 0 && this->isRunning)
			{
				SetXY(true,pt.x,pt.y);
				SendKey(hWndMS, VK_UP);
				Sleep(100);
			}

			if(! this->isRunning)
				return;
			while( *(DWORD*)PeopleBase == 0 && this->isRunning)
				Sleep(100);
			if(! this->isRunning)
				return;
			if(*tmp != eMap)
				tmp++;
			Sleep(500);

	}
}

void __fastcall TThreadTaxi::Execute()
{
	proc(0,0,0);
	long *path = SearchMapPath(sMap, eMap);
	long *tmp = path;
	POINT pt;
	String name;

	status = TaxiStart;
	if( *tmp != eMap )
	{
		while( *tmp != eMap && (status != TaxiStop && status != TaxiError ) && this->isRunning)
		{
			TaxiControl(tmp);
		}
        long cmap = ReadPointer(MapBase,MapIDOffset);
		if( *tmp == eMap && cmap != eMap  )
		{
			Sleep(700);
			SendKey(hWndMS, VK_UP);
			while( *(DWORD*)PeopleBase != 0 && this->isRunning)
				Sleep(100);
			while( *(DWORD*)PeopleBase == 0 && this->isRunning)
				Sleep(100);
		}
	}
	long cmap = ReadPointer(MapBase,MapIDOffset);
	if( cmap != eMap){
		proc(-2,0,0);
	}
	Terminate();
}

void __fastcall TThreadTaxi::Terminate()
{
	proc(-1,0,0);
	this->isRunning = false;
}
void __fastcall TThreadTaxi::SetXY( bool s , int x, int y)
{
	WritePointer(SystemBase,SpawnSwitchOffset,s);
	WritePointer(SystemBase,SpawnXOffset,x);
	WritePointer(SystemBase,SpawnYOffset,y);
}
void __fastcall TThreadTaxi::TeleXY( bool s , int x, int y)
{
	WritePointer(PeopleBase,PeopleTeleX,x);
	WritePointer(PeopleBase,PeopleTeleY,y);
	WritePointer(PeopleBase,PeopleTeleSW,s);
}
#pragma package(smart_init)

