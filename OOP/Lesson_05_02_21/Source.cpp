#include<iostream>
#include<assert.h>
using namespace std;

class Fraction
{
private:
	int num;
	int denom;
public:
	Fraction(int num, int denom)
	{
		assert(denom != 0 && "Denom can't be 0");
		this->num = num;
		this->denom = denom;
	}
	Fraction() : Fraction(0, 1) {}
	int GetNom()
	{
		return num;
	}
	int GetNom() const
	{
		return num;
	}
	void SetNom(int num)
	{
		this->num = num;
	}
	int GetDenom()
	{
		return denom;
	}
	int GetDenom() const
	{
		return denom;
	}
	void SetDenom(int num)
	{
		assert(denom != 0 && "Denom can't be 0");
		this->denom = denom;
	}
	static Fraction Sum(const Fraction& one, const Fraction& two)
	{
		int temp_num = one.num * two.denom + one.denom * two.num;
		int temp_denom = one.denom * two.denom;
		return Fraction(temp_num, temp_denom);
	}

	bool operator==(Fraction other)
	{
		return false;
	}

	Fraction operator++()
	{
		SetNom(this->num + this->denom);
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction temp(this->num, this->denom);
		SetNom(this->num + this->denom);
		return temp;
	}

	Fraction operator+(Fraction other)
	{
		int temp_num = this->num * other.denom +  this->denom * other.num;
		int temp_denom = this->denom * other.denom;
		return Fraction(temp_num, temp_denom);
	}

/*	static Fraction operator+(Fraction one, Fraction two)
	{
		int temp_num = one.GetNom() * two.GetDenom() + one.GetDenom() * two.GetNom();
		int temp_denom = one.GetDenom() * two.GetDenom();
		return Fraction(temp_num, temp_denom);
	}*/	
};

//Fraction operator+(Fraction one, Fraction two)
//{
//	int temp_num = one.GetNom() * two.GetDenom() + one.GetDenom() * two.GetNom();
//	int temp_denom = one.GetDenom() * two.GetDenom();
//	return Fraction(temp_num, temp_denom);
//}

void PrintFraction(const Fraction& fraction)
{
	cout << fraction.GetNom() << "/" << fraction.GetDenom() << endl;
}

int main()
{
	Fraction f(1, 3);
	PrintFraction(f++);
	Fraction fr(2, 5);
	Fraction sum_result = Fraction::Sum(f, fr);
	Fraction oper_result = f + fr;


	PrintFraction(f);
	cout << "+\n";
	PrintFraction(fr);
	cout << "=\n";
	PrintFraction(sum_result);
}