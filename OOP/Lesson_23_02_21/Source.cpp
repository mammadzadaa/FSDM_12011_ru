#include<iostream>
#include<map>
#include<set>

using namespace std;

class Car
{
public:
	char* brend;
	char* model;
	double engine_size;
	Car(const char* brend, const char* model, const double engine_size)
	{
		this->brend = _strdup(brend);
		this->model = _strdup(model);
		this->engine_size = engine_size;
	}
	Car() {}
};

Car* car_array_creater(size_t size)
{
	auto car_array = new Car[size]{};
	return car_array;
}

void car_array_fill(Car* arr,const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		char* temp = new char[255]{};
		cout << "Enter Brand:";
		cin.getline(temp,255);
		
		arr[i].brend = _strdup(temp);
		memset(temp,0,255);

		cout << "Enter model:";
		cin.getline(temp, 255);
		arr[i].model = _strdup(temp);
		delete[] temp;

		cout << "Enter engine size:";
		cin >> arr[i].engine_size;
		cin.ignore();	
		cout << endl << endl;
	}
}

void print_car_array(const Car* const arr,const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Car Number " << i + 1 << endl;
		cout << arr[i].brend << " " << arr[i].model << " with " << arr[i].engine_size << " lt engine!\n\n";
	}
}

void write_car_array(const Car* const arr, const size_t size)
{
	FILE* ft;
	fopen_s(&ft,"cars.bin","wb");
	if (ft != nullptr)
	{
		fwrite(&size, sizeof(size), 1, ft);

		for (size_t i = 0; i < size; i++)
		{
			size_t size_of_str = strlen(arr[i].brend);
			fwrite(&size_of_str, sizeof(size_of_str), 1, ft);
			fwrite(arr[i].brend, sizeof(char), size_of_str, ft);

			size_of_str = strlen(arr[i].model);
			fwrite(&size_of_str, sizeof(size_of_str), 1, ft);
			fwrite(arr[i].model, sizeof(char), size_of_str, ft);

			fwrite(&(arr[i].engine_size), sizeof(double), 1, ft);
		}
		fclose(ft);
	}
}

Car* read_car_array(size_t& size)
{
	FILE* ft;
	fopen_s(&ft, "cars.bin", "rb");
	Car* arr = nullptr;
	if (ft != nullptr)
	{
		fread(&size, sizeof(size_t), 1, ft);
		arr = new Car[size]{};
		for (size_t i = 0; i < size; i++)
		{
			size_t str_len;
			char* temp = new char[255]{};
			fread(&str_len, sizeof(size_t), 1, ft);
			fread(temp, sizeof(char), str_len, ft);
			arr[i].brend = _strdup(temp);
			memset(temp, 0, 255);
			fread(&str_len, sizeof(size_t), 1, ft);
			fread(temp, sizeof(char), str_len, ft);
			arr[i].model = _strdup(temp);
			fread(&(arr[i].engine_size),sizeof(double),1,ft);
			delete[] temp;
		}
	}
	return arr;
}

int main()
{
	map<int, Car*> m;
	m.insert(pair<int, Car*>(1, new Car("BMW","M5",4.4)));
	m.insert(pair<int, Car*>(2, new Car("BMW", "M3", 4)));
	m.insert(pair<int, Car*>(3, new Car("Gaz", "201", 2.4)));
	m.insert(pair<int, Car*>(4, new Car("Vaz", "2101", 1.4)));

	cout << m.at(4)->brend;
	
	set<Car*> s;
	s.insert(new Car("BMW", "M5", 4.4));
	s.insert(new Car("BMW", "M3", 4));
	s.insert(new Car("Gaz", "201", 2.4));
	s.insert(new Car("Vaz", "2101", 1.4));

	

		
	//size_t size = 3;
	//auto car_array = car_array_creater(size);
	//car_array_fill(car_array, size);
	//print_car_array(car_array, size);
	//write_car_array(car_array,size);
	/*size_t size = 0;
	auto car_array = read_car_array(size);
	print_car_array(car_array, size);*/

	return 0;
}