#include <vector>

struct Resistor {
	double resistance;
	double max_power;
};

void initResistor(Resistor&);
void initResistors(Resistor*, size_t);
void showResistor(Resistor);
void showResistors(Resistor*, size_t);
void checkResistors(Resistor*, size_t, double);