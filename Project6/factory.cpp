#include "factory.h"


factory::factory(char* a, char* b, int vol)
{
	for (int i = 0; i < 20; i++)
	{
		name[i] = a[i];
		product[i] = b[i];
	}
	this->vol = vol;
}

factory::factory()
{
	name = new char[20];
	product = new char[20];
	for (int i = 0; i < 20; i++)
	{
		name[i] = ' ';
		product[i] = ' ';
	}
	this->vol = -1;
}

std::ostream& operator<<(std::ostream& st, const factory f)
{
	for (int i = 0; i < 20; ++i)
	{
		st << f.name[i];
	}
	for (int i = 0; i < 20; ++i)
	{
		st << f.product[i];
	}
	st << f.vol;
	return st;
}

std::istream& operator>>(std::istream& input, factory& f)
{
	for (int i = 0; i < 20; ++i)
	{
		input >> f.name[i];
	}
	for (int i = 0; i < 20; ++i)
	{
		input >> f.product[i];
	}
	input >> f.vol;
	return input;
}
