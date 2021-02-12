#include<iostream>
using namespace std;

template<class T1, class T2>
class Template
{
	T1* arr;
	T2 size;
public:
	void Foo() {}

};

template<class T>
class Template<int, class T>
{
	int* arr;
	T size;
public:
	void Function() {}
};


template<>
class Template<int, size_t>
{
	int* arr;
	size_t size;
public:
	void Function() {}
};

template<class T, size_t size>
class Array
{
	T arr[size]{};
	size_t lenght = size;
};

int main()
{
	Template<int, size_t> f;

	Array<char, 10> arr;
	

	return 0;
}