#include<iostream>
#include "Empoyer.h"
using namespace std;

class MyClass
{
private:
	int a = 0;
	int b = 0;
public:
	void setA(int val) { a = val; }
	int getA() { return a; }

	void setB(int val) { b = val; }
	int getB() { return b; }


public:

	// MyClass() = default;

	MyClass()
	{
		a = 5;
		b = 10;
		cout << "Parametrless Cotr was called!\n";
	}

	MyClass(int a_val, int b_val)
	{
		a = a_val;
		b = b_val;
		cout << "Cotr with parametrs\n";
	}


	MyClass(int a_val) : MyClass(a_val,0) 
	{
		cout << "Cotr wich delegates its job\n";
	}

	//~MyClass()
	//{

	//}

};

int main()
{

	Empoyer e;


	MyClass entity;
	cout << entity.getA() << "   " << entity.getB() << endl << endl;

	MyClass another_entity(1, 2);
	cout << another_entity.getA() << "   " << another_entity.getB() << endl << endl;

	MyClass other_entity(7);
	cout << other_entity.getA() << "   " << other_entity.getB() << endl;
	
}

