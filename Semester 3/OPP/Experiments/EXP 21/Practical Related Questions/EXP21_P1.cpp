#include <iostream>
using namespace std;

class parent {
	public:
		int a;
		int b;
		
		virtual void read(){
			cout<<"A: ";
			cin >>a;
			cout<<"B: ";
			cin >>b;
		}
		 
		virtual void display(){
			cout<<"A: "<<a<<endl;
			cout<<"B: "<<b<<endl;
		}
};
class base: public parent {
	public:
		int c;
		int d;
		
		void read()
		{
			cout<<"A: ";
			cin >>a;
			cout<<"B: ";
			cin >>b;
			cout<<"C: ";
			cin >>c;
			cout<<"D: ";
			cin >>d;	
		}
		void display(){
			cout<<"A: "<<a<<endl;
			cout<<"B: "<<b<<endl;
			cout<<"C: "<<c<<endl;
			cout<<"D: "<<d<<endl;
		}
};

int  main(){
	base animal;
	parent fish;
	
	cout << endl << "Enter Animal: " << endl;
	animal.read();
	
	cout << endl << "Enter Fish: " << endl;
	fish.read();
	
	cout << endl << "Animal: " << endl;
	animal.display();
	
	cout << endl << "Fish: "  << endl;
	fish.display();
	
	return 0;
}
