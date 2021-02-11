#include "MyVector.h"
#include <assert.h>

MyVector::MyVector(size_t capacity)
{
	this->capacity = capacity;
	if (capacity > 0)
	{
		arr = new int[capacity] {};
	}
}

MyVector::MyVector(const MyVector& other)
{
	this->arr = new int[other.capacity]{};
	this->size = other.size;
	this->capacity = other.capacity;
	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}
MyVector::MyVector(MyVector&& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->arr = other.arr;
	other.arr = nullptr;
}
MyVector::~MyVector()
{
	delete[] arr;
}

size_t MyVector::GetSize()
{
	return size;
}
size_t MyVector::GetCapacity()
{
	return capacity;
}

void MyVector::ChangeCapacity(size_t new_capacity)
{
	int* temp_arr = new int[new_capacity] {};
	capacity = new_capacity;
	for (size_t i = 0; i < size; i++)
	{
		temp_arr[i] = arr[i];
	}
	delete[] arr;
	arr = temp_arr;
}

void MyVector::push_back(int element)
{
	if (!(capacity > size))
	{
		ChangeCapacity(capacity * 2);
	}
	arr[size++] = element;
}
int MyVector::pop_back()
{
	return arr[--size];
}
int MyVector::at(size_t index)
{
	assert(index >= 0 && index < size && "Invalid index for at function!\n");
	return arr[index];
}
bool MyVector::is_empty()
{
	return size == 0;
}
int& MyVector::operator[](size_t index)
{
	assert(index >= 0 && index < size && "Invalid index for at function!\n");
	return arr[index];
}
MyVector MyVector::operator+(const MyVector& other)
{
	size_t new_capacity;
	if ((this->size + other.size) > this->capacity)
	{
		new_capacity = this->capacity + other.capacity;
	}
	else
	{
		new_capacity = this->capacity;
	}
	MyVector temp(new_capacity);
	temp.size = this->size + other.size;
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->arr[i];
	}
	for (size_t i = this->size, j = 0; j < other.size; i++,j++)
	{
		temp[i] = other.arr[j];
	}
	return temp;
}

void MyVector::shrink_to_fit()
{
	ChangeCapacity(size);
}