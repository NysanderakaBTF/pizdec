#pragma once
#include <string>
#include <iostream>
struct factory
{
public:
	char* name;
	char* product;
	int vol;
	factory(char* a, char* b, int vol);
	factory();
	friend std::ostream& operator<<(std::ostream&, const factory);
	friend std::istream& operator>>(std::istream& input, factory& f);
};
