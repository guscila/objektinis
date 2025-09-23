
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

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

struct Studentas {
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzas;
    float rez;
    float mediana;
};

Studentas ivesk();
void isvesk(const vector<Studentas>& grupe);

int main()
{
    vector<Studentas> grupe;
    for (int j = 0; j < 3; j++)
    {
        cout << "Iveskite " << j + 1 << " studenta: \n";
        grupe.push_back(ivesk());
    }
    isvesk(grupe);
    return 0;
}

Studentas ivesk() {
    Studentas laik;
    int sum = 0, n, paz, x;
    string ivestis; // ivestis naudojama rankiniu budu ivedant namu darbu pazymius
    random_device rd;   //
    mt19937 gen(rd());  // "random" engine kodas
    uniform_int_distribution<> dist(1, 10); // random algoritmo ribos (1-10)
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> laik.vardas >> laik.pavarde;
    cout << "Jei norite, ivesti namu darbu pazymius ir egzamino bala rankiniu budu - iveskite 1, jei norite, kad pazymiai butu sugeneruoti atsitiktinai - iveskite 2: "; cin >> x;
    while (x != 1 && x != 2) {  // apsauga, kad butu ivedama 1 arba 2
        cout << "Neteisinga ivestis. ";
        cout << "Jei norite, ivesti namu darbu pazymius ir egzamino bala rankiniu budu - iveskite 1, jei norite, kad pazymiai butu sugeneruoti atsitiktinai - iveskite 2: "; cin >> x;
    }
    if (x == 1) {   // pasirinktis, jei norima ivesti rankiniu budu
        cout << "Iveskite studento namu darbu pazymius, kai noresite sustoti iveskite zodi 'baigta':" << endl;
        while (true) {
            cin >> ivestis;
            if (ivestis == "baigta") break;
            try {
                paz = stoi(ivestis);
                laik.pazymiai.push_back(paz);
                sum += paz;
            }
            catch (...) {   // apsauga, kad butu ivedami tik skaiciai arba baigiamasis zodis
                cout << "Neteisinga ivestis - iveskite skaiciu, o jei norite baigti, iveskite zodi 'baigta':" << endl;
            }
        }
        cout << "Iveskite egzamino bala: "; cin >> laik.egzas;
    }
    else if (x == 2) {  // pasirinktis, jei norima, kad duomenys butu atsitiktinai generuojami
        int nd;
        cout << "Iveskite kiek studento namu darbu pazymiu norite atsitiktinai sugeneruoti: "; cin >> nd;
        for (int i = 0; i < nd; i++) {
            paz = dist(gen);
            laik.pazymiai.push_back(paz);
            sum += paz;
        }
        laik.egzas = dist(gen);
    }
    laik.rez = laik.egzas * 0.6 + double(sum) / double(laik.pazymiai.size()) * 0.4; // galutinio vidurkio apskaiciavimas
    n = laik.pazymiai.size();
    sort(laik.pazymiai.begin(), laik.pazymiai.end());
    if (n % 2 == 1) {   // medianos apskaiciavimas
        laik.mediana = laik.pazymiai[n / 2];
    }
    else {
        laik.mediana = (laik.pazymiai[(n / 2) - 1] + laik.pazymiai[n / 2]) / 2.0;
    }
    return laik;
}

void isvesk(const vector<Studentas>& grupe) {
    int x; 
    cout << "Jei norite, kad programa isvestu tik studentu vidurkius - iveskite 1, jei norite, kad programa isvestu tik studentu medianas - iveskite 2, jei norite, kad isvestu abi reiksmes - iveskite 3: "; cin >> x;
    while (x != 1 && x != 2 && x != 3) {    // apsauga, kad butu ivedama 1, 2 arba 3
        cout << "Neteisinga ivestis. ";
        cout << "Jei norite, kad programa isvestu tik studentu vidurkius - iveskite 1, jei norite, kad programa isvestu tik studentu medianas - iveskite 2, jei norite, kad isvestu abi reiksmes - iveskite 3: "; cin >> x;
    }
    if (x == 1) {   // isvetis tik su vidurkiu
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
        cout << string(50, '-') << endl;
        for (auto temp : grupe)
            cout << left << setw(15) << temp.vardas << setw(15) << temp.pavarde << setw(20) << fixed << setprecision(2) << temp.rez << endl;
    }
    else if (x == 2) {  // isvetis tik su mediana
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Med.)" << endl;
        cout << string(50, '-') << endl;
        for (auto temp : grupe)
            cout << left << setw(15) << temp.vardas << setw(15) << temp.pavarde << setw(20) << fixed << setprecision(2) << temp.mediana << endl;
    }
    else if (x == 3) {  // isvetis su vidurkiu ir mediana
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
        cout << string(70, '-') << endl;
        for (auto temp : grupe)
            cout << left << setw(15) << temp.vardas << setw(15) << temp.pavarde << setw(20) << fixed << setprecision(2) << temp.rez << setw(20) << fixed << setprecision(2) << temp.mediana << endl;
    }
}