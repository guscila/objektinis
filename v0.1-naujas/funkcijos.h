#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <limits>
#include <chrono>
#include <utility>
#include <list>
#include <type_traits>
#include <iterator>

#include "studentas.h"
#include "Timer.h"
#include "meniu.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::setfill;
using std::setprecision;
using std::fixed;
using std::stable_sort;
using std::uniform_int_distribution;
using std::mt19937;
using std::random_device;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::stringstream;
using std::cerr;
using std::numeric_limits;
using std::streamsize;
using std::list;

MeniuAts meniu();    // meniu funkcija
int VienasDu(); // funkcija patikrai, kad meniu įvestis būtų 1 arba 2
int tikNr();	// funkcija patikrai, kad įvestis yra skaičius didesnis už 0
Studentas ivesk();  // studentų įvesties fukcija
template<typename cont>
void NuskaitymasIsFailo(cont& grupe, string name);   // funkcija duomenų nuskaitymui iš failo
template<typename cont>
void IsvedimasIFaila(cont& grupe, string name);  // funkcija rezultatų išvedimui į failą
template<typename cont>
void IsvedimasITerminala(cont& grupe);	// funckija rezultatų išvedimui į terminalą
float mediana(vector<int>& pazymiai);   // medianos apskaičiavimo funkcija
void FailuGeneravimas(string name);	// studentų duomenų failų generavimo funkcija
template<typename cont>
void StudentuKategorizacija(cont& grupe, cont& vargsiukai, cont& kietiakai);	// studentų kategorizacijos funkcija į Vargšiukus ir Kietiakus
template<typename cont>
void FailuTestavimas(cont& grupe, cont& vargsiukai, cont& kietiakai, string name, int strategija);	// failų greičio spartos analizės funkcija
template<typename cont>
void StudentuRusiavimas(cont& grupe, string name);	// studentų rūšiavimo funkcija

// templates:
template void NuskaitymasIsFailo<vector<Studentas>>(vector<Studentas>&, string);
template void NuskaitymasIsFailo<list<Studentas>>(list<Studentas>&, string);
template void IsvedimasIFaila<vector<Studentas>>(vector<Studentas>&, string);
template void IsvedimasIFaila<list<Studentas>>(list<Studentas>&, string);
template void StudentuKategorizacija<vector<Studentas>>(vector<Studentas>&, vector<Studentas>&, vector<Studentas>&);
template void StudentuKategorizacija<list<Studentas>>(list<Studentas>&, list<Studentas>&, list<Studentas>&);
template void FailuTestavimas<vector<Studentas>>(vector<Studentas>&, vector<Studentas>&, vector<Studentas>&, string, int strategija);
template void FailuTestavimas<list<Studentas>>(list<Studentas>&, list<Studentas>&, list<Studentas>&, string, int strategija);
template void StudentuRusiavimas<vector<Studentas>>(vector<Studentas>&, string);
template void StudentuRusiavimas<list<Studentas>>(list<Studentas>&, string);
template void IsvedimasITerminala<vector<Studentas>>(vector<Studentas>&);
template void IsvedimasITerminala<list<Studentas>>(list<Studentas>&);