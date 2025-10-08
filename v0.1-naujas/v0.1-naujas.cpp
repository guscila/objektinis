
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

struct Studentas {  // studento struktūra
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzas;
    float rez;
    float mediana;
    string kategorija;
};

int meniu();    // meniu funkcija
int VienasDu(); // funkcija patikrai, kad meniu įvestis būtų 1 arba 2
int tikNr();    // funkcija patikrai, kad įvestis yra skaičius didesnis už 0
Studentas ivesk();  // studentų įvesties fukcija
void NuskaitymasIsFailo(vector<Studentas>& grupe, string name);   // funkcija duomenų nuskaitymui iš failo
void IsvedimasIFaila(vector<Studentas>& grupe, string name);  // funkcija rezultatų išvedimui į failą
float mediana(vector<int>& pazymiai);   // medianos apskaičiavimo funkcija
void FailuGeneravimas(string name);
void StudentuRusiavimas(const vector<Studentas>& grupe, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai);


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

int meniu() {
    int ivestis;
    cout << string(21, '-') << " Meniu " << string(22, '-') << endl;
    cout << "1 - ivesti studentu duomenis ir balus rankiniu budu;\n";
    cout << "2 - duomenis nuskaityti is failo;\n";
    cout << "3 - sugeneruoti studentu duomenis i failus:\n";
    cout << "Iveskite savo pasirinkima: ";
    while (true) {
        ivestis = tikNr();  // teigiamo skaičiaus funkcijos iškvietimas
        if (ivestis > 3) cout << "Neteisinga ivestis. Bandykite vel: ";
        else break;
    }
    cout << string(50, '-') << endl;
    return ivestis;
}

int VienasDu() {
    int ivestis;
    cout << "Iveskite, savo pasirinkima: "; cin >> ivestis;
    while (true) {
        if (cin.fail()) {   // veiksmai jei įvestis žodinio tipo
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Neteisinga ivestis. Iveskite skaiciu 1 arba 2: "; cin >> ivestis;
        }
        else if (ivestis == 1 || ivestis == 2) return ivestis;
        else {  // veiksmai jei skaičiai nėra 1 arba 2
            cout << "Neteisinga ivestis. Iveskite skaiciu 1 arba 2: "; cin >> ivestis;
        }
    }
}

int tikNr() {
    int ivestis;
    cin >> ivestis;
    while (true) {
        if (cin.fail() || ivestis <= 0) { // veiksmai jei įvestis žodinio tipo arba <= 0
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Neteisinga ivestis. Bandykite vel: "; cin >> ivestis;
        }
        else return ivestis;
    }
}

