# v0.1

## Programos aprašymas
Programa leidžia naudotojui apskaičiuoti studentų galutinius balus pagal formulę ( *pav.1* ) ir pagal studento namų darbų medianą ( *code.1* ). Duomenis galima įvesti ranka, sugeneruoti atsitiktinai, arba nuskaityti iš failo. Galutiniai rezultatai yra išvedami į failą *"rezultatai.txt"*. <br>
<br>
*Pav.1:* <br> ![pav.1](https://latex.codecogs.com/svg.image?&space;Galutinis=0.4*vidurkis&plus;0.6*egzaminas)<br>
*Code.1:*
```c++
vector<int>& pazymiai;
int nd;
sort(pazymiai.begin(), pazymiai.end()); // studento namų darbų pažymių vektoriaus surūšiavimas didėjimo tvarka
nd = pazymiai.size();
if (nd % 2 == 1) {   // veiksmai ieškant vektoriaus medianos
    return pazymiai[nd / 2];
}
else return (pazymiai[(nd / 2) - 1] + pazymiai[nd / 2]) / 2.0;
```
## Programos failai:
### Programos įvesties failų formatas:
Vardas1 / Pavarde1 / ND1 / ND2 / ... / Egz. <br>
Jonas / Jonaitis / 8 / 9 / ... / 9 <br>
### Programos rezultatų išvedimo (*"rezultatai.txt"*) formatas:
Vardas1 / Pavarde1 / Galutinis(Vid.) / Galutinis(Med.) <br>
Jonas / Jonaitis / 7.8 / 8.0 <br>
### Programoje testuoti failai:
"studentai10000.txt" - 10 tūkst. studentų <br>
"studentai100000.txt" - 100 tūkst. studentų <br>
"studentai1000000.txt" - 1 mln. studentų <br>
#
### Komentaras:
```
Atliekant šią užduotį kilo problemų su didelės talpos duomenų failais. Dėl šios problemos išsitrynė pagrindinė "master" šaka bei v0.1 projektas perkeltas į "v0.1-nauja" šaką. Taip pat dėl šios priežasties relizas išleistas pavėluotai, o "v0.1-nauja" šaka neturi reikalaujamo commit'ų kiekio.
