#include "funkcijos.h"

int main()
{
    vector<Studentas> grupe;
    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakai;
    int pasirinkimas;
    string name;
    pasirinkimas = meniu(); // meniu funkcijos iškvietimas
    if (pasirinkimas == 1) {
        int stud;
        cout << "Iveskite keleto studentu duomenis norite ivesti: ";
        stud = tikNr(); // teigiamo skaičiaus funkcijos iškvietimas
        for (int j = 0; j < stud; j++)
        {
            cout << "Iveskite " << j + 1 << " studenta: \n";
            grupe.push_back(ivesk());   // studento duomenų įvesties funkcijos iškvietimas
            cout << string(50, '-') << endl;
        }
    }
    else if (pasirinkimas == 2) {
        cout << "Iveskite failo pavadinima, kuri norime nuskaityti:\n";
        cin >> name;
        NuskaitymasIsFailo(grupe, name);   // failo nuskaitymo funkcijos iškvietimas
        cout << string(50, '-') << endl;
    }
    else if (pasirinkimas == 3) {
        cout << "Iveskite failo pavadinima, kuri norite sugeneruoti:\n";
        cin >> name;
        cout << string(50, '-') << endl;
        FailuGeneravimas(name);
        NuskaitymasIsFailo(grupe, name);   // failo nuskaitymo funkcijos iškvietimas
        StudentuRusiavimas(grupe, vargsiukai, kietiakai);
        IsvedimasIFaila(vargsiukai, "Vargsiukai");
        IsvedimasIFaila(kietiakai, "Kietiakai");
        return 0;
    }
    else {
        cout << "Klaida. ";
        pasirinkimas = tikNr();
    }
    IsvedimasIFaila(grupe, "rezultatai");  // failo įrašymo funkcijos iškvietimas
    return 0;
}
