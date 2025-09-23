
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

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
using std::string;
using std::sort;

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
    int sum = 0, n, paz;
    string ivestis;
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> laik.vardas >> laik.pavarde;
    cout << "Iveskite studento namu darbu pazymius, kai noresite sustoti iveskite zodi 'baigta':" << endl;
    while (true) {
        cin >> ivestis;
        if (ivestis == "baigta") break;
        try {
            paz = stoi(ivestis);
            laik.pazymiai.push_back(paz);
            sum += paz;
        }
        catch (...) {
            cout << "Neteisinga ivestis - iveskite skaiciu, o jei norite baigti, iveskite zodi 'baigta':" << endl;
        }
    }
    cout << "Iveskite egzamino bala: "; cin >> laik.egzas;
    laik.rez = laik.egzas * 0.6 + double(sum) / double(laik.pazymiai.size()) * 0.4;
    n = laik.pazymiai.size();
    sort(laik.pazymiai.begin(), laik.pazymiai.end());
    if (n % 2 == 1) {
        laik.mediana = laik.pazymiai[n / 2];
    }
    else {
        laik.mediana = (laik.pazymiai[(n / 2) - 1] + laik.pazymiai[n / 2]) / 2.0;
    }
    return laik;
}

void isvesk(const vector<Studentas>& grupe) {
    int x; 
    cout << "Jei norite, kad programa isvestu tik studentu vidurkius - iveskite 1, jei norite, kad programa isvestu tik studentu medianas - iveskite 2, jei norite, kad isvestu abi reiksmes - iveskite 3: " << endl; cin >> x;
    if (x == 1) {
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
        cout << string(50, '-') << endl;
        for (auto temp : grupe)
            cout << left << setw(15) << temp.vardas << setw(15) << temp.pavarde << setw(20) << fixed << setprecision(2) << temp.rez << endl;
    }
    else if (x == 2) {
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Med.)" << endl;
        cout << string(50, '-') << endl;
        for (auto temp : grupe)
            cout << left << setw(15) << temp.vardas << setw(15) << temp.pavarde << setw(20) << fixed << setprecision(2) << temp.mediana << endl;
    }
    else {
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
        cout << string(70, '-') << endl;
        for (auto temp : grupe)
            cout << left << setw(15) << temp.vardas << setw(15) << temp.pavarde << setw(20) << fixed << setprecision(2) << temp.rez << setw(20) << fixed << setprecision(2) << temp.mediana << endl;
    }
}