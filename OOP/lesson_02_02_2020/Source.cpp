#include<iostream>
using namespace std;

class Entity
{
	public:
		int a;
		int b;

		void Print()
		{
			cout << a << " " << b << endl;
		}

		//int foo(int a, int b)
		//{
		///*	return this->a + this->b;*/
		//	return a + b;
		//}

};

class Person
{
public:
	Person()
	{
		age = 10;
		name = _strdup("N/A");
		num = new int(0);
		cout << "Ctor ben called!\n";
	}

	Person(const Person &other)
	{
		cout << "Copy constructor called\n";
		this->age = other.age;
		this->num = new int(*other.num);
		this->name = _strdup(other.name);
	}

	char* name;
	int age;
	int* num;
	void Print()
	{
		cout << "Name is " << name << " age is " << age << " " << *num << endl;
	}
};

void foo(Person p)
{
	cout << "Inside the function!\n";
}

Person foo1()
{
	Person person;
	return person;
}

int main()
{
	int a = 5;

	Person p = foo1();

	//foo(person);

	cout << "end\n";


	/*Person p1;
	p1.name = _strdup("Aftandil");
	p1.age = 45;
	p1.num = new int(5);
	p1.Print();

	Person p2 = p1;
	p2.Print();

	cout << "\n\n";

	delete p2.name;
	p2.name = _strdup("Israfil");
	p2.age = 35;
	*p2.num = 6;

	p1.Print();
	p2.Print();*/


	//Entity* ptr = new Entity();
	//ptr->a;

	//Entity a;
	//a.a = 5;
	//a.b = 6;
	//a.Print();

	//Entity b;
	//b = a;
	//b.Print();
	//b.b = 10;
	//a.Print();
	//b.Print();


}
