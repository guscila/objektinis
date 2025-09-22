
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;

struct Studentas {
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzas;
    float rez;
};

Studentas ivesk();

int main()
{
    vector<Studentas> grupe;
    for (int j = 0; j < 3; j++)
    {
        cout << "Iveskite " << j + 1 << " studenta: \n";
        grupe.push_back(ivesk());
    }
    for (auto temp :grupe)
    cout << temp.vardas << " | " << temp.pavarde << " | " << temp.rez << endl;
    return 0;
}

Studentas ivesk() {
    Studentas laik;
    int sum = 0, n, paz;
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> laik.vardas >> laik.pavarde;
    cout << "Kiek pazymiu turi studentas?:"; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Iveskite " << i + 1 << " pazymi is " << n << ": ";
        cin >> paz;
        laik.pazymiai.push_back(paz);
        sum += paz;
    }
    cout << "Iveskite egzamino bala: "; cin >> laik.egzas;
    laik.rez = laik.egzas * 0.6 + double(sum) / double(laik.pazymiai.size()) * 0.4;
    return laik;
}