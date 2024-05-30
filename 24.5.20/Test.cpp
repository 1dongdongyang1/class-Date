#include"Date.h"

int main()
{
	Date d1(2020, 4, 11);
	Date d2;
	Date d3;

	d2 = d1 + -10;
	d2.Print();

	d3 = d1 - 10;
	d3.Print();
	return 0;
}
