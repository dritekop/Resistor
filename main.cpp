#include "resist.h"

int main(int argc, char** argv)
{
	Resistor* res = new Resistor[4];
	initResistors(res, 4);
	showResistors(res, 4);
	checkResistors(res, 4, 40);
	delete[] res;
}