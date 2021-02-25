#include<iostream>
#include<list>
using namespace std;

//class Room
//{
//public:
//	char* name;
//	double sqm;
//};
//
//class Building
//{
//public:
//	//Room rooms[10]{};
//	Room* rooms;
//	Building()
//	{
//		rooms = new Room[10]{};
//	}
//	~Building()
//	{
//		delete[] rooms;
//	}
//};
//
//class StudentsGroup
//{
//public:
//	Student** students = nullptr;
//	size_t student_count = 0;
//	void add_Student(Student* student)
//	{
//		if (student != nullptr)
//		{
//			if (students == nullptr)
//			{
//				students = new Student * [1]{};
//			}
//			else
//			{
//				auto temp = new Student * [student_count + 1]{};
//				for (size_t i = 0; i < student_count; i++)
//				{
//					temp[i] = students[i];
//				}
//				delete[] students;
//				students = temp;
//			}
//			students[student_count++] = student;
//			
//		}
//		
//	}
//	~StudentsGroup()
//	{
//		if (student_count > 0)
//		{
//			delete[] students;
//		}
//	}
//};
//
//class Student
//{
//public:
//	char* name;
//	char* surname;
//	int age;
//};

//class A
//{
//private:
//	int num;
//	class B
//	{
//	public:
//		int num_b;
//	};
//public:
//	class C
//	{
//	public:
//		int num_c;
//	};
//	void foo()
//	{
//		B b;
//		b.num_b;
//	}
//};

//class Base
//{
//public:
//	int a;
//protected:
//	int b;
//private:
//	int c;
//};
//
//class Derived : public Base
//{
//public:
//	int e;
//	void foo()
//	{
//		a = 5;
//		b = 6;
//		c = 1;
//	}
//};
//
//class D : Derived
//{
//	void foo()
//	{
//		a = 3;
//		b = 2;
//		c = 1;
//	}
//};

class Base{
private:
	int a;
protected:
	int b;
	int GetA()
	{
		return a;
	}
public:
	int c;
};
class Derived : private Base{
private:
	int d;
protected:
	int e;
	void foo()
	{
		GetA();
	}
public:
	int f;
};
int main()
{
	cout << sizeof(Base) << endl;
	cout << sizeof(Derived) << endl;


	/*Base b;
	Derived d;*/
	
	//A::C c;
	//c.num_c;
	//list<int> l;
	//auto i = l.begin();
	//while (i != l.end())
	//{
	//	*i;
	//	i++;
	//}

	//Building b;
	//Building* d = new Building;
	//d->rooms[0].name;
	//b.rooms[0].sqm;
}

