#pragma once

enum GearBoxType
{
	Manual, Automatic, Robot
};

enum Color
{
	White, Black, Red, Blue
};

enum GeographicalDirection
{
	East, North, West, South
};

enum OrientationalDirection
{
	Left, Right
};

class Car
{
public:
	char* model;
	float engine_volume;
	GearBoxType gearbox_type;
	Color color;

private:
	float weight;
public:
	void SetWeight(float weight);
	float GetWeight();

private:
	int speed = 0;
	GeographicalDirection direction = GeographicalDirection::North;

public:
	void Accelerate();
	void Breake();
	int GetSpeed();
	void Turn(OrientationalDirection direction);
	GeographicalDirection GetDirection();

};

