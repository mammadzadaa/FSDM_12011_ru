#include <iostream>
#include"Car.h"
#include "Source.h"

using namespace std;

//struct Person
//{
//	char* name;
//	char* surname;
//
//	void Walk()
//	{
//		cout << "Hi" << endl;
//		cout << age << endl;
//	}
//private: 
//	int age = 0;
//};
//
//
//
//
//
//class PersonClass
//{
//public:
//	char* name; // поля
//protected:
//	void Walk() // методы
//	{
//		cout << "Hi" << endl;
//	}
//	
//public:
//	char* surname;
//	void Swimm();
//};
//
//void PersonClass::Swimm()
//{
//
//}

// private | protected | public  - модификаторы доступа (access specifiers)

void ShowSpeed(Car* car)
{
	cout << "Your " << car->model << " speed is " << car->GetSpeed() << " km/h" << endl;
}


void ShowDirection(Car* car)
{
	switch (car->GetDirection())
	{
	case East:
		cout << "Your " << car->model << " direction is East" << endl;
		break;			   
	case North:			   
		cout << "Your " << car->model << " direction is North" << endl;
		break;			   
	case West:			   
		cout << "Your " << car->model << " direction is West" << endl;
		break;			  
	case South:			  
		cout << "Your " << car->model << " direction is South" << endl;
		break;
	}
}

int main()
{
	Car* mazda = new Car;
	mazda->model = _strdup("R7");
	mazda->color = Color::Black;
	mazda->engine_volume = 4.4;
	mazda->gearbox_type = GearBoxType::Manual;
	mazda->SetWeight(-1457);
	cout << mazda->GetWeight() << endl << endl;

	
	ShowSpeed(mazda);
	mazda->Accelerate();
	mazda->Accelerate();
	mazda->Accelerate();
	mazda->Accelerate();
	ShowSpeed(mazda);
	cout << "\n\n\n\n";
	
	ShowDirection(mazda);
	mazda->Turn(OrientationalDirection::Right);
	ShowDirection(mazda);
	mazda->Turn(OrientationalDirection::Left);
	ShowDirection(mazda);

	cout << "\n\n\n\n";

	mazda->Breake();
	mazda->Breake();
	ShowSpeed(mazda);


	//Person afti;
	//Person* isi = new Person;
	//afti.Walk();
	//afti.name = _strdup("Aftandil");
	//isi->Walk();

	//PersonClass afti_class;
	////afti_class.Walk(); // inacessable
	//afti_class.name = _strdup("Aftandil");
}