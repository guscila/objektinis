#include "funkcijos.h"
#include "meniu.h"

MeniuAts meniu()  {    // meniu funkcija grąžinanti naudotojo pasirinkimus
    int ivestis;    // naudotojo įvestis
    string name;
    int cont; // konteinerio pasirinkimas
    int strat;  // strategijos pasirinkimas
    cout << string(21, '-') << " Meniu " << string(22, '-') << endl;
    cout << "1 - ivesti studentu duomenis ir balus rankiniu budu;\n";
    cout << "2 - duomenis nuskaityti is failo;\n";
    cout << "3 - sugeneruoti faila su studentu duomenimis:\n";
    cout << "4 - failu testavimas/spartos analize;\n";
    cout << "Iveskite savo pasirinkima: ";
    while (true) {
        ivestis = tikNr();  // teigiamo skaičiaus funkcijos iškvietimas
        if (ivestis > 4) cout << "Neteisinga ivestis. Bandykite vel: ";
        else break;
    }
    cout << string(50, '-') << endl;
    cout << "Pasirinkite norima naudoti konteineri:\n";
    cout << "1 - vector\n";
    cout << "2 - list\n";
    cout << "Iveskite savo pasirinkima: ";
    while (true) {
        cont = tikNr();  // teigiamo skaičiaus funkcijos iškvietimas
        if (cont > 2) cout << "Neteisinga ivestis. Bandykite vel: ";
        else break;
    }
    cout << string(50, '-') << endl;
    if (ivestis == 1 ) {}
    else if (ivestis == 2) {
        cout << "Iveskite failo pavadinima, kuri norite nuskaityti:\n";
        cin >> name;
        cout << string(50, '-') << endl;
    }
    else if (ivestis == 3) {
        cout << "Iveskite failo pavadinima, kuri norite sugeneruoti:\n";
        cin >> name;
        cout << string(50, '-') << endl;
    }
    else if (ivestis == 4) {
        cout << "Iveskite failo pavadinima, kuri norite nuskaityti:\n";
        cin >> name;
        cout << string(50, '-') << endl;
        cout << "Pasirinkite norima naudoti dalijimo i dvi kategorijas strategija:\n";
        cout << "strategija 1 - studentu skaidymas i du konteinerius;\n";
        cout << "strategija 2 - studentu perkelimas i antra vektoriu;\n";
        cout << "strategija 3 - efektyvi strategija;\n";
        cout << "Iveskite savo pasirinkima: ";
        while (true) {
            strat = tikNr();  // teigiamo skaičiaus funkcijos iškvietimas
            if (strat > 3) cout << "Neteisinga ivestis. Bandykite vel: ";
            else break;
        }
        Container konteineris = (cont == 1) ? Container::Vector : Container::List;
        return MeniuAts{ ivestis, name, konteineris, strat };    // grąžinami naudotojo pasirinkimai/įvestys
    }
    Container konteineris = (cont == 1) ? Container::Vector : Container::List;
    return MeniuAts{ ivestis, name, konteineris};    // grąžinami naudotojo pasirinkimai/įvestys
}

