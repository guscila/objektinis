#pragma once

#include <string>
#include <vector>

struct Studentas {  // studento struktūra
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzas;
    float rez;
    float mediana;
};