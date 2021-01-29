#include "Teacher.h"
#include <assert.h>
#include <iostream>

using namespace std;

char* Teacher::GetName()
{
	return firstname;
}
void Teacher::SetName(char* name)
{
	assert(firstname != NULL && "Name is NULL\n");
	delete firstname;
	firstname = _strdup(name);
}

char* Teacher::GetFirstname()
{
	return lastname;
}
void Teacher::SetFirstname(char* lastname_value)
{
	assert(lastname != NULL && "Lastname is NULL");
	delete lastname;
	lastname = _strdup(lastname_value);
}

int Teacher::GetAge()
{
	return age;
}
void Teacher::SetAge(int age_value)
{
	assert(!age < 0 && "Age is negative");
	age = age_value;
}

Gender Teacher::GetGender() 
{
	return gender;
}

char* Teacher::GetSubject()
{
	return subject;
}
void Teacher::SetSubject(char* subject_value)
{
	assert(subject != NULL && "Subject is NULL");
	delete subject;
	subject = _strdup(subject_value);
}

Teacher::Teacher(char* firstname_value, char* lastname_value, int age_value, Gender gender_value, char* subject_value)
{
	SetName(firstname_value);
	SetFirstname(lastname_value);
	SetAge(age_value);
	

}
