#include<iostream>

using namespace std;

class Transport
{
public:
	float speed;
	double weight;
	int capacity;

public:
	Transport() : Transport(0, 0, 0) {}

	Transport(float speed, double weight, int capacity)
	{
		this->speed = speed;
		this->weight = weight;
		this->capacity = capacity;
	}
	void virtual Move()
	{
		cout << "Transport generally moves!\n";
	}
};

class Car : public Transport
{
protected:
	float engine_size;
public:
	Car(float engine_size, float speed, double weight, int capacity) : Transport(speed, weight, capacity)
	{
		this->engine_size = engine_size;
	}
	void Move() override
	{
		cout << "Car is driven!\n";
	}
};

class Airplane : public Transport
{
private:
	float flight_time;
public:
	Airplane(float flight_time, float speed, double weight, int capacity) : Transport(speed, weight, capacity)
	{
		this->flight_time = flight_time;
	}
	void Move() override
	{
		cout << "Airplane is flewn!\n";
	}
};

class Ship : public Transport
{
private:
	float water_displacement;
public:
	Ship(float water_displacement, float speed, double weight, int capacity) : Transport(speed, weight, capacity)
	{
		this->water_displacement = water_displacement;
	}
	void Move() override
	{
		cout << "Ship is floated!\n";
	}
};

void PrintInfo(Transport t)
{
	cout << "Weight is " << t.weight << " ton\n";
	cout << "Speed is " << t.speed << " km/h\n";
	cout << "Capacty is " << t.capacity << " persons\n\n";
}

class Fighter
{
protected:
	int health_point;
public:
	virtual void Move() = 0;
	virtual void Attack(Fighter& other) = 0;
	void DecreaseHealth(int hp)
	{
		if ((health_point - hp) > 0)
		{
			health_point -= hp;
		}
		else
		{
			health_point = 0;
		}
	}
	int get_health()
	{
		return health_point;
	}
};

class Warior : public Fighter
{
public:
	Warior() { health_point = 100; }
	void Move() override
	{
		cout << "Warrior moves normal!\n";
	}
	void Attack(Fighter& other)
	{
		cout << "Warior attacks!\n";
		other.DecreaseHealth(30);
	}
};

class Knight : public Fighter
{
public:
	Knight() { health_point = 150; }
	void Move() override
	{
		cout << "Knight moves fast!\n";
	}
	void Attack(Fighter& other)
	{
		cout << "Knight attacks!\n";
		other.DecreaseHealth(25);
	}
};

class Archer : public Fighter
{
public:
	Archer() { health_point = 80; }
	void Move() override
	{
		cout << "Archer moves slow!\n";
	}
	void Attack(Fighter& other)
	{
		cout << "Archer attacks!\n";
		other.DecreaseHealth(15);
	}
};

class Army
{
private:
	Fighter** fighters;
	size_t quantity;
public:
	Army()
	{
		quantity = 5;
		fighters = new Fighter * [quantity] {};
		fighters[0] = new Archer();
		fighters[1] = new Warior();
		fighters[2] = new Warior();
		fighters[3] = new Knight();
		fighters[4] = new Archer();
	}
	void Move()
	{
		for (size_t i = 0; i < quantity; i++)
		{
			fighters[i]->Move();
		}
	}
	void Attack(Fighter& enemy)
	{
		for (size_t i = 0; i < quantity; i++)
		{
			fighters[i]->Attack(enemy);
		}
	}
	void ShowInfo()
	{
		for (size_t i = 0; i < quantity; i++)
		{
			cout << fighters[i]->get_health() << endl;
		}
	}

};

int main()
{
	Army a;
	a.Move();
	Knight k;
	a.Attack(k);
	a.ShowInfo();
	cout << endl << k.get_health() << endl;

	//Transport** t = new Transport * [3]{};
	//t[0] = new Car(2.2, 210, 1.8, 5);
	//t[1] = new Airplane(12.5, 940, 100, 140);
	//t[2] = new Ship(230, 30, 340, 25);
	//for (size_t i = 0; i < 3; i++)
	//{
	//	t[i]->Move();
	//}

	/*Transport tr(100,32.1,40);
	Car c(2.2,210,1.8,5);
	Airplane a(12.5,940,100,140);
	Ship s(230,30,340,25);

	Transport& t = c;
	Transport* t_ptr = new Airplane(10,870,95,86);*/

	/*tr.Move();
	c.Move();
	a.Move();
	s.Move();
	cout << endl << endl;
	t.Move();
	t_ptr->Move();*/


	/*PrintInfo(tr);
	PrintInfo(c);
	PrintInfo(a);
	PrintInfo(s);*/
	return 0;
}