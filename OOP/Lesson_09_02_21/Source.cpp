#include<iostream>
#include<assert.h>
using namespace std;

class String
{
private:
	char* str;
public:
	String(const char* str)
	{
		cout << "Ctor with argument\n";
		this->str = _strdup(str);
	}
	String() : String("") { cout << "Default Ctor\n"; }
	String(const String &other)
	{
		cout << "Copy ctor with argument\n";
		this->str = _strdup(other.str);
	}
	String(String && other)
	{
		cout << "Move constructor\n";
		this->str = other.str;
		other.str = nullptr;
	}

	~String()
	{
		cout << "Destructor\n";
		delete[] str;
	}
	char* GetString()
	{
		return str;
	}
	char* GetString() const
	{
		return str;
	}
	void SetString(const char* str)
	{
		assert(str != nullptr && "NULL been sent to Setter of String!");
		delete[] this->str;
		this->str = _strdup(str);
	}

	String operator=(String other) = delete;

	explicit operator char* ()
	{
		return str;
	}

	char operator[](int num)
	{
		assert(num > 0 && num < strlen(str) - 1 && "Invalid index for String!\n");
		return str[num];
	}

	void operator() ()
	{
		cout << "\n\n";
	}

	String friend operator+(String first, String second);
	class Friend friend;
};

ostream& operator<< (ostream& o,const String& s)
{
	o << s.GetString() << endl;
	return o;
}

class Friend
{
private:
	String str;
public:
	void Print()
	{
		cout << str.str << endl;
	}
};

	String operator+(String first, String second)
	{
		char* new_str = new char[strlen(first.str) + strlen(second.str) + 1]{};
		strcpy_s(new_str, strlen(first.str) + 1, first.str);
		strcpy_s(new_str + strlen(first.str), strlen(second.str) + 1, second.str);
		return String(new_str);
	}

	/*String* Create(const char* str)
	{
		return new String(str);
	}*/

	String Create(const char* str)
	{
		String a(str);
		return a;
	}

	void Print(char* str)
	{
		cout << str << endl;
	}

int main()
{
	String s = Create("Afti");
	Print((char*)s);
	cout << s[1] << endl;
	s();

	cout << "Print String directly: ";
	cout << s << endl;

	/*String s("Aftandil ");
	String n("Mammadov");
	String t("Mr. ");
	String r = t + s + n;
	
	cout << r.GetString() << endl;*/

	return 0;
}