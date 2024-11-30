#include "includes/Serializer.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2)
	{
		std::cout << "No valid args"<< std::endl;
		return 1;
	}
	Data test;
	test.value = av[1];
	uintptr_t serialized = Serializer::serialize(&test);
	std::cout << "Serialized Data: " << serialized << std::endl;
	Data* raw = Serializer::deserialize(serialized);
	if (raw == &test)
		std::cout << "Raw Data: " << raw->value << std::endl;
	return 0;
}