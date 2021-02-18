#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<assert.h>

using namespace std;

template<class T>
class MyList
{
private:
	struct Node
	{
		Node* next = nullptr;
		T value;
	};
	Node* begin = nullptr;
public:
	void push_front(T val)
	{
		Node* temp = new Node();
		temp->next = begin;
		temp->value = val;
		begin = temp;
	}
	T pop_front()
	{
		assert(begin != nullptr && "No more element in list");
		Node* temp = begin;
		begin = begin->next;
		T val = temp->value;
		delete temp;
		return val;
	}

	void push_back(T val)
	{
		if (begin == nullptr)
		{
			begin = new Node();
			begin->value = val;
		}
		else
		{
			Node* iterator = begin;
			while (iterator->next != nullptr)
			{
				iterator = iterator->next;
			}
			iterator->next = new Node();
			iterator->next->value = val;
		}
	}

	T pop_back()
	{
		assert(begin != nullptr && "No more element in list");
		if (begin->next == nullptr)
		{
			T val = begin->value;
			delete begin;
			begin = nullptr;
			return val;
		}

		if (begin->next->next == nullptr)
		{
			T val = begin->next->value;
			delete begin->next;
			begin->next = nullptr;
			return val;
		}
		Node* iterator = begin->next;
		Node* iterator_prev = begin;

		while (iterator->next != nullptr)
		{
			iterator_prev = iterator;
			iterator = iterator->next;
		}
		T val = iterator->value;
		delete iterator;
		iterator_prev->next = nullptr;
		return val;
	}

};

void foo(string s) {}
class Person
{
private:
	string name;
	string surname;
public:
	Person()
	{

	}
};

int main()
{
	MyList<int> list;

	list.push_back(3);
	list.push_back(12);
	list.push_back(32);
	list.push_back(54);
	list.push_back(11);

	for (size_t i = 0; i < 5; i++)
	{
		cout << list.pop_back() << endl;
	}

	//list.push_front(2);
	//list.push_front(34);
	//list.push_front(19);
	//list.push_front(10);

	//for (size_t i = 0; i < 5; i++)
	//{
	//	cout << list.pop_front() << endl;
	//}

	/*vector<Person> people;
	array<int, 10> arr;
	cout << "Array: ";
	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
		cout << arr[i] << " ";
	}
	cout << endl;

	vector<int>  vec;
	cout << "\nVector: ";
	
	for (size_t i = 0; i < 15; i++)
	{
		vec.push_back(i + 1);
		cout << vec[i] << " ";
	}
	vec.shrink_to_fit();
	cout << endl << vec.capacity() << endl << vec.size() << endl;


	string name;
	name = "Hello";
	auto s = name + "Hi";
	foo(s);*/
}