#pragma once
class MyVector
{
private:
	int* arr;
	size_t size = 0;
	size_t capacity;

	void ChangeCapacity(size_t new_capacity);
public:
	MyVector(size_t capacity);
	MyVector() : MyVector(4) {}
	MyVector(const MyVector& other);
	MyVector(MyVector&& other);
	~MyVector();

	size_t GetSize();
	size_t GetCapacity();



	void push_back(int element);
	int pop_back();
	int at(size_t index);
	bool is_empty();
	int& operator[](size_t index);
	MyVector operator+(const MyVector& other);
	void shrink_to_fit();

};

