#include "resist.h"
#include <array>
#include <iostream>

void initResistor(Resistor& obj)
{
	const double epsilon = 1e-9;
	std::cout << "Enter resistance (Ohm): ";
	std::cin >> obj.resistance;
	if (obj.resistance < -epsilon)
		obj.resistance = 0;

	std::cout << "Enter max power (Watt): ";
	std::cin >> obj.max_power;
	if (obj.max_power < -epsilon)
		obj.max_power = 0;
}

void initResistors(Resistor* resistors, size_t size)
{
	for(size_t i = 0; i < size; i++)
	{
		Resistor res;
		initResistor(res);
		*(resistors + i) = res;
	}	
}

void showResistor(Resistor obj)
{
	std::cout << "resistance: " << obj.resistance\
	    << " Ohm, max power: " << obj.max_power  \
			<< " Watt\n";
}

void showResistors(Resistor* resistors, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "Resistor " << i + 1 << "\n";
		showResistor(resistors[i]);
	}
}

void checkResistors(Resistor* resistors, size_t size, double voltage)
{
	for (size_t i = 0; i < size; i++)
	{
		auto res = resistors[i];
		double power = (voltage * voltage) / res.resistance;
		if (res.max_power - power > 0)
			std::cout << "Resistor #" << i << " is good\n";
		else
			std::cout << "Resistor #" << i << " has been burned\n";
	}
}

