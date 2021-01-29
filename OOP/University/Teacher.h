#pragma once
#include "Gender.h"

class Teacher
{
private:
	char* firstname;
	char* lastname;
	int age;
	Gender gender;
	char* subject;
public:
	char* GetName();
	void SetName(char*);

	char* GetFirstname();
	void SetFirstname(char*);

	int GetAge();
	void SetAge(int);

	Gender GetGender();

	char* GetSubject();
	void SetSubject(char*);

	Teacher(char*, char*, int, Gender, char*);
	Teacher() :Teacher((char*)"Name", (char*)"Lastname", 0, Gender::Male, (char*)"Subject"){}
	Teacher(char* firstname, char* lastname) : Teacher(firstname, lastname, 0, Gender::Male, (char*)"Subject") {}

};

