#include"stdio.h"

typedef struct MyStruct
{

	int a;
	void (*foo)();

} MyStruct;

void my_foo()
{
	printf("This is pure C, baybe!");
}

int main()
{
	MyStruct my;
	my.foo = my_foo;

	my.foo();
}