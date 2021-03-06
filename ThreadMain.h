//---------------------------------------------------------------------------

#ifndef ThreadMainH
#define ThreadMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <vcl.h>

//---------------------------------------------------------------------------
class ThreadMain : public TThread
{
private:
	void __fastcall RefreshData();
protected:
	void __fastcall Execute();
public:
	__fastcall ThreadMain(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
