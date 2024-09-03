#include<iostream>
using namespace std;

class OPP{
    protected:
	float marksOPP;
};

class DSU{
	protected:
    float marksDSU;
};

class DMS{
	protected:
    float marksDMS;
};

class DTE{
	protected:
    float marksDTE;
};

class CGR{
	protected:
	float marksCGR;
};

class EIC{
	protected:
    float marksEIC;
};

class CT : public OPP, public DSU, public DMS, public DTE, public CGR, public EIC {
    public:
	   CT(float opp, float dsu, float dms, float dte, float cgr, float eic)
	   {
 			marksOPP = opp;
   	        marksDSU = dsu;
   	        marksDMS = dms;
   	        marksDTE = dte;
   	        marksCGR = cgr;
   	        marksEIC = eic;
	   }
	   float average()
	   {
            return (marksOPP + marksDSU + marksDMS + marksDTE + marksCGR + marksEIC) / 6;
	   }
};

int main ()
{
	CT ct1(20, 22, 24, 26, 30, 30), ct2(26, 29, 20, 30, 30, 30);
	
	cout << "Average: " << endl;
	cout << "CT1: " << ct1.average() << endl;
	cout << "CT2: " << ct2.average() << endl;
	
	return 0;
}