int VienasDu() {    // funkcija patikrai, kad meniu įvestis būtų 1 arba 2
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

int tikNr() {   // funkcija patikrai, kad įvestis yra skaičius didesnis už 0
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

Studentas ivesk() { // studentų įvesties fukcija
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
    if (laik.pazymiai.empty()) {
        laik.rez = laik.egzas * 0.6;    // studento galutinio vidurkio apskaičiavimas
        laik.mediana = 0;
    }
    else {
        laik.rez = laik.egzas * 0.6 + double(sum) / double(laik.pazymiai.size()) * 0.4; // studento galutinio vidurkio apskaičiavimas
        laik.mediana = mediana(laik.pazymiai);  // medianos apskaičiavimo funkcijos iškvietimas
    }
    return laik;
}

template<typename cont>
void NuskaitymasIsFailo(cont& grupe, string name) { // funkcija duomenų nuskaitymui iš failo
    Studentas laik;
    string failas = "C:/Users/ugiri/Desktop/uni/MIF/Obj. programavimas/testavimo failai/" + name + ".txt";  // failo kelio sudarymas
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
    while ((pos = line.find("ND", pos)) != string::npos) {    // veiksmai skaičiuojant kiek namų darbų (ND) pažymių yra faile pagal header eilutę
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
            laik.mediana = 0;
        }
        else {
            laik.rez = laik.egzas * 0.6 + double(sum) / double(laik.pazymiai.size()) * 0.4; // studento galutinio vidurkio apskaičiavimas
            laik.mediana = mediana(laik.pazymiai);  // medianos apskaičiavimo funkcijos iškvietimas
        }
        grupe.push_back(laik);  // studento duomenų įdėjimas į vektorių
    }
    df.close();
    cout << "Failas '" + name + ".txt' sekmingai nuskaitytas.\n";
}

template<typename cont>
void IsvedimasIFaila(cont& grupe, string name) {    // funkcija rezultatų išvedimui į failą
    string failas = "C:/Users/ugiri/Desktop/uni/MIF/Obj. programavimas/testavimo failai/" + name + ".txt";
    ofstream rf(failas);
    cout << string(50, '-') << endl;
    rf << left << setw(17) << "Vardas" << setw(17) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
    for (auto temp : grupe) // studentų duomenų įrašymas į failą
        rf << left << setw(17) << temp.vardas << setw(17) << temp.pavarde << setw(20) << fixed << setprecision(2) << temp.rez << setw(20) << fixed << setprecision(2) << temp.mediana << endl;
    rf.close();
    cout << "Rezultatai sekmingai irasyti i faila '" << name << ".txt' aplanke 'testavimo failai'." << endl;
}

template<typename cont>
void IsvedimasITerminala(cont& grupe) { // funckija rezultatų išvedimui į terminalą
    cout << left << setw(17) << "Vardas" << setw(17) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << setw(20) << "Adresas" << endl;
    for (const auto& temp : grupe) { // studentų duomenų išvedimas į terminalą
        cout << left << setw(17) << temp.vardas << setw(17) << temp.pavarde << setw(20) << fixed << setprecision(2) << temp.rez << setw(20) << fixed << setprecision(2) << temp.mediana << static_cast<const void*>(&temp) << endl;
    }
}

float mediana(vector<int>& pazymiai) {  // medianos apskaičiavimo funkcija
    int nd;
    sort(pazymiai.begin(), pazymiai.end()); // studento namų darbų pažymių vektoriaus surūšiavimas didėjimo tvarka
    nd = pazymiai.size();
    if (nd % 2 == 1) {   // veiksmai ieškant vektoriaus medianos
        return pazymiai[nd / 2];
    }
    else return (pazymiai[(nd / 2) - 1] + pazymiai[nd / 2]) / 2.0;
}

void FailuGeneravimas(string name) {    // studentų duomenų failų generavimo funkcija
    random_device rd;   //
    mt19937 gen(rd());  // "random" engine kodas
    uniform_int_distribution<> dist(1, 10); // random funkcijos algoritmo ribos (1-10)
    string failas;
    int ivestis, nd;
    failas = "C:/Users/ugiri/Desktop/uni/MIF/Obj. programavimas/testavimo failai/" + name + ".txt"; // failo kelio sudarymas
    cout << "Keleto studentu duomenis norite sugeneruoti?:\n";
    ivestis = tikNr();  // teigiamo skaičiaus funkcijos iškvietimas
    cout << string(50, '-') << endl;
    cout << "Iveskite kiek norite sugeneruoti namu darbu pazymiu vienam studentui:\n";
    nd = tikNr();   // teigiamo skaičiaus funkcijos iškvietimas
    Timer generavimas;  // laiko skaičiavimo pradžia
    ofstream rf(failas);
    rf << left << setw(17) << "Vardas" << setw(17) << "Pavarde";
    for (int i = 0; i < nd; i++) {  // failo header eilutės įrašymas į failą
        rf << setw(2) << left << "ND" << setw(3) << left << i + 1;
    }
    rf << setw(6) << "Egz." << endl;
    for (int i = 0; i < ivestis; i++) { // failo duomenų įrašymas į failą
        rf << setw(6) << left << "Vardas" << setw(11) << left << i + 1 << setw(7) << left << "Pavarde" << setw(10) << left << i + 1;
        for (int j = 0; j < nd + 1; j++) {
            rf << setw(5) << dist(gen);
        }
        rf << endl;
    }
    rf.close();
    cout << string(50, '-') << endl;
    cout << "Failas '" << name << ".txt' sekmingai sugeneruotas aplanke 'testavimo failai'.\n";
    cout << "Failo sukurimas uztruko: " << generavimas.elapsed() << " sek.\n";  // laiko skaičiavimo pabaiga
    cout << string(50, '-') << endl;
}

template<typename cont>
void StudentuKategorizacija(cont& grupe, cont& vargsiukai, cont& kietiakai, int strategija) {   // studentų kategorizacijos funkcija į Vargšiukus ir Kietiakus
    if (strategija == 1) {  // Strategija 1
        for (auto temp : grupe) {   // studentų rūšiavimas į vargšiukus ir kietiakus
            if (temp.rez < 5.0) {   // atrenkami "vargšiukai"
                vargsiukai.push_back(temp);
            }
            else if (temp.rez >= 5.0) { // atrenkami "kietiakai
                kietiakai.push_back(temp);
            }
        }
    }
    else if (strategija == 2) { // Strategija 2
        if constexpr (std::is_same_v<cont, std::list<Studentas>>) { // veiksmai su list konteineriu
            for (auto it = grupe.begin(); it != grupe.end();) {
                if (it->rez < 5.0) {    // atrenkami "vargšiukai"
                    vargsiukai.push_back(*it);  // "vargšiukai" įrašomi į naują konteinerį
                    it = grupe.erase(it); // "vargšiukai" pašalinami iš originalaus konteinerio
                }
                else it++;
            }
        }
        else {  // veiksmai su vector konteineriu
            auto it = grupe.begin();
            while (it != grupe.end()) {
                if (it->rez < 5.0) {    // atrenkami "vargšiukai"
                    vargsiukai.push_back(std::move(*it));   // "vargšiukai" perkeliami į naują konteinerį
                    *it = std::move(grupe.back());  //
                    grupe.pop_back();               // užpildoma buvusi "vargšiuko" vieta
                }
                else it++;
            }
        }
    }
    else if (strategija == 3) { // Strategija 3
        auto kietas = [](const Studentas& stud) { return stud.rez >= 5.0; };
        auto atskirtis = std::partition(grupe.begin(), grupe.end(), kietas);    // randama atskirtis tarp "kietiakų" konteinerio priekyje ir "vargšiukų" konteinerio gale
        if constexpr (std::is_same_v<cont, std::list<Studentas>>) { // veiksmai su list konteineriu
            vargsiukai.splice(vargsiukai.end(), grupe, atskirtis, grupe.end()); // "vargšiukai atskiriami į kitą konteinerį
        }
        else {  // veiksmai su vector konteineriu
            vargsiukai.insert(vargsiukai.end(), std::make_move_iterator(atskirtis), std::make_move_iterator(grupe.end()));  // "vargšiukai" perkeliami į kitą konteinerį
            grupe.erase(atskirtis, grupe.end());    // iš originalaus vektoriaus pašalinami visi "vargšiukai"
        }
    }
}

template<typename cont>
void FailuTestavimas(cont& grupe, cont& vargsiukai, cont& kietiakai, string name, int strategija) { // failų greičio spartos analizės funkcija
    Timer skaitymas;    // skaitymo laikmačio pradžia
    NuskaitymasIsFailo(grupe, name);
    skaitymas.save(" irasu failo nuskaitymo trukme: ", grupe.size());   // skaitymo trukmės išsaugojimas
    int originalSize = grupe.size();    // originalaus studentų vektoriaus dydis
    Timer kategorizacija;   // kategorizacijos laikmačio pradžia
    StudentuKategorizacija(grupe, vargsiukai, kietiakai, strategija);
    kategorizacija.save(" irasu failo kategorizacijos trukme: ", originalSize); // kategorizacijos trukmės išsaugojimas
    StudentuRusiavimas(vargsiukai, "Vargsiukai");
    if (strategija == 1) {
        StudentuRusiavimas(kietiakai, "Kietiakai");
    }
    else StudentuRusiavimas(grupe, "Kietiakai");
    Timer isvedimasVarg;    // Vargšiukų išvedimo laikmačio pradžia
    IsvedimasIFaila(vargsiukai, "Vargsiukai");
    isvedimasVarg.save(" Vargsiukai isvedimo trukme: ", vargsiukai.size()); // Vargšiukų išvedimo trukmės išsaugojimas
    Timer isvedimasKiet;    // Kietiakų išvedimo laikmačio pradžia
    if (strategija == 1) {
        IsvedimasIFaila(kietiakai, "Kietiakai");
    }
    else IsvedimasIFaila(grupe, "Kietiakai");
    if (strategija == 1) {
        isvedimasKiet.save(" Kietiakai isvedimo trukme: ", kietiakai.size());    // Kietiakų išvedimo trukmės išsaugojimas
    }
    else     isvedimasKiet.save(" Kietiakai isvedimo trukme: ", grupe.size());    // Kietiakų išvedimo trukmės išsaugojimas
    cout << string(50, '-') << endl;
    cout << string(19, '-') << " Rezultatai " << string(19, '-') << endl;
    cout << '\t' << name << ".txt testavimo laikai:\n";
    Timer::printAll();  // visų laiko trukių išvedimas
    Timer::clearAll();  // laiko trukmių saugyklos išvalymas
}

template<typename cont>
void StudentuRusiavimas(cont& grupe, string name) {    // studentų rūšiavimo funkcija rūšiuojanti studentus pagal naudotojo pasirinkimą
    cout << string(50, '-') << endl;
    cout << "Kaip norite surusiuoti '" << name << ".txt' faila?:\n";
    cout << "1 - rusiuoti faila pagal varda/pavarde abeceles didejimo tvarka;\n";
    cout << "2 - rusiuoti faila pagal varda/pavarde abeceles mazejimo tvarka;\n";
    cout << "3 - rusiuoti faila pagal galutini vidurki didejimo tvarka;\n";
    cout << "4 - rusiuoti faila pagal galutini vidurki mazejimo tvarka;\n";
    cout << "5 - failo nerusiuoti;\n";
    cout << "Iveskite savo pasirinkima: ";
    int ivestis;
    while (true) {
        ivestis = tikNr();  // teigiamo skaičiaus funkcijos iškvietimas
        if (ivestis > 5) cout << "Neteisinga ivestis. Bandykite vel: ";
        else break;
    }
    Timer rusiavimas;
    if constexpr (is_same_v<cont, list<Studentas>>) {  // veiksmai su list konteineriu
        if (ivestis == 1) {
            grupe.sort([](auto& stud1, auto& stud2) { return stud1.vardas < stud2.vardas; });   // veiksmai studentus surušiuojant abecelės didėjimo tvarka
        }
        else if (ivestis == 2) {
            grupe.sort([](auto& stud1, auto& stud2) { return stud1.vardas > stud2.vardas; });   // veiksmai studentus surušiuojant abecelės mažėjimo tvarka
        }
        else if (ivestis == 3) {
            grupe.sort([](auto& stud1, auto& stud2) { return stud1.rez < stud2.rez;    });  // veiksmai studentus surušiuojant pagal galutinį vidurkį didėjimo tvarka
        }
        else if (ivestis == 4) {
            grupe.sort([](auto& stud1, auto& stud2) { return stud1.rez > stud2.rez;    });  // veiksmai studentus surušiuojant pagal galutinį vidurkį mažėjimo tvarka
        }
    }
    else {  // veiksmai su vector konteineriu
        if (ivestis == 1) {
            stable_sort(grupe.begin(), grupe.end(), [](const Studentas& stud1, const Studentas& stud2) {   // veiksmai studentus surušiuojant abecelės didėjimo tvarka
                return stud1.vardas < stud2.vardas;
                });
        }
        else if (ivestis == 2) {
            stable_sort(grupe.begin(), grupe.end(), [](const Studentas& stud1, const Studentas& stud2) {   // veiksmai studentus surušiuojant abecelės mažėjimo tvarka
                return stud1.vardas > stud2.vardas;
                });
        }
        else if (ivestis == 3) {
            stable_sort(grupe.begin(), grupe.end(), [](const Studentas& stud1, const Studentas& stud2) {   // veiksmai studentus surušiuojant pagal galutinį vidurkį didėjimo tvarka
                return stud1.rez < stud2.rez;
                });
        }
        else if (ivestis == 4) {
            stable_sort(grupe.begin(), grupe.end(), [](const Studentas& stud1, const Studentas& stud2) {   // veiksmai studentus surušiuojant pagal galutinį vidurkį mažėjimo tvarka
                return stud1.rez > stud2.rez;
                });
        }
    }
    string text = " irasu " + name + " surusiavimo trukme: ";
    rusiavimas.save(text, grupe.size());
}