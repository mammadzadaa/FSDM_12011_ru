#pragma once
enum Position
{
	Master, Chief, Worker, Assistant

};
class Empoyer
{
private:

	char* name;
	char* surname;
	int age;
	Position position;
	float work_experience;
	float salary;

public:

	char* GetName();
	void SetName(char*);

	char* GetSurname();
	void SetSurname(char*);

	int GetAge();

	Position GetPosition();
	void SetPosition(Position);

	float GetWorkExperience();

	float GetSalary();
	void SetSalary(float);


	Empoyer(char* name, char* surname, int age, Position position, float work_experience, float salary);
	Empoyer(char* name, char* surname, int age, Position position) : Empoyer(name, surname, age, position, 0, 0) {}
	Empoyer() : Empoyer((char*)"N/A",(char*)"N/A",0,Position::Worker,0,0) {}
	~Empoyer();


};