Studentas ivesk() {
    Studentas laik;
    int sum = 0, nd, paz, pasirinkimas; // sum - studento pažymių suma; nd - studento pažymių kiekis; paz - įvedamas pažymys 
    string ivestis; // ivestis naudojama rankiniu budu ivedant namu darbu pazymius
    random_device rd;   //
    mt19937 gen(rd());  // "random" engine kodas
    uniform_int_distribution<> dist(1, 10); // random funkcijos algoritmo ribos (1-10)
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> laik.vardas >> laik.pavarde;
    cout << string(50, '-') << endl;
    cout << "1 - ivesti namu darbu pazymius ir egzamino bala rankiniu budu;\n";
    cout << "2 - studento pazymius sugeneruoti atsitiktinai;\n";
    pasirinkimas = VienasDu();  // įvesties patikros (1 arba 2) funkcijos iškvietimas
    cout << string(50, '-') << endl;
    if (pasirinkimas == 1) {   // veiksmai, jei naudotojas pasirinko duomenis įvesti rankiniu būdu
        cout << "Iveskite studento namu darbu pazymius, kai noresite sustoti iveskite zodi 'baigta':" << endl;
        while (true) {
            cin >> ivestis;
            if (ivestis == "baigta") break;
            try {
                paz = stoi(ivestis);    // įvestis paverčiama iš string į int tipo kintamąjį
                if (paz >= 1 && paz <= 10) {  // patikra, kad įvestas pažymys yra dešimbalėje skalėje
                    laik.pazymiai.push_back(paz);
                    sum += paz;
                }
                else {
                    cout << "Neteisinga ivestis. Iveskite pazymi 1-10 skaleje, o jei norite baigti, iveskite zodi 'baigta':" << endl;
                }
            }
            catch (...) {   // klaidingos įvesties apsauga, jei įvestis neteisinga
                cout << "Neteisinga ivestis. Iveskite skaiciu 1-10 skaleje, o jei norite baigti, iveskite zodi 'baigta':" << endl;
            }
        }
        cout << "Iveskite egzamino bala: ";
        int egzas;  // egzas - studento egzamino balas;
        egzas = tikNr();    // teigiamo skaičiaus funkcijos iškvietimas
        while (egzas < 1 || egzas > 10) {       // patikra, kad įvestas egzamino balas yra dešimbalėje skalėje
            cout << "Neteisinga ivestis. Iveskite egzamino bala 1-10 skaleje: ";
            egzas = tikNr();    // teigiamo skaičiaus funkcijos iškvietimas
        }
        laik.egzas = egzas;
    }
    else if (pasirinkimas == 2) {  // veiksmai, jei naudotojas pasirenka, kad duomenys būtų generuojami atsitiktinai
        int nd; // nd - studento pazymiu kiekis;
        cout << "Iveskite kiek studento namu darbu pazymiu norite atsitiktinai sugeneruoti: ";
        nd = tikNr();   // teigiamo skaičiaus funkcijos iškvietimas
        for (int i = 0; i < nd; i++) {  // veiksmai generuojant studento namų darbų pažymius atsitiktinai
            paz = dist(gen);
            laik.pazymiai.push_back(paz);
            sum += paz;
        }
        laik.egzas = dist(gen); // studento egzamino balo sugeneravimas atsitiktinai
    }
    laik.rez = laik.egzas * 0.6 + double(sum) / double(laik.pazymiai.size()) * 0.4; // studento galutinio vidurkio apskaičiavimas
    laik.mediana = mediana(laik.pazymiai);  // medianos apskaičiavimo funkcijos iškvietimas
    return laik;
}

void NuskaitymasIsFailo(vector<Studentas>& grupe, string name) {
    Studentas laik;
    string failas = "C:/Users/ugiri/Desktop/uni/MIF/Obj. programavimas/testavimo failai/" + name + ".txt";
    ifstream df(failas);
    if (!df) {
        cout << string(50, '-') << endl;
        cout << "Ivyko klaida atidarant faila arba failas neegzistuoja.\n";
        exit(0);
    }
    string line, word;  // line - nuskaitoma failo eilutė; word - objektai į kuriuos suskirstoma eilutė
    getline(df, line);
    int nd = 0; // nd - studento pažymių kiekis;
    size_t pos = 0;
    while ((pos = line.find("ND", pos)) !=string::npos) {    // veiksmai skaičiuojant kiek namų darbų (ND) pažymių yra faile pagal header eilutę
        nd++;
        pos += 2;
    }
    while (getline(df, line)) {
        stringstream ss(line);  // nuskaityta eilutė padalinama į word objektus
        laik.pazymiai.clear();  // pažymių vektoriaus išvalymas
        ss >> laik.vardas >> laik.pavarde;  // nuskaitomi studento vardas ir pavardė
        int sum = 0, paz;   // sum - studento pažymių suma; paz - įvedamas pažymys
        for (int i = 0; i < nd; i++) {  // nuskaitomi namų darbų pažymiai
            ss >> paz;
            laik.pazymiai.push_back(paz);
            sum += paz;
        }
        ss >> laik.egzas;   // nuskaitomas egzamino balas
        if (laik.pazymiai.empty()) {
            laik.rez = laik.egzas * 0.6;    // studento galutinio vidurkio apskaičiavimas
        }
        else {
            laik.rez = laik.egzas * 0.6 + double(sum) / double(laik.pazymiai.size()) * 0.4; // studento galutinio vidurkio apskaičiavimas
        }
        laik.mediana = mediana(laik.pazymiai);  // medianos apskaičiavimo funkcijos iškvietimas
        if (laik.rez < 5) {
            laik.kategorija = "vargsiukas";
        }
        else if (laik.rez>=5) {
            laik.kategorija = "kietiakas";
        }
        grupe.push_back(laik);  // studento duomenų įdėjimas į vektorių
    }
    df.close();
    cout << "Failas '" + name + ".txt' sekmingai nuskaitytas.\n";
}

