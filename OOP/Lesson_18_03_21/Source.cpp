#include<iostream>

using namespace std;

//class SmartPtr
//{
//public:
//	SmartPtr(int* p)
//	{
//		ptr = p;
//	}
//	~SmartPtr()
//	{
//		if (ptr != nullptr)
//		{
//			delete[] ptr;
//		}
//	}
//	int* get_ptr()
//	{
//		return ptr;
//	}
//private:
//	int* ptr;
//
//};

//int* foo()
//{
//	//SmartPtr s_p = new int[10]{1,2,3,4,5,6,7,8,9,0};
//	SmartPtr s_p = nullptr;
//	return s_p.get_ptr();
//}

template<typename T>
class MyUnique
{
private:
	T* ptr;
	MyUnique() = delete;
	MyUnique(const MyUnique& other) = delete;
	MyUnique(int size)
	{
		ptr = new T[size]{};
	}
public:
	T operator*()
	{
		return *ptr;
	}
	T operator->()
	{
		return *ptr;
	}

	template<typename T>
	friend MyUnique<T> make_my_unique1(int size);

	 ~MyUnique()
	 {
		 if (ptr != nullptr)
		 {
			 delete[] ptr;
		 }
	 }
};

template<typename T>
MyUnique<T> make_my_unique1(int size)
{
	return MyUnique<T>(size);
}

class Person
{
public:
	char* name;
	int age;
};

int main()
{
	unique_ptr<int> p = make_unique<int>(10);
	unique_ptr<int> p1 = make_unique<int>(10);

	

	MyUnique<int> m_p = make_my_unique1<int>(10);

	unique_ptr<Person> p_ptr = make_unique<Person>();
	p_ptr->name = _strdup("afti");
	p_ptr->age = 45;

	
	

	
	


	/*int* p = foo();

	cout << p[0] << endl;*/
	
	

	//for (size_t i = 0; i < 100; i++)
	//{
	//	int* p = new int[1000]{};
	//	delete[] p;
	//}

	return 0;
}