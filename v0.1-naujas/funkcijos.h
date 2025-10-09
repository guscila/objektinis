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
#include "studentas.h"
#include "timer.h"

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
using std::sort;
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
using std::pair;
using std::make_pair;


pair<int, string> meniu();    // meniu funkcija
int VienasDu(); // funkcija patikrai, kad meniu įvestis būtų 1 arba 2
int tikNr();	// funkcija patikrai, kad įvestis yra skaičius didesnis už 0
Studentas ivesk();  // studentų įvesties fukcija
void NuskaitymasIsFailo(vector<Studentas>& grupe, string name);   // funkcija duomenų nuskaitymui iš failo
void IsvedimasIFaila(vector<Studentas>& grupe, string name);  // funkcija rezultatų išvedimui į failą
float mediana(vector<int>& pazymiai);   // medianos apskaičiavimo funkcija
void FailuGeneravimas(string name);	// studentų duomenų failų generavimo funkcija
void StudentuRusiavimas(vector<Studentas>& grupe, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai);	// studentų rūšiavimo funkcija į Vargšiukus ir Kietiakus
void FailuTestavimas(vector<Studentas>& grupe, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai, string name);	// failų greičio spartos analizės funkcija