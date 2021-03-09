#include<iostream>
using namespace std;

class DerivedEx : public exception
{
public:
	DerivedEx(const char* str) : exception(str)
	{
		cout << "Ctor of DerivedEx\n";
	}
	const char* what() const override
	{
		return "Derived\n";
	}
};

int main()
{
	try
	{
		throw exception("Hello");
	}
	catch (const DerivedEx& ex)
	{
		cout << ex.what() << endl;
	}
	cin.get();
	return 0;
}