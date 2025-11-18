# 1Lab.
v1.0 release
## Programos aprašymas
Programa leidžia naudotojui įvesti rankiniu būdu arba nuskaityti studentų duomenis ( vardą ir pavardę, atliktų namų darbų rezultatus (10-balėje sistemoje), egzamino balą ) ir suskaičiuoja galutinį balą pagal formulę ( *pav.1* ). Visos programos veikimo metu naudotojas gali pasirinkti kokio tipo ( vector ar list ) konteineris bus naudojamas. Įvesdamas duomenis rankiniu būdu naudotojas gali namų darbų ir egzamino rezultatuts įvesti arba atsitiktinai sugeneruoti. Naudotojui taip pat leidžiama sugeneruoti failą su studentų vardais, namų darbų ir egzamino rezultatais, kurį vėliau gali naudoti programos testavimo funkcijos metu. Failų testavimo metu, naudotojui pasirinkus failą, yra atliekama greičio spartos analizė naudojant vieną iš trijų studentų kategorizacijos strategijų bei suteikiant naudotojui pasirinkimą kokia tvarka bus surūšiuoti studentų *'Kietiakų'<sup>1</sup>* ir *'Vargšiukų'<sup>2</sup>* failai.
```
1 - Kietiakas - tai studentas, kurio galutinis vidurkis >=5;
2 - Vargšiukas - tai studentas, kurio galutinis vidurkis < 5;
```
*Pav.1:* ![pav.1](https://latex.codecogs.com/svg.image?&space;Galutinis=0.4*vidurkis&plus;0.6*egzaminas)<br>
## Programos diegimo instrukcija
1. Nukopijuokite projekto direktoriją ir paruošiame "build" direktoriją, kur nukeliaus visi mūsų sukurti failai:
```
cd projekto_direktorija
mkdir build
cd build
```
2. Sugeneruojame projekto failus naudodami CMake:
```
cmake ..
(čia naudojame "cmake ..", nes "CMakeLists.txt" failas yra aukštesnio lygio aplanke)
```
3. Kompliuojame programą Release režimu:
```
cmake --build . --config Release
```
4. Paleidžiame sukurtą programą:
```
.\v1.0.exe
```
#### Arba galite paleisti šiame projekte prikabintą `run.bat` failą:
```run.bat``` failą galite paleisti paspaudę ant jo du kartus arba terminale įvedę komandą:
```
.\run.bat
```
## Programos naudojimo instrukcija
1. Įdiekite programą.
2. Programai pradėjus veikti, naudotojas pasirenka iš Meniu norimą naudoti funkciją ir toliau seka Meniu aprašytais nurodymais.
### Meniu
* 1 - Įvesti studentų duomenis rankiniu būdu;<br>
  * 1.1 - Pasirinkti norimą naudoti konteinerį ( vector arba list );<br>
* 2 - Studentų duomenis nuskaityti iš failo;<br>
  * 2.1 - Pasirinkti norimą naudoti konteinerį ( vector arba list );<br>
    * 2.1.1 - Įvesti failo pavadinimą, kurį norite nuskaityti;<br>
* 3 - Sugeneruoti failą su studentų duomenimis;<br>
  * 3.1 - Pasirinkti norimą naudoti konteinerį ( vector arba list );<br>
    * 3.1.1 - Įvesti failo pavadinimą, kurį norite sugeneruoti;<br>
* 4 - Atlikti failų testavimą/sparto analizę;<br>
  * 4.1 - Pasirinkti norimą naudoti konteinerį ( vector arba list );<br>
    * 4.1.1 - Įvesti failo pavadinimą, kurį norite nuskaityti;<br>
      * 4.1.1.1 - Pasirinkti norimą naudoti studentų kategorizacijos strategiją (1, 2 arba 3);<br>
3. Programa nustoja veikti, kai yra išvedami rezultatai arba išvedama teksinė/informacinė eilutė, po vieno iš šių įvykių paspaudus bet kurį klaviatūros klavišą programa užsidaro.

## Ankstesnės versijos
[v0.1](https://github.com/guscila/objektinis/tree/v0.1-nauja)<br>
```
Dėl techninių nesklandumų įvykusių bandant įkelti didelio formato failus v0.1 yra v0.1-nauja šakoje bei trūksta dalies įvykdytų commit'ų.
```
#### [v0.2](https://github.com/guscila/objektinis/tree/v0.2) pokyčiai:
Versija v0.1 optimizuota ir papildyta funkcija leidžiančia naudotojui sugeneruoti studentų duomenų failus; pridėta failų spartos analizės funkcija; pridėta funkcija leidžianti naudotojui pasirinkti išvedimo failo rūšiavimo parametrą; struktūros bei funkcijos perkeltos į atskirus failus; sutvarkytas meniu; funkcijoms suteikti aiškesni pavadinimai.
#### [v0.3](https://github.com/guscila/objektinis/tree/v0.3) pokyčiai:
Versija v0.2 optimizuota ir papildyta galimybe pasirinkti norimą naudoti konteinerį; programa papildyta funkcija leidžiančia įvestų studentų duomenis išvesti į terminalą bei pateikianti jų saugojimo atmintyje adresus; programa papildyta Meniu struktūra ir detalesniu pasirinkimu; Timer'is papildytas saugojimo bei visų laiko trukmių išvedimo funkcijomis; failų spartos analizės funkcija papildyta studentų kategorizacijos bei išvedimo į failus spartos apskaičiavimu.
#### [v1.0](https://github.com/guscila/objektinis/tree/v1.0) pokyčiai:
Versija v0.3 optimizuota ir papildyta funkcija leidžiančiau naudotojui pasirinkti norimą naudoti studentų kategorizacijos strategiją; parengta įdiegimo instrukcija su `CMakeLists.txt` ir `run.bat`.

## Programos failai
### Failai
* v1.0 - pagrindinis programos failas;
* funkcijos.h - programos funkcijų header'ių failas;
* meniu.h - meniu struktūros failas;
* studentas.h - studento struktūros failas;
* Timer.h - laiko skaičiavimo funkcijos Timer failas;
* mylib.cpp - programos funkcijų failas;
* CMakeLists.txt - programos įdiegimo instrukcijos failas;
* run.bat - programos paleidimo failas;

### Programos įvesties/generavimo failų formatas:
| Vardas1 | Pavarde1 | ND1 | ND2 | ... | Egz. |
|:--------|:---------|:----|:----|:----|:-----|
| Jonas | Jonaitis | 8 | 9 | ... | 9 |
##### Komentaras:
```
Visi programa sugeneruoti failai buvo sukurti su 5 namų darbų pažymiais studentui.
```
### Programos išvedimo failų formatas:
| Vardas1 | Pavarde1 | Galutinis(Vid.) | Galutinis(Med.) |
|:--------|:---------|:----------------|:----------------|
| Jonas | Jonaitis | 7.80 | 8.00 |
### Programos rezultatų terminale formatas:
| Vardas1 | Pavarde1 | Galutinis(Vid.) | Galutinis(Med.) | Adresas |
|:--------|:---------|:----------------|:----------------|:--------|
| Jonas | Jonaitis | 7.80 | 8.00 | 0000000000A000A0 |
### Programos greičio spartos analizės rezultatų išvedimo formatas:
![rezultatųformatas](foto/rezultatupvz.png)
### Programa testuoti failai:
* Užduotyje pateikti failai:
  * "studentai10000.txt" - 10 tūkst. studentų <br>
  * "studentai100000.txt" - 100 tūkst. studentų <br>
  * "studentai1000000.txt" - 1 mln. studentų <br>
* Programos sugeneruoti failai:
  * "1000studentu.txt" - 1 tūkst. studentų <br>
  * "10000studentu.txt" - 10 tūkst. studentų <br>
  * "100000studentu.txt" - 100 tūkst. studentų <br>
  * "1000000studentu.txt" - 1 mln. studentų <br>
  * "10000000studentu.txt" - 10 mln. studentų <br>
### Testavimo sistemos parametrai:
CPU: 11th Gen Intel(R) Core(TM) i5-1135G7 @ 2.40GHz (2.42 GHz) <br>
RAM: 8.00 GB <br>
HDD: SSD 238 GB <br>
## Greičio spartos analizė:
### Strategijos:
* Strategija 1 - Bendro studentų konteinerio kategorizacija į du naujus konteinerius: *'Kietiakai'<sup>1</sup>* ir *'Vargšiukai'<sup>2</sup>*.
* Strategija 2 - Bendro studentų konteinerio kategorizacija panaudojant tik vieną naują konteinerį: *'Vargšiukai'<sup>2</sup>*.
* Strategija 3 - Efektyvioji strategija paremta Strategija 2 bei naudojanti algoritmus siekiant optimizuoti kategorizaciją.
### Studentų kategorizacijos strategijų testavimas:
#### Strategija 1
| Failas                 | Vector   | List     |
|:-----------------------|:---------|:---------|
| studentai10000.txt     | 0,004 s  | 0,003 s  |
| studentai100000.txt    | 0,038 s  | 0,030 s  |
| studentai1000000.txt   | 0,391 s  | 0,282 s  |
|                        |          |          |
| 1000studentu.txt       | 0,0004 s | 0,0003 s |
| 10000studentu.txt      | 0,008 s  | 0,002 s  |
| 100000studentu.txt     | 0,034 s  | 0,034 s  |
| 1000000studentu.txt    | 0,422 s  | 0,310 s  |
| 10000000studentu.txt   | 7,633 s  | 8,811 s  |

#### Strategija 2
| Failas                 | Vector   | List     |
|:-----------------------|:---------|:---------|
| studentai10000.txt     | 0,001 s  | 0,001 s  |
| studentai100000.txt    | 0,008 s  | 0,005 s  |
| studentai1000000.txt   | 0,232 s  | 0,060 s  |
|                        |          |          |
| 1000studentu.txt       | 0,0001 s | 0,0001 s |
| 10000studentu.txt      | 0,001 s  | 0,001 s  |
| 100000studentu.txt     | 0,011 s  | 0,006 s  |
| 1000000studentu.txt    | 0,103 s  | 0,061 s  |
| 10000000studentu.txt   | 1,115 s  | 0,755 s  |
```
Išvados: Pirmų dviejų studentų kategorizacijos strategijų spartos panašios, tačiau antroji šiek tiek spartesnė už pirmąją. Antrosios strategijos pagrindu buvo sukurta trečioji strategija.
```
#### Strategija 3
| Failas                 | Vector    | List        |
|:-----------------------|:----------|:------------|
| studentai10000.txt     | 0,0002 s  | 0,00009 s   |
| studentai100000.txt    | 0,003 s   | 0,009 s     |
| studentai1000000.txt   | 0,040 s   | 0,116 s     |
|                        |           |             |
| 1000studentu.txt       | 0,00003 s | 0,0001 s    |
| 10000studentu.txt      | 0,0002 s  | 0,001 s     |
| 100000studentu.txt     | 0,004 s   | 0,012 s     |
| 1000000studentu.txt    | 0,036 s   | 0,134 s     |
| 10000000studentu.txt   | 0,425 s   | 1,350 s     |
### Studentų kategorizacijos strategijų testavimo išvados:
Pritaikius `std::partition` ir `std::make_move_iterator` algoritmus buvo sukurta Strategija 3 paremta antrosios strategijos pagrindu. Trečioji strategija yra spartesnė ir efektyvesnė dirbant su vektoriaus tipo konteineriais, tačiau susiduria su sunkumais dirbant su didesniais failais. Nepaisant to, Strategija 3 yra efektyviausia iš visų testuotų strategijų. 
```
Studentų kategorizacijos strategijų testavimas buvo atliktas naudojant v1.0 realizaciją.
```
### Testavimo laikai veiksmus atliektant su vektoriaus (vector) konteineriu:
| Failas                 | Failo sukūrimas | Duomenų nuskaitymas | Studentų kategorizacija | *'Kietiakų'<sup>1</sup>* rūšiavimas | *'Vargšiukų'<sup>2</sup>* rūšiavimas | Išvedimas į failą (*'Kietiakai'<sup>1</sup>*)  | Išvedimas į failą (*'Vargšiukai'<sup>2</sup>*) |
|:-----------------------|:----------------|:--------------------|:------------------------|:------------------------------------|:-------------------------------------|:-----------------------------------------------|:-----------------------------------------------|
| studentai10000.txt     | -               | 0,055 s             | 0,003 s                 | 0,004 s                             | 0,001 s                              | 0,023 s                                        | 0,018 s                                        |
| studentai100000.txt    | -               | 0,658 s             | 0,026 s                 | 0,014 s                             | 0,008 s                              | 0,226 s                                        | 0,155 s                                        |
| studentai1000000.txt   | -               | 3,080 s             | 0,249 s                 | 0,256 s                             | 0,179 s                              | 2,228 s                                        | 1,523 s                                        |
|                        |                 |                     |                         |                                     |                                      |                                                |                                                |
| 1000studentu.txt       | 0.011 s         | 0,0045 s            | 0,0003 s                | 0,0001 s                            | 0,0001 s                             | 0,0036 s                                       | 0,0037 s                                       |
| 10000studentu.txt      | 0.043 s         | 0,023 s             | 0,003 s                 | 0,001 s                             | 0,001 s                              | 0,022 s                                        | 0,018 s                                        |
| 100000studentu.txt     | 0.435 s         | 0,235 s             | 0,022 s                 | 0,013 s                             | 0,009 s                              | 0,216 s                                        | 0,148 s                                        |
| 1000000studentu.txt    | 4.323 s         | 2,248 s             | 0,241 s                 | 0,26 s                              | 0,179 s                              | 2,672 s                                        | 1,579 s                                        |
| 10000000studentu.txt   | 42.89 s         | 22,458 s            | 3,067 s                 | 3,213 s                             | 2,09 s                               | 25,029 s                                       | 15,467 s                                       |
<br>

### Testavimo laikai veiksmus atliektant su sąrašo (list) konteineriu:
| Failas                 | Failo sukūrimas | Duomenų nuskaitymas | Studentų kategorizacija | *'Kietiakų'<sup>1</sup>* rūšiavimas | *'Vargšiukų'<sup>2</sup>* rūšiavimas | Išvedimas į failą (*'Kietiakai'<sup>1</sup>*)  | Išvedimas į failą (*'Vargšiukai'<sup>2</sup>*) |
|:-----------------------|:----------------|:--------------------|:------------------------|:------------------------------------|:-------------------------------------|:-----------------------------------------------|:-----------------------------------------------|
| studentai10000.txt     | -               | 0,054 s             | 0,002 s                 | 0,001 s                             | 0,001 s                              | 0,025 s                                        | 0,018 s                                        |
| studentai100000.txt    | -               | 0,443 s             | 0,022 s                 | 0,013 s                             | 0,009 s                              | 0,22 s                                         | 0,159 s                                        |
| studentai1000000.txt   | -               | 3,010 s             | 0,183 s                 | 0,270 s                             | 0,189 s                              | 2,483 s                                        | 1,566 s                                        |
|                        |                 |                     |                         |                                     |                                      |                                                |                                                |
| 1000studentu.txt       | 0.011 s         | 0,0036 s            | 0,0002 s                | 0,0001 s                            | 0,0001 s                             | 0,0047 s                                       | 0,0039 s                                       |
| 10000studentu.txt      | 0.043 s         | 0,023 s             | 0,002 s                 | 0,001 s                             | 0,001 s                              | 0,024 s                                        | 0,017 s                                        |
| 100000studentu.txt     | 0.435 s         | 0,212 s             | 0,018 s                 | 0,013 s                             | 0,008 s                              | 0,223 s                                        | 0,154 s                                        |
| 1000000studentu.txt    | 4.323 s         | 2,124 s             | 0,188 s                 | 0,268 s                             | 0,186 s                              | 2,908 s                                        | 1,626 s                                        |
| 10000000studentu.txt   | 42.89 s         | 22,238 s            | 3,18 s                  | 4,37 s                              | 3,424 s                              | 22,535 s                                       | 15,912 s                                       |

##### Komentaras:
```
Greičio spartos analizės lentelėse pateikti 3 testavimų laikų vidurkiai.
Greičio spartos analizė buvo atlikta naudojant v0.3 realizaciją.
```
### Greičio spartos analizės išvados:
Atlikus greičio spartos analizę galime matyti, kad abiejų konteinerių greičio spartos rezultatai yra labai panašūs. Tačiau sąrašo tipo konteineris (list) sparčiau atlieka duomenų nuskaitymą iš failo bei šių duomenų kategorizaciją. Tuo tarpu vektoriaus tipo konteineris (vector) yra spartesnis duomenis išvedant į failą. <br>

