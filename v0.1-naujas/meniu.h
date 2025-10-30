#pragma once

#include <string>

enum class Container {Vector, List};

struct MeniuAts {
	int pasirinkimas;
	std::string name;
	Container konteineris;
};