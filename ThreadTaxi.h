//---------------------------------------------------------------------------

#ifndef ThreadTaxiH
#define ThreadTaxiH
#include <Classes.hpp>

#include <io.h>
//---------------------------------------------------------------------------
class TThreadTaxi : public TThread
{
public:
typedef long (*MLPROC)(int status, long current , long target);
enum  TaxiStatus  {
		TaxiStop,
		TaxiFirst,
		TaxiStart,
		TaxiEnd,
		TaxiError
	};
private:
	void __fastcall Start();
	MLPROC proc;
	bool isRunning ;
	long sMap;
	long eMap;
	void __fastcall SetXY( bool s ,int x, int y);
	void __fastcall TeleXY( bool s ,int x, int y);
	void __fastcall TaxiGo(long sMap , long eMap);
	void __fastcall TaxiControl( long* &tmp );
    TaxiStatus status;

protected:
	void __fastcall Execute();

public:

    void __fastcall Terminate();
    TaxiStatus  GetTaxiStatus();
	__fastcall TThreadTaxi(bool CreateSuspended ,long sMap , long eMap, MLPROC proc);

};
extern PACKAGE TThreadTaxi * ThreadTaxi;
#endif
