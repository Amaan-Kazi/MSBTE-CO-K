#include <iostream>
using namespace std;

class A {
	public:
	int x;
	virtual void test() = 0;
};

class B: public A {
	public:
	int y;
};

class C: public B {
	public:
	int z;
	
	C (int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	void test() {
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		cout << "z: " << z << endl;
	}
};

int main ()
{
	C c1(10, 20, 30);
	A *ptr;
	
	ptr = &c1;
	ptr->test();
	
	return 0;
}
