#include "Car.h"
#include <assert.h>

void Car::Accelerate()
{
	speed += 10;
}

void Car::Breake()
{
	speed -= 10;
}

void Car::Turn(OrientationalDirection direction)
{
	switch (Car::direction)
	{
	case East:
		if (direction == OrientationalDirection::Left)
		{
			Car::direction = GeographicalDirection::North;
		}
		else
		{
			Car::direction = GeographicalDirection::South;
		}
		break;

	case North:
		if (direction == OrientationalDirection::Left)
		{
			Car::direction = GeographicalDirection::West;
		}
		else
		{
			Car::direction = GeographicalDirection::East;
		}
		break;
	case West:
		if (direction == OrientationalDirection::Left)
		{
			Car::direction = GeographicalDirection::South;
		}
		else
		{
			Car::direction = GeographicalDirection::North;
		}
		break;
	case South:
		if (direction == OrientationalDirection::Left)
		{
			Car::direction = GeographicalDirection::East;
		}
		else
		{
			Car::direction = GeographicalDirection::West;
		}
		break;

	}
}

int Car::GetSpeed()
{
	return speed;
}

GeographicalDirection Car::GetDirection()
{
	return direction;
}

void Car::SetWeight(float weight)
{
		assert(weight >= 0 && "Weight can't be negative number");
		Car::weight = weight;
	//if (weight < 0)
	//{
	//	Car::weight = 0;
	//}
	//else
	//{
	//	Car::weight = weight;
	//}
}

float Car::GetWeight()
{
	return weight;
}