void IsvedimasIFaila(vector<Studentas>& grupe, string name) {
    string failas = "C:/Users/ugiri/Desktop/uni/MIF/Obj. programavimas/testavimo failai/" + name + ".txt";
    ofstream rf(failas);
    sort(grupe.begin(), grupe.end(), [](const Studentas& stud1, const Studentas& stud2) {   // veiksmai studentus surušiuojant abecelės tvarka
        return stud1.vardas < stud2.vardas;
        });
    rf << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
    for (auto temp : grupe) // studentų duomenų įrašymas į failą
        rf << left << setw(15) << temp.vardas << setw(15) << temp.pavarde << setw(20) << fixed << setprecision(2) << temp.rez << setw(20) << fixed << setprecision(2) << temp.mediana << endl;
    rf.close();
    cout << "Rezultatai sekmingai irasyti i faila '" << name << ".txt' aplanke 'testavimo failai'." << endl;
}

float mediana(vector<int>& pazymiai) {
    int nd;
    sort(pazymiai.begin(), pazymiai.end()); // studento namų darbų pažymių vektoriaus surūšiavimas didėjimo tvarka
    nd = pazymiai.size();
    if (nd % 2 == 1) {   // veiksmai ieškant vektoriaus medianos
        return pazymiai[nd / 2];
    }
    else return (pazymiai[(nd / 2) - 1] + pazymiai[nd / 2]) / 2.0;
}

void FailuGeneravimas (string name){
    random_device rd;   //
    mt19937 gen(rd());  // "random" engine kodas
    uniform_int_distribution<> dist(1, 10); // random funkcijos algoritmo ribos (1-10)
    string failas;
    int ivestis, nd;
    failas = "C:/Users/ugiri/Desktop/uni/MIF/Obj. programavimas/testavimo failai/" + name + ".txt";
    cout << "Keleto studentu duomenis norite sugeneruoti?:\n";
    ivestis = tikNr();
    cout << string(50, '-') << endl;
    cout << "Iveskite kiek norite sugeneruoti namu darbu pazymiu vienam studentui:\n";
    nd = tikNr();
    ofstream rf(failas);
    rf << left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    for (int i = 0; i < nd; i++) {
        rf << setw(2) << left << "ND" << setw(3) << left << i + 1;
    }
    rf << setw(6) << "Egz." << endl;
    for (int i = 0; i < ivestis; i++) {
        rf << setw(6) << left << "Vardas" << setw(9) << left << i+1 << setw(7) << left << "Pavarde" << setw(8) << left << i+1;
        for (int j = 0; j < nd+1; j++) {
            rf << setw(5) << dist(gen);
        }
        rf << endl;
    }
    rf.close();
    cout << string(50, '-') << endl;
    cout << "Failas '" << name << ".txt' sekmingai sugeneruotas aplanke 'testavimo failai'.\n";
}

void StudentuRusiavimas(const vector<Studentas>& grupe, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai) {
    for (auto temp : grupe) {
        if (temp.kategorija == "vargsiukas") {
            vargsiukai.push_back(temp);
        }
        else if (temp.kategorija == "kietiakas") {
            kietiakai.push_back(temp);
        }
    }
}