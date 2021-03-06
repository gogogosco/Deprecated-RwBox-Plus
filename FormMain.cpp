//---------------------------------------------------------------------------


#pragma hdrstop
#include "Script.h"
#include "Variable.h"
#include "FormTaxi.h"
#include "FormMain.h"
#include "ItemList.h"
#include "windows.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfrmMain *frmMain;
TIniFile* itemINI;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TfrmMain::LoadSetting()
{
	if (strcmp(LoginerPath,"")!=0) {
		if( FileExists(  String(LoginerPath) +"\\Data\\"+ GameAccount + "\\Setting.ini" ))
		{
			TIniFile* ini = new TIniFile( String(LoginerPath) +"\\Data\\"+ GameAccount + "\\Setting.ini");

			AutoGuagi_X = ini->ReadInteger("AutoGuagi","X",0);
			AutoGuagi_Y = ini->ReadInteger("AutoGuagi","Y",0);
			AutoGuagi_MapId = ini->ReadInteger("AutoGuagi","MapId",0);

			this->ck_func_godmode->IsChecked = ini->ReadBool("Setting","godmode",true);
			this->ck_func_dingua->IsChecked=ini->ReadBool("Setting","dingua",this->ck_func_dingua->IsChecked);
			ck_func_csx->IsChecked =ini->ReadBool("Setting","csx",this->ck_func_csx->IsChecked);
			//ck_func_autolr->IsChecked =ini->ReadBool("Setting","autolr",this->ck_func_autolr->IsChecked);
			this->ck_func_chardir->IsChecked =ini->ReadBool("Setting","chardir",this->ck_func_chardir->IsChecked);
		    this->sw_func_chardir->IsChecked  =ini->ReadBool("Setting","chardir_v",this->sw_func_chardir->IsChecked);
			this->ck_func_dingwei->IsChecked =ini->ReadBool("Setting","dingwei",this->ck_func_dingwei->IsChecked);
			this->ck_func_hidebk->IsChecked =ini->ReadBool("Setting","hidebk",this->ck_func_hidebk->IsChecked);
			this->ck_func_hidedmg->IsChecked =ini->ReadBool("Setting","hidedmg",this->ck_func_hidedmg->IsChecked);
			this->ck_func_hideskill->IsChecked =ini->ReadBool("Setting","hideskill",this->ck_func_hideskill->IsChecked);
			this->ck_func_itemvac->IsChecked =ini->ReadBool("Setting","itemvac",this->ck_func_itemvac->IsChecked);
			this->ck_func_jmp->IsChecked =ini->ReadBool("Setting","jmp",this->ck_func_jmp->IsChecked);
			this->ck_func_stupid->IsChecked =ini->ReadBool("Setting","stupid",this->ck_func_stupid->IsChecked);
			this->ck_hp->IsChecked =ini->ReadBool("Protect","hp",this->ck_hp->IsChecked);
			this->ck_mp->IsChecked =ini->ReadBool("Protect","mp",this->ck_mp->IsChecked);
			this->ck_att->IsChecked =ini->ReadBool("Protect","att",this->ck_att->IsChecked);
		    this->ck_pick->IsChecked =ini->ReadBool("Protect","pick",this->ck_pick->IsChecked);
			this->ck_key1->IsChecked =ini->ReadBool("Protect","key1",this->ck_key1->IsChecked);
			this->ck_key2->IsChecked =ini->ReadBool("Protect","key2",this->ck_key2->IsChecked);
			this->ck_key3->IsChecked =ini->ReadBool("Protect","key3",this->ck_key3->IsChecked);
			this->ck_key4->IsChecked =ini->ReadBool("Protect","key4",this->ck_key4->IsChecked);
			this->txt_hp->Text =ini->ReadString("Protect","hp_v",this->txt_hp->Text);
		    this->txt_mp->Text =ini->ReadString("Protect","mp_v",this->txt_mp->Text);
			this->txt_att->Text =ini->ReadString("Protect","att_v",this->txt_att->Text);
			this->txt_pick->Text =ini->ReadString("Protect","pick_v",this->txt_pick->Text);
		    this->txt_key1->Text =ini->ReadString("Protect","key1_v",this->txt_key1->Text);
			this->txt_key2->Text =ini->ReadString("Protect","key2_v",this->txt_key2->Text);
			this->txt_key3->Text =ini->ReadString("Protect","key4_v",this->txt_key3->Text);
			this->txt_key4->Text =ini->ReadString("Protect","key3_v",this->txt_key4->Text);
			this->cb_att->Selected->Text =ini->ReadString("Protect","att_k",this->cb_att->Selected->Text);
			this->cb_att->ItemIndex = ini->ReadInteger("Protect","att_k",this->cb_att->ItemIndex);
			this->cb_pick->ItemIndex = ini->ReadInteger("Protect","pick_k",this->cb_pick->ItemIndex);
			this->cb_key1->ItemIndex=ini->ReadInteger("Protect","key1_k",this->cb_key1->ItemIndex);
			this->cb_key2->ItemIndex= ini->ReadInteger("Protect","key2_k",this->cb_key2->ItemIndex);
			this->cb_key3->ItemIndex=ini->ReadInteger("Protect","key4_k",this->cb_key3->ItemIndex);
			this->cb_key4->ItemIndex=ini->ReadInteger("Protect","key3_k",this->cb_key4->ItemIndex);
			AutoKey_HP_Value = StrToInt(txt_hp->Text);
			AutoKey_MP_Value = StrToInt(txt_mp->Text);
			AutoKey_Att_Time = StrToInt(txt_att->Text);
			AutoKey_Pick_Time = StrToInt(txt_pick->Text);
			AutoKey_Skill_Time[0] = StrToInt(txt_key1->Text);
			AutoKey_Skill_Time[1] = StrToInt(txt_key2->Text);
			AutoKey_Skill_Time[2] = StrToInt(txt_key3->Text);
			AutoKey_Skill_Time[3] = StrToInt(txt_key4->Text);
			AutoKey_Att_Key = GetVirtualKeyCodeByName(AnsiString(cb_att->Selected->Text).c_str());
			AutoKey_Pick_Key = GetVirtualKeyCodeByName(AnsiString(cb_pick->Selected->Text).c_str());
			AutoKey_Skill_Key[0] = GetVirtualKeyCodeByName(AnsiString(cb_key1->Selected->Text).c_str());
			AutoKey_Skill_Key[1] = GetVirtualKeyCodeByName(AnsiString(cb_key2->Selected->Text).c_str());
			AutoKey_Skill_Key[2] = GetVirtualKeyCodeByName(AnsiString(cb_key3->Selected->Text).c_str());
			AutoKey_Skill_Key[3] = GetVirtualKeyCodeByName(AnsiString(cb_key4->Selected->Text).c_str());







		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
	cb_key1->Items->AddStrings(Keys);
	cb_key2->Items->AddStrings(Keys);
	cb_key3->Items->AddStrings(Keys);
	cb_key4->Items->AddStrings(Keys);
	cb_pick->Items->AddStrings(Keys);
    cb_att->Items->AddStrings(Keys);
	cb_key1->ItemIndex = 0;
	cb_key1->ItemIndex = 1;
	cb_key1->ItemIndex = 2;
	cb_key1->ItemIndex = 3;
	cb_pick->ItemIndex = 4;
	cb_att->ItemIndex = 5;
	UI->Enabled = true;
	SendMessage(FmxHandleToHWND(this->Handle), WM_SETICON, ICON_BIG, (LPARAM) hIcon1);
	SendMessage(FmxHandleToHWND(this->Handle), WM_SETICON, ICON_SMALL, (LPARAM) hIcon1);
	SendMessage(FmxHandleToHWND(this->Handle), WM_SETICON, ICON_SMALL2, (LPARAM) hIcon1);
	this->Caption = String("RwBox ++ - ") +  GameAccount;

	if( !DirectoryExists( String(LoginerPath) + "\\Data\\" + GameAccount))
	{
		CreateDir(String(LoginerPath) + "\\Data\\");
		CreateDir(String(LoginerPath) + "\\Data\\" + GameAccount + "\\");
	}
		Load->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	TerminateProcess(GetCurrentProcess(),0);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::OpenTaxiWindow()
{

	if( frmTaxi != NULL)
	{
		frmTaxi->Close();
		delete frmTaxi;
	}
	frmTaxi = new TfrmTaxi(this);
    frmTaxi->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_func_godmodeChange(TObject *Sender)
{
	GodMode_OnOff = ck_func_godmode->IsChecked;
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_func_csxChange(TObject *Sender)
{
	CSX_OnOff = ck_func_csx->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_func_dinguaChange(TObject *Sender)
{
	SuperDiagua_OnOff = ck_func_dingua->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_func_stupidChange(TObject *Sender)
{
	SuperMobStupid_OnOff = ck_func_stupid->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::UITimer(TObject *Sender)
{
	lb_hp->Text = IntToStr(HP_Now) + "/" + IntToStr(HP_Max);
	lb_mp->Text = IntToStr(MP_Now) + "/" + IntToStr(MP_Max);
	lb_exp->Text = IntToStr(EXP_Now) + "/" + IntToStr(EXP_Max);
	HPBar->Max = HP_Max;
	MPBar->Max = MP_Max;
	ExpBar->Max = EXP_Max;
	HPBar->Value = HP_Now;
	MPBar->Value = MP_Now;
	ExpBar->Value = EXP_Now;
	lb_Guagi_onoff->Text = AutoGuagi_OnOff == 0 ? "OFF" : "ON";
	txt_autoguagi_x->Text = IntToStr(AutoGuagi_X);
	txt_autoguagi_y->Text = IntToStr(AutoGuagi_Y);
	txt_autoguagi_mapid->Text = IntToStr(AutoGuagi_MapId);

}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::txt_hpKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if(!(((Key >= '0') && (Key <= '9')) || (Key == VK_BACK) || (Key   == VK_DELETE) || (Key == VK_LEFT)|| (Key == VK_RIGHT) ))
    {
      Key = 0;
	}
}
//---------------------------------------------------------------------------
unsigned int __fastcall TfrmMain::CheckItem(bool isMoney ,unsigned long ItemID)
{
		if( isMoney )
		{
            return ItemID;
        }
		if (list_filter->Items->IndexOfObject((TObject *)ItemID) > -1)
		{
			return 0; // 物品在過濾清單
		}
		else if (list_drop->Items->IndexOfObject((TObject *)ItemID) > -1)
		{
			return ItemID; // 物品在掉落清單
		}
		else // 物品不在掉落清單
		{
			String name = String(GetItemName(ItemID));
			if (name.IsEmpty())
			{
				name.sprintf(TEXT(L"未知物品(編號:%d)"), ItemID);
			}
			list_drop->Items->AddObject(name, (TObject *)ItemID);
			return ItemID;
		}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::txt_hpChange(TObject *Sender)
{
	AutoKey_HP_Value = StrToInt(txt_hp->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::txt_mpChange(TObject *Sender)
{
	AutoKey_MP_Value = StrToInt(txt_mp->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::txt_attChange(TObject *Sender)
{
	AutoKey_Att_Time = StrToInt(txt_att->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::txt_pickChange(TObject *Sender)
{
	AutoKey_Pick_Time = StrToInt(txt_pick->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::txt_key1Change(TObject *Sender)
{
	AutoKey_Skill_Time[0] = StrToInt(txt_key1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::txt_key2Change(TObject *Sender)
{
	AutoKey_Skill_Time[1] = StrToInt(txt_key2->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::txt_key3Change(TObject *Sender)
{
	AutoKey_Skill_Time[2] = StrToInt(txt_key3->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::txt_key4Change(TObject *Sender)
{
	AutoKey_Skill_Time[3] = StrToInt(txt_key4->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::cb_attChange(TObject *Sender)
{
	AutoKey_Att_Key = GetVirtualKeyCodeByName(AnsiString(cb_att->Selected->Text).c_str());
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::cb_pickChange(TObject *Sender)
{
	AutoKey_Pick_Key = GetVirtualKeyCodeByName(AnsiString(cb_pick->Selected->Text).c_str());
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::cb_key1Change(TObject *Sender)
{
	AutoKey_Skill_Key[0] = GetVirtualKeyCodeByName(AnsiString(cb_key1->Selected->Text).c_str());
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::cb_key2Change(TObject *Sender)
{
	AutoKey_Skill_Key[1] = GetVirtualKeyCodeByName(AnsiString(cb_key2->Selected->Text).c_str());
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::cb_key3Change(TObject *Sender)
{
	AutoKey_Skill_Key[2] = GetVirtualKeyCodeByName(AnsiString(cb_key3->Selected->Text).c_str());
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::cb_key4Change(TObject *Sender)
{
	AutoKey_Skill_Key[3] = GetVirtualKeyCodeByName(AnsiString(cb_key4->Selected->Text).c_str());
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_func_jmpChange(TObject *Sender)
{
	UltimateJmp_OnOff = ck_func_jmp->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_func_hideskillChange(TObject *Sender)
{
	NoSkillAni_OnOff = ck_func_hideskill->IsChecked;

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_func_chardirChange(TObject *Sender)
{
	FaceLR_OnOff = ck_func_chardir->IsChecked;
    sw_func_chardir->Enabled = ck_func_chardir->IsChecked;
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::sw_func_chardirClick(TObject *Sender)
{
	FaceLR_Value = (!sw_func_chardir->IsChecked)*(-1);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_func_itemvacChange(TObject *Sender)
{
	ItemVac_OnOff = ck_func_itemvac->IsChecked;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::WalkSpeedUpSwitch()
{
	WalkSpeedUp_OnOff = !WalkSpeedUp_OnOff;
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::ck_hpChange(TObject *Sender)
{
	AutoKey_HP_OnOff = ck_hp->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_mpChange(TObject *Sender)
{
	AutoKey_MP_OnOff = ck_mp->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_attChange(TObject *Sender)
{
	AutoKey_Att_OnOff = ck_att->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_pickChange(TObject *Sender)
{
	AutoKey_Pick_OnOff = ck_pick->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_key1Change(TObject *Sender)
{
	AutoKey_Skill_OnOff[0] = ck_key1->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_key2Change(TObject *Sender)
{
	AutoKey_Skill_OnOff[1] = ck_key2->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_key3Change(TObject *Sender)
{
	AutoKey_Skill_OnOff[2] = ck_key3->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_key4Change(TObject *Sender)
{
	AutoKey_Skill_OnOff[3] = ck_key4->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::list_dropDblClick(TObject *Sender)
{
 	int index = list_drop->ItemIndex;
	if (index > -1)
	{
		list_filter->Items->AddObject(list_drop->Items->Strings[index],list_drop->Items->Objects[index]);
		list_drop->Items->Delete(index);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::list_filterDblClick(TObject *Sender)
{
	if (list_filter->ItemIndex > -1)
	{
		list_filter->Items->Delete(list_filter->ItemIndex);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_func_hidebkChange(TObject *Sender)
{
	NoBkImg_OnOff = ck_func_hidebk->IsChecked;

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btn_vac_setClick(TObject *Sender)
{
	if( AutoGuagi_OnOff == false )
	{
		AutoGuagi_X = ReadPointer(PeopleBase,PeopleUberX);
		AutoGuagi_Y = ReadPointer(PeopleBase,PeopleUberY);
		AutoGuagi_MapId = ReadPointer(MapBase,MapIDOffset);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ck_func_autolrChange(TObject *Sender)
{
	AutoLR_Step = 1;
	AutoLR_Value = AutoLR_Range /2;
	AutoLR_Position = ReadPointer(PeopleBase,PeopleUberX);
	AutoLR_OnOff = ck_func_autolr->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::儲存設定Click(TObject *Sender)
{
	this->SaveSetting();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::SaveSetting()
{
	TIniFile* ini = new TIniFile( String(LoginerPath) +"\\Data\\"+ GameAccount + "\\Setting.ini");
	ini->WriteInteger("AutoGuagi","X",AutoGuagi_X);
	ini->WriteInteger("AutoGuagi","Y",AutoGuagi_Y);
	ini->WriteInteger("AutoGuagi","MapId",AutoGuagi_MapId);

	ini->WriteBool("Setting","godmode",this->ck_func_godmode->IsChecked);
	ini->WriteBool("Setting","dingua",this->ck_func_dingua->IsChecked);
	ini->WriteBool("Setting","csx",this->ck_func_csx->IsChecked);
	ini->WriteBool("Setting","autolr",this->ck_func_autolr->IsChecked);
	ini->WriteBool("Setting","chardir",this->ck_func_chardir->IsChecked);
	ini->WriteBool("Setting","chardir_v",this->sw_func_chardir->IsChecked);
	ini->WriteBool("Setting","dingwei",this->ck_func_dingwei->IsChecked);
	ini->WriteBool("Setting","hidebk",this->ck_func_hidebk->IsChecked);
	ini->WriteBool("Setting","hidedmg",this->ck_func_hidedmg->IsChecked);
	ini->WriteBool("Setting","hideskill",this->ck_func_hideskill->IsChecked);
	ini->WriteBool("Setting","itemvac",this->ck_func_itemvac->IsChecked);
	ini->WriteBool("Setting","jmp",this->ck_func_jmp->IsChecked);
	ini->WriteBool("Setting","stupid",this->ck_func_stupid->IsChecked);
	ini->WriteBool("Protect","hp",this->ck_hp->IsChecked);
	ini->WriteBool("Protect","mp",this->ck_mp->IsChecked);
	ini->WriteBool("Protect","att",this->ck_att->IsChecked);
	ini->WriteBool("Protect","pick",this->ck_pick->IsChecked);
	ini->WriteBool("Protect","key1",this->ck_key1->IsChecked);
	ini->WriteBool("Protect","key2",this->ck_key2->IsChecked);
	ini->WriteBool("Protect","key3",this->ck_key3->IsChecked);
	ini->WriteBool("Protect","key4",this->ck_key4->IsChecked);
	ini->WriteString("Protect","hp_v",this->txt_hp->Text);
	ini->WriteString("Protect","mp_v",this->txt_mp->Text);
	ini->WriteString("Protect","att_v",this->txt_att->Text);
	ini->WriteString("Protect","pick_v",this->txt_pick->Text);
	ini->WriteString("Protect","key1_v",this->txt_key1->Text);
	ini->WriteString("Protect","key2_v",this->txt_key2->Text);
	ini->WriteString("Protect","key4_v",this->txt_key3->Text);
	ini->WriteString("Protect","key3_v",this->txt_key4->Text);
	ini->WriteInteger("Protect","att_k",this->cb_att->ItemIndex);
	ini->WriteInteger("Protect","pick_k",this->cb_pick->ItemIndex);
	ini->WriteInteger("Protect","key1_k",this->cb_key1->ItemIndex);
	ini->WriteInteger("Protect","key2_k",this->cb_key2->ItemIndex);
	ini->WriteInteger("Protect","key4_k",this->cb_key3->ItemIndex);
	ini->WriteInteger("Protect","key3_k",this->cb_key4->ItemIndex);



}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::LoadTimer(TObject *Sender)
{
	LoadSetting();
	if (FileExists(String(LoginerPath) +"\\Data\\"+ GameAccount + "\\Items.dat"))
	{
		TStringList *list = new TStringList();
		list->LoadFromFile(String(LoginerPath) +"\\Data\\"+ GameAccount + "\\Items.dat");
		for (int i = 0; i < list->Count; i++)
		{
			unsigned int ItemID;
			ItemID = _wtoi(list->Strings[i].w_str());
			AnsiString name = String(GetItemName(ItemID));
			if (name.IsEmpty())
			{
				name.sprintf(TEXT("未知物品(編號:%d)"), ItemID);
			}
			int index = list_drop->Items->IndexOfObject((TObject *)ItemID);
			if (index > -1)
				list_drop->Items->Delete(index);
			index = list_filter->Items->IndexOfObject((TObject *)ItemID);
			if (index < 0)
				list_filter->Items->AddObject(name, (TObject *)ItemID);
		}

		delete list;
	}
	Load->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::PingTimer(TObject *Sender)
{
	PostMessage(hWndLoginer,WM_PING,GetCurrentProcessId(),4);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btn_item_saveClick(TObject *Sender)
{
	TStringList *list = new TStringList();
	for (int i = 0; i < list_filter->Count; i++)
	{
		list->Add((int)list_filter->Items->Objects[i]);
	}
	list->SaveToFile(String(LoginerPath) +"\\Data\\"+ GameAccount + "\\Items.dat");
	delete list;
}
//---------------------------------------------------------------------------

