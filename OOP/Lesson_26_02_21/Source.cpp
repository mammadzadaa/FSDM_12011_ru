#include<iostream>
using namespace std;

//class Base
//{
//protected:
//	int a;
//public:
//	void setA(int num) { a = num; }
//	int getA() { return a; }
//};
//
//class Derived : public Base
//{
//private:
//public:
//	int a;
//	void set(int num) { a = num; }
//	int get() { return a; }
//	void foo()
//	{
//		Base::a = 20;
//	}
//};

//class G
//{
//public:
//	void  func()
//	{
//		cout << "Aloha\n";
//	}
//};
//
//class A : public G
//{
//public:
//	int a;
//	void foo()
//	{
//		cout << "Hi\n";
//	}
//};
//
//class B : public G
//{
//protected:
//	int num;
//public:
//	int b;
//	void foo()
//	{
//		cout << "Hello\n";
//	}
//};
//
//class C : public A, public B
//{
//public:
//	B::num;
//	int c;
//	void f()
//	{
//		A::foo();
//	}
//};

class Base
{
	int n;
public:
	Base() = default;
	Base(int num)
	{
		n = num;
		cout << "Base Ctor\n";
	}

	int get_num()
	{
		return n;
	}
};

class Derived : public Base
{
public:
	//Derived() : Base(0)
	//{
	//	cout << "Derived Ctor\n";
	//}
};

int main()
{
	Derived d;
	cout << d.get_num();


	//C n;
	//n.num = 1;
	
	/*Derived d;
	d.a = 10;
	d.foo();
	cout << d.getA() << endl << d.get() << endl;*/

	//d.setA(10);
	//d.set(20);
	//cout << d.get() << endl << d.getA() << endl;
	return 0;
}