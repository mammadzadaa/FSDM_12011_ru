#include<iostream>
using namespace std;

class A
{
private:
	int a = 0;
	int b = 1;
};

class B
{
public:
	int f;
	int d;
	virtual ~B() {}
};

class C : public B
{
public:
	int k;
};

class D : public B
{
public:
	int z;
};

void foo(const int* const ptr)
{
	int* p = const_cast<int*>(ptr);
	*p = 10;
}

void foo1(int* ptr)
{
	const int* p = const_cast<const int*>(ptr);
	//*p = 10;
}

void foo2(B* ptr)
{
	auto c = dynamic_cast<C*>(ptr);
	if (c != nullptr)
	{
		cout << c->k << endl;
	}
	else
	{
		cout << "Can not cast!\n";
	}
}

int main()
{
	C* c = new C();
	c->k = 10;

	D* d = new D();
	d->z = 20;
	foo2(d);

	/*int num = 5;
	foo(&num);
	cout << num << endl;*/
	//double d = 232131.432434;
	//auto f = static_cast<char>(d);
	//char* p = &f;
	//int* ptr = reinterpret_cast<int*>(p);

	//B* bp = reinterpret_cast<B*>(new A());
	//cout << bp->d << endl << bp->f << endl;

	//cout << *ptr << endl;
	//cout << f << endl;

	//A a;
	////B b = (B)a;
	//B* i = (B*)new A();
	//cout << i->d << endl << i->f << endl;

	/*float f = 3.4;
	int num = f;
	cout << num << endl;

	char* ptr = (char*)&num;

	cout << *ptr << endl;*/

	return 0;
}