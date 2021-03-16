#pragma once
class MyClass
{
private:
	int m;
public:
	MyClass() : MyClass(0) {}
	MyClass(int num);
	void SetM(int num);
	int GetM();
};
