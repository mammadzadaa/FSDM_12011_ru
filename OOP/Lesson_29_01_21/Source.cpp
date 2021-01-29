#include <iostream>
using namespace std;

namespace farid
{
	class A
	{

	};
}
namespace mynamespace
{
	class A
	{
	};
	class Entity2
	{
	public:
		int a;
		int b;
		static int c;

		void Print()
		{
			cout << a << " " << b << " " << c << endl;
		}

		static void foo()
		{
			cout << c << endl;
		}
	};
}

class Entity
{
public:

	static const int num;

	Entity()
	{
		cout << "Ctor been called\n";
	}
	Entity(int) : Entity()
	{
		cout << "Ctor with Param\n";
	}
	~Entity()
	{
		cout << "Destructor been called\n";
	}
};

const int Entity::num = 1;

static class Math
{
public:
	static float Pi;
	static int Sum(int x, int y)
	{
		return x + y;
	}

};

float Math::Pi = 3.14;

int mynamespace::Entity2::c = 0;

int main()
{
	cout << Math::Pi << endl << Math::Sum(2, 3) << endl;

	mynamespace::A a;
	farid::A b;

	mynamespace::Entity2 e;
	mynamespace::Entity2 e1;

	e.a = 1;
	e.b = 2;
	e.c = 3;
	e.Print();

	e1.a = 10;
	e1.b = 20;
	e1.c = 30;
	e1.Print();

	cout << endl << e.c << endl;
	cout << endl << mynamespace::Entity2::c << endl;

	/*Entity2::Print();*/
	mynamespace::Entity2::foo();


	/*cout << Entity::num << endl;*/
	//Entity* e = new Entity(1);

	//delete e;

	//{
	//	Entity e;
	//}
	cin.get();
}