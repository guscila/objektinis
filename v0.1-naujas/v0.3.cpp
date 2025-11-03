#include "funkcijos.h"

int main()
{
    auto m = meniu();   // meniu funkcijos iškvietimas
    int pasirinkimas = m.pasirinkimas;   // naudotojo meniu pasirinkimas
    string name = m.name;    // failo pavadinimas
    if (m.konteineris == Container::List) { // veiksmai su list konteineriu
        list<Studentas> grupe, vargsiukai, kietiakai;
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
            IsvedimasITerminala(grupe);  // duomenų išvedimo į terminalą funkcijos iškvietimas
        }
        else if (pasirinkimas == 2) {
            cout << string(50, '-') << endl;
            NuskaitymasIsFailo(grupe, name);   // failo nuskaitymo funkcijos iškvietimas
            IsvedimasIFaila(grupe, "rezultatai");  // failo įrašymo funkcijos iškvietimas
            return 0;
        }
        else if (pasirinkimas == 3) {
            cout << string(50, '-') << endl;
            FailuGeneravimas(name); // failo generavimo funkcijos iškvietimas
            return 0;
        }
        else if (pasirinkimas == 4) {
            FailuTestavimas(grupe, vargsiukai, kietiakai, name);    // failų testavimo funkcijos iškvietimas
            return 0;
        }
        return 0;
    }
    else {  // veiksmai su vector konteineriu
        vector<Studentas> grupe, vargsiukai, kietiakai;
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
            IsvedimasITerminala(grupe);  // duomenų išvedimo į terminalą funkcijos iškvietimas
        }
        else if (pasirinkimas == 2) {
            cout << string(50, '-') << endl;
            NuskaitymasIsFailo(grupe, name);   // failo nuskaitymo funkcijos iškvietimas
            IsvedimasIFaila(grupe, "rezultatai");  // failo įrašymo funkcijos iškvietimas
            return 0;
        }
        else if (pasirinkimas == 3) {
            cout << string(50, '-') << endl;
            FailuGeneravimas(name); // failo generavimo funkcijos iškvietimas
            return 0;
        }
        else if (pasirinkimas == 4) {
            FailuTestavimas(grupe, vargsiukai, kietiakai, name);    // failų testavimo funkcijos iškvietimas
            return 0;
        }
        return 0;
    }
}
