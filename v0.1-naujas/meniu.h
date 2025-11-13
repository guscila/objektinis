#pragma once

#include <string>

enum class Container {Vector, List};

struct MeniuAts {	// meniu struktūra
	int pasirinkimas;
	string name;
	Container konteineris;
	int strategija;
};