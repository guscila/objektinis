#pragma once

#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

struct info {
    string text;
    double size;
    double time;
};

class Timer {
    using hrClock = chrono::high_resolution_clock; // nurodomas kintamasis naudoti high_resolution_clock
    using durationDouble = chrono::duration<double>;   // nurodomas kintamasis naudoti duration<double>
private:
    std::chrono::time_point<hrClock> start;
    static vector<info>& store() {
        static vector<info> t;
        return t;
    }
public:
    Timer() : start{ hrClock::now() } {}
    void reset() {
        start = hrClock::now();
    }
    double elapsed() const {
        return durationDouble(hrClock::now() - start).count();  // laiko tarpo apskaičiavimas nuo starto iki dabar
    }
    void save(const string& text, double size) const {
        store().push_back(info{ text, size, elapsed() });
    }
    void saveReset(const string& text, double size) {
        save(text, size);
        reset();
    }
    static void printAll() {
        if (store().empty()) {
            cout << "Nera issaugotu laiku.\n";
            cout << string(50, '-') << endl;
            return;
        }
        for (const auto& t : store()) {
            cout << t.size << t.text << t.time << " sek.\n";
        }
    }
    static void clearAll() {
        store().clear();
    }
};