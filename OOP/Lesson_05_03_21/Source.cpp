#include<iostream>
using namespace std;

//namespace Aftandil
//{
//	class A : Israfil::B
//	{
//
//	};
//	namespace Israfil
//	{
//		class B
//		{
//
//		};
//		int abs(int X)
//		{
//			std::cout << "wohoo!\n";
//			return 0;
//		}
//	}
//}


class MyException : public exception
{
public:
	MyException(const char* const message) : exception(message) {}
	const char* what() const override
	{
		char* message = new char[255]{};
		const char* old_msg = exception::what();
		strcat_s(message,strlen(old_msg) + 1,old_msg);
		strcat_s(message + strlen(old_msg),20," by MyException");
		return _strdup(message);
	}
};

class MyExceptionConcreet : public MyException
{
public:
	MyExceptionConcreet(const char* const message) : MyException(message) {}
	const char* what() const override
	{
		char* message = new char[255]{};
		const char* old_msg = MyException::what();
		strcat_s(message, strlen(old_msg) + 1, old_msg);
		strcat_s(message + strlen(old_msg), 50, " by MyExceptionConcreet");
		return _strdup(message);
	}
};
void func();
int foo()
{
	try
	{
		func();
	}
	catch (const MyExceptionConcreet* ex)
	{
		cout << endl << "Whell done!\n";
		cout << ex->what() << endl;

		throw;
	}

	catch (const MyException* ex)
	{
		cout << endl << "Good done!\n";
		cout << ex->what() << endl;

		throw;
		
	}
	catch (const exception* ex)
	{
		cout << endl << "Not done!\n";
		cout << ex->what() << endl;
	}
	
	catch (const char* str)
	{
		cout << str << endl;
	}
	/*catch (const MyException* ex)
	{
		cout << ex->what() << endl;

		throw;
	}*/
	return 0;
}

void func()
{
	//throw new MyExceptionConcreet("Ouuups!");
	throw new MyException("Ouuups!");
	throw "Hey there\n";

}

int main()
{
	cout << "Will print!\n";
	try
	{
		cout << foo();
	}
	catch (const exception* ex)
	{
		cout << ex->what() << endl;
	}

	cout << "Will not print!\n";


	/*Aftandil::A a;
	Aftandil::Israfil::B b;

	Aftandil::Israfil::abs(-20);*/
	return 0;
}