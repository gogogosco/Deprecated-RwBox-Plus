//---------------------------------------------------------------------------

#ifndef FormMainH
#define FormMainH
//---------------------------------------------------------------------------
#include <fmx.h>
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Types.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Edit.hpp>
#include <FMX.ListBox.hpp>
#include "Keys.h"
#include <FMX.Layouts.hpp>
#include <inifiles.hpp>
#include <FMX.Platform.Win.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TStyleBook *style;
	TTabControl *TabControl1;
	TTabItem *TabItem1;
	TTabItem *TabItem2;
	TTabItem *TabItem3;
	TEdit *txt_autoguagi_y;
	TEdit *txt_autoguagi_x;
	TLabel *Label1;
	TGroupBox *GroupBox1;
	TButton *btn_vac_set;
	TLabel *Label2;
	TEdit *txt_autoguagi_mapid;
	TGroupBox *GroupBox2;
	TLabel *Label3;
	TCheckBox *ck_func_godmode;
	TCheckBox *ck_func_dingua;
	TCheckBox *ck_func_stupid;
	TCheckBox *ck_func_autolr;
	TCheckBox *ck_func_csx;
	TLabel *Label4;
	TCheckBox *ck_func_dingwei;
	TCheckBox *ck_func_hidebk;
	TCheckBox *ck_func_hideskill;
	TCheckBox *ck_func_jmp;
	TCheckBox *ck_func_hidedmg;
	TCheckBox *ck_func_itemvac;
	TCheckBox *ck_func_chardir;
	TSwitch *sw_func_chardir;
	TLabel *Label6;
	TLabel *Label7;
	TProgressBar *ExpBar;
	TLabel *lb_exp;
	TProgressBar *HPBar;
	TLabel *lb_hp;
	TProgressBar *MPBar;
	TLabel *lb_mp;
	TEdit *txt_hp;
	TEdit *txt_mp;
	TEdit *txt_att;
	TEdit *txt_key1;
	TEdit *txt_key2;
	TEdit *txt_key3;
	TEdit *txt_key4;
	TComboBox *cb_att;
	TComboBox *cb_key1;
	TComboBox *cb_key2;
	TComboBox *cb_key3;
	TComboBox *cb_key4;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TCheckBox *ck_att;
	TCheckBox *ck_key1;
	TCheckBox *ck_key2;
	TCheckBox *ck_key3;
	TCheckBox *ck_key4;
	TCheckBox *ck_mp;
	TCheckBox *ck_hp;
	TListBox *list_drop;
	TListBox *list_filter;
	TLabel *Label5;
	TLabel *Label8;
	TButton *儲存設定;
	TTimer *UI;
	TCheckBox *ck_pick;
	TComboBox *cb_pick;
	TEdit *txt_pick;
	TLabel *Label9;
	TLabel *lb_Guagi_onoff;
	TTimer *Load;
	TTimer *Ping;
	TLabel *Label10;
	TButton *btn_item_save;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ck_func_godmodeChange(TObject *Sender);
	void __fastcall ck_func_csxChange(TObject *Sender);
	void __fastcall ck_func_dinguaChange(TObject *Sender);
	void __fastcall ck_func_stupidChange(TObject *Sender);
	void __fastcall UITimer(TObject *Sender);
	void __fastcall txt_hpKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall txt_hpChange(TObject *Sender);
	void __fastcall txt_mpChange(TObject *Sender);
	void __fastcall txt_attChange(TObject *Sender);
	void __fastcall txt_pickChange(TObject *Sender);
	void __fastcall txt_key1Change(TObject *Sender);
	void __fastcall txt_key2Change(TObject *Sender);
	void __fastcall txt_key3Change(TObject *Sender);
	void __fastcall txt_key4Change(TObject *Sender);
	void __fastcall cb_attChange(TObject *Sender);
	void __fastcall cb_pickChange(TObject *Sender);
	void __fastcall cb_key1Change(TObject *Sender);
	void __fastcall cb_key2Change(TObject *Sender);
	void __fastcall cb_key3Change(TObject *Sender);
	void __fastcall cb_key4Change(TObject *Sender);
	void __fastcall ck_func_jmpChange(TObject *Sender);
	void __fastcall ck_func_hideskillChange(TObject *Sender);
	void __fastcall ck_func_chardirChange(TObject *Sender);
	void __fastcall sw_func_chardirClick(TObject *Sender);
	void __fastcall ck_func_itemvacChange(TObject *Sender);
	void __fastcall ck_hpChange(TObject *Sender);
	void __fastcall ck_mpChange(TObject *Sender);
	void __fastcall ck_attChange(TObject *Sender);
	void __fastcall ck_pickChange(TObject *Sender);
	void __fastcall ck_key1Change(TObject *Sender);
	void __fastcall ck_key2Change(TObject *Sender);
	void __fastcall ck_key3Change(TObject *Sender);
	void __fastcall ck_key4Change(TObject *Sender);
	void __fastcall list_dropDblClick(TObject *Sender);
	void __fastcall list_filterDblClick(TObject *Sender);
	void __fastcall ck_func_hidebkChange(TObject *Sender);
	void __fastcall btn_vac_setClick(TObject *Sender);
	void __fastcall ck_func_autolrChange(TObject *Sender);
	void __fastcall 儲存設定Click(TObject *Sender);
	void __fastcall LoadTimer(TObject *Sender);
	void __fastcall PingTimer(TObject *Sender);
	void __fastcall btn_item_saveClick(TObject *Sender);
private:	// User declarations
	void __fastcall LoadSetting();
	void __fastcall SaveSetting();


public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
	void __fastcall OpenTaxiWindow();
	void __fastcall WalkSpeedUpSwitch();
	unsigned int __fastcall CheckItem(bool isMoney , unsigned long id);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
