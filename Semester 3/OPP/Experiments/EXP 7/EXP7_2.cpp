#include <iostream>
using namespace std;

class Test1 {
	public:
		int marksOPP;
		int marksDSU;
		int marksDTE;
		int marksDMS;
		int total;
	
	public:
		void setData(int OPP, int DSU, int DTE, int DMS)
		{
			marksDMS = DMS;
			marksDSU = DSU;
			marksDTE = DTE;
			marksOPP = OPP;
		}
		friend int test1Total(Test1);
};

int test1Total(Test1 t)
{
	t.total = t.marksOPP + t.marksDSU + t.marksDTE + t.marksDMS;
	return t.total;
}

class Test2 {
	public:
		int marksOPP;
		int marksDSU;
		int marksDTE;
		int marksDMS;
		int total;
	
	public:
		void setData(int OPP, int DSU, int DTE, int DMS)
		{
			marksDMS = DMS;
			marksDSU = DSU;
			marksDTE = DTE;
			marksOPP = OPP;
		}
		friend int test2Total(Test1);
};

int test2Total(Test2 t)
{
	t.total = t.marksOPP + t.marksDSU + t.marksDTE + t.marksDMS;
	return t.total;
}



int main ()
{
	Test1 t1;
	Test2 t2;
	int average;
	
	t1.setData(60, 30, 90, 80);
	t2.setData(70, 60, 50, 70);
	
	average = (test1Total(t1) + test2Total(t2))/2;
	cout << "Average = " << average;
	
	return 0;
}
