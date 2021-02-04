#include <iostream>
#include <assert.h>
using namespace std;


class MyClass
{
private:
	int a = 1, b = 2, c = 3;
public:
	int e, f, g;
	static int num;
	MyClass() = default;
	explicit MyClass(int num)
	{
		cout << "Ctor been called\n";
	}

	void foo() const 
	{
		cout << "With Const\n";
		// e++; // wont change any field
		cout << a << " " << b << " " << c << endl;
	}

	void foo()
	{
		cout << "WithOut Const\n";
		// e++; // wont change any field
		cout << a << " " << b << " " << c << endl;
	}

	//MyClass(const MyClass& other) = delete;
};

int MyClass::num = 255;

void foo(const MyClass my)
{
	cout << "Function!\n";
	my.foo();
}

class String
{
private:
	char* str;
public:
	String() : String("") {}

	String(const char* val) 
	{
		str = _strdup(val);
	}

	String(const String& other)
	{
		delete[] this->str;
		this->str = _strdup(other.str);
	}

	~String()
	{
		delete[] str;
	}

	static String StringCancat(const String &a, const String &b)
	{
		char* temp = new char[a.GetLengh() + b.GetLengh() + 1]();
		strcpy_s(temp, (rsize_t)(a.GetLengh() + 1) , a.str);
		strcpy_s(temp + a.GetLengh(), (rsize_t)(b.GetLengh() + 1), b.str);
		return String(temp);
	}

	void SetString(const char* val)
	{
		assert(val != nullptr && "Can't sent null to SetString!\n");
		delete[] str;
		str = _strdup(val);
	}
	char* GetString()
	{
		return str;
	}
	size_t GetLengh()
	{
		return strlen(str);
	}
	size_t GetLengh() const
	{
		return strlen(str);
	}

};



int main()
{
	String a("a");
	String b("b");

	cout << String::StringCancat(a, b).GetString() << endl;

	//const MyClass my;
	//foo(my);


	//MyClass my = 10;
	////MyClass my(10);

	//foo(20);
	////foo(MyClass(20));

	//MyClass my;
	//my.e = 4;
	//my.f = 5;
	//my.g = 6;

	//MyClass* my1 = (MyClass*)malloc(sizeof(MyClass));

	//my1->e = 5;
	//my1->f = 10;
	//

	//cout << my1->e << " " << my1->f << " " << my1->g;

	//my1.e = 14;
	//my1.f = 15;
	//my1.g = 16;
}

