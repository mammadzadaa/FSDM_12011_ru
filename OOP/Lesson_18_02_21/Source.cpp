#include<iostream>
using namespace std;

enum Priority
{
	High = 1, Mid, Low
};

template<class T>
class DLinkedList
{
private:
	struct Node
	{
		Node* next = nullptr;
		Node* previous = nullptr;
		Priority priority = Priority::High;
		T value;
	};
	Node* begin = nullptr;
public:
	void push(T val, Priority priority)
	{
		Node* temp = new Node();
		temp->value = val;
		temp->priority = priority;
		if (begin == nullptr)
		{
			temp->next = temp;
			temp->previous = temp;
			begin = temp;
		}
		else
		{
			temp->next = begin;
			temp->previous = begin->previous;
			begin->previous = temp;
			if (begin->next == begin)
			{
				begin->next = temp;
			}
			begin = temp;
		}
	}
};

int	main()
{
	DLinkedList<int> queue;
	queue.push(3,Priority::Low);
	queue.push(7, Priority::High);
	queue.push(9, Priority::Mid);
	queue.push(0, Priority::Low);
	queue.push(1, Priority::High);


	return 0;
}

