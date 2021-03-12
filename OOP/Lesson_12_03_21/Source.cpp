#include<iostream>
#include<fstream>
#include<sstream>

typedef int someINT;
using namespace std;

class Person
{
public:
	string name;
	string surname;
};

fstream& operator<<(fstream& st, const Person p)
{
	st << p.name;
	st << p.surname;
	return st;
}

int main()
{
	stringstream s;
	s << "Hello\n";
	

	fstream f;
	f.open("file.bin", ios::in | ios::out);
	if (f.is_open())
	{
		cin.get();
		Person p;
		p.name = "Israfil";
		p.surname = "Ahmedov";
		f << p;
		f.close();
	}

	someINT a;
	a = 10;

	//ostream f;
	//ifstream i;
	//iostream io;

	//fstream fs;
	//fs.open("file.bin",ios::out | ios::in );

	//ofstream of;
	//of.open("file.bin", ios::out | ios::binary);

	//ifstream ifs;
	//ifs.open("file.bin",ios::in | ios::binary );

	//

	//string str;
	//char* buffer = new char[255]{};
	//ifs.getline(buffer,255);
	//str = buffer;
	//cout << str << endl;

	/*string str = "Please baybe, don't show me your tears!";

	of << str;*/

	return 0;
}