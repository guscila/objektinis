#pragma once

#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

struct info {   // laiko trukmės informacijos struktūra
    string text;
    double size;
    double time;
};

class Timer {
    using hrClock = chrono::high_resolution_clock; // nurodomas kintamasis naudoti high_resolution_clock
    using durationDouble = chrono::duration<double>;   // nurodomas kintamasis naudoti duration<double>
private:
    std::chrono::time_point<hrClock> start;
    static vector<info>& store() {  // nurodoma laiko trukmių saugykla
        static vector<info> t;
        return t;
    }
public:
    Timer() : start{ hrClock::now() } {}
    void reset() {  // laikmačio reset funkcija
        start = hrClock::now();
    }
    double elapsed() const {    // laikmačio užbaigimo funkcija
        return durationDouble(hrClock::now() - start).count();  // laiko tarpo apskaičiavimas nuo starto iki dabar
    }
    void save(const string& text, double size) const {  // laiko trukmės išsaugojimo funkcija
        store().push_back(info{ text, size, elapsed() });   // laiko trukmės infromacijos patalpinimas į saugyklos vektorių
    }
    static void printAll() {    // visų laiko trukmių išvedimo funkcija
        if (store().empty()) {  // patikra, ar saugyklos vektorius netuščias
            cout << "Nera issaugotu laiku.\n";
            cout << string(50, '-') << endl;
            return;
        }
        for (const auto& t : store()) { // laiko trukmių išvedimas
            cout << t.size << t.text << t.time << " sek.\n";
        }
    }
    static void clearAll() {    // visų trukmių saugyklos išvalymas
        store().clear();
    }
};