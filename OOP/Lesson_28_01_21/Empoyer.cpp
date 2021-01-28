#include "Empoyer.h"
#include <iostream>
#include <assert.h>
using namespace std;
char* Empoyer::GetName() 
{
	return name;
}
void Empoyer::SetName(char* name_value) 
{
	assert(name != NULL && "Name is null\n\n");
	delete name;
	name = _strdup(name_value);
}

char* Empoyer::GetSurname() 
{
	return surname;
}
void Empoyer::SetSurname(char* surname_value)
{
	assert(surname != NULL && "Surname is null\n\n");
	delete surname;
	surname = _strdup(surname_value);
}

int Empoyer::GetAge() 
{
	return age;
}

Position Empoyer::GetPosition() 
{
	return position;
}
void Empoyer::SetPosition(Position p)
{
	position = p;
}

float Empoyer::GetWorkExperience() 
{
	return work_experience;
}

float Empoyer::GetSalary() 
{
	return salary;
}
void Empoyer::SetSalary(float s) 
{
	assert(salary < 0 && "Salary is negative\n\n");
	salary = s;
}

Empoyer::Empoyer(char* name, char* surname, int age, Position position, float work_experience, float salary)
{
	SetName(name);
	SetSurname(surname);
	SetSalary(salary);
	SetPosition(position);
	assert(age >= 0 && "Age is negative\n\n");
	assert(work_experience >= 0 && "Work experience is negative!");

	this->age = age;
	this->work_experience = work_experience;
}

Empoyer::~Empoyer()
{
	delete name;
	delete surname;
}