#include "funkcijos.h"

int main()
{
    vector<Studentas> grupe;
    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakai;
    int pasirinkimas;
    string name;
    auto ivestis = meniu();
    pasirinkimas = ivestis.first; // meniu funkcijos iškvietimas
    name = ivestis.second;
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
        cout << string(50, '-') << endl;
        NuskaitymasIsFailo(grupe, name);   // failo nuskaitymo funkcijos iškvietimas
    }
    else if (pasirinkimas == 3) {
        cout << string(50, '-') << endl;
        FailuGeneravimas(name);
        NuskaitymasIsFailo(grupe, name);   // failo nuskaitymo funkcijos iškvietimas
        StudentuRusiavimas(grupe, vargsiukai, kietiakai);
        IsvedimasIFaila(vargsiukai, "Vargsiukai");
        IsvedimasIFaila(kietiakai, "Kietiakai");
        return 0;
    }
    IsvedimasIFaila(grupe, "rezultatai");  // failo įrašymo funkcijos iškvietimas
    return 0;
}
