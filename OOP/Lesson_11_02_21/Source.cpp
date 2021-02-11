#include "MyVector.h"
#include <iostream>
using namespace std;

void PrintInfo(MyVector vector)
{
	cout << "Size: " << vector.GetSize() << endl << "Capacity: " << vector.GetCapacity() << endl;
}

void PrintVector(MyVector vector)
{
	cout << endl;
	for (size_t i = 0; i < vector.GetSize(); i++)
	{
		cout << vector[i] << "  ";
	}
	cout << endl;
}

template<class T>
class Vec
{
private:
	size_t size;
	size_t capacity;
	T* arr;
};

int main()
{
	Vec<int> c;

	MyVector v(5);
	PrintInfo(v);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	v.push_back(70);

	PrintInfo(v);

	PrintVector(v);
	cout << v.pop_back() << endl;
	PrintVector(v);
	PrintInfo(v);

	v.shrink_to_fit();
	PrintInfo(v);


	return 0;
}