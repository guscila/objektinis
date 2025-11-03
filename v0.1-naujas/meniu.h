#pragma once

#include <string>

enum class Container {Vector, List};

struct MeniuAts {	// meniu struktūra
	int pasirinkimas;
	std::string name;
	Container konteineris;
};