#include "funkcijos.h"

int main()
{
    vector<Studentas> grupe;    // visu studentų vektorius
    vector<Studentas> vargsiukai;   // vargsiuku studentu (rez < 5) vektorius
    vector<Studentas> kietiakai;    // kieteku studentu (rez >= 5) vektorius
    int pasirinkimas;   // naudotojo meniu pasirinkimas
    string name;    // failo pavadinimas
    auto ivestis = meniu(); // meniu funkcijos iškvietimas
    pasirinkimas = ivestis.first;
    name = ivestis.second;
    if (pasirinkimas == 1) {
        int stud;
        cout << "Iveskite keliu studentu duomenis norite ivesti: ";
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
        FailuGeneravimas(name); // failo generavimo funkcijos iškvietimas
        NuskaitymasIsFailo(grupe, name);   // failo nuskaitymo funkcijos iškvietimas
        StudentuRusiavimas(grupe, vargsiukai, kietiakai);   // studentų rūšiavimo į vargšiukus ir kietekus funkcijos iškvietimas
        IsvedimasIFaila(vargsiukai, "Vargsiukai");  // vargšiukų išvedimas į failą
        IsvedimasIFaila(kietiakai, "Kietiakai");    // kietekų išvedimas į failą
        return 0;
    }
    else if (pasirinkimas == 4) {
        FailuTestavimas(grupe, vargsiukai, kietiakai, name);    // failų testavimo funkcijos iškvietimas
        return 0;
    }
    IsvedimasIFaila(grupe, "rezultatai");  // failo įrašymo funkcijos iškvietimas
    return 0;
}
