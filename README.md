# v0.3

## Versijos aprašymas
Versija [v0.2](https://github.com/guscila/objektinis/tree/v0.2) optimizuota ir papildyta galimybe pasirinkti norimą naudoti konteinerį ( Vector arba List ) atliekant veiksmus su duomenimis. Taip pat, programa papildyta funkcija leidžiančia įvestų studentų duomenis išvesti į terminalą bei pateikianti jų saugojimo atmintyje adresus. Programos Timer'is papildytas saugojimo bei visų laiko trukmių išvedimo funkcijomis. Be to, failų spartos analizės funkcija papildyta studentų kategorizacijos bei išvedimo į failus spartos apskaičiavimu. Taip pat, sukurta Meniu struktūra. <br>
## Programos failai:
### Programos įvesties/generavimo failų formatas:
Vardas1 / Pavarde1 / ND1 / ND2 / ... / Egz. <br>
Jonas / Jonaitis / 8 / 9 / ... / 9 <br>
##### Komentaras:
```
Visi programa sugeneruoti failai buvo sukurti su 5 namų darbų pažymiais studentui.
```
### Programos išvedimo failų formatas:
Vardas1 / Pavarde1 / Galutinis(Vid.) / Galutinis(Med.) <br>
Jonas / Jonaitis / 7.80 / 8.00 <br>
### Programos rezultatų terminale formatas:
Vardas1 / Pavarde1 / Galutinis(Vid.) / Galutinis(Med.) / Adresas <br>
Jonas / Jonaitis / 7.80 / 8.00 / 0000000000A000A0 <br>
### Programa testuoti failai:
* Užduotyje pateikti failai:
  * "studentai10000.txt" - 10 tūkst. studentų <br>
  * "studentai100000.txt" - 100 tūkst. studentų <br>
  * "studentai1000000.txt" - 1 mln. studentų <br>
  * "kursiokai.txt" - ~10 studentų <br>
* Programos sugeneruoti failai:
  * "1000studentu.txt" - 1 tūkst. studentų <br>
  * "10000studentu.txt" - 10 tūkst. studentų <br>
  * "100000studentu.txt" - 100 tūkst. studentų <br>
  * "1000000studentu.txt" - 1 mln. studentų <br>
  * "10000000studentu.txt" - 10 mln. studentų <br>
## Greičio spartos analizė:
| Failas                 | Failo sukūrimas | Duomenų nuskaitymas | Studentų kategorizacija | *'Kietiakų'<sup>1</sup>* rūšiavimas | *'Vargšiukų'<sup>2</sup>* rūšiavimas | Išvedimas į failą (*'Kietiakai'<sup>1</sup>*)  | Išvedimas į failą (*'Vargšiukai'<sup>2</sup>*) |
|:-----------------------|:----------------|:--------------------|:------------------------|:------------------------|:-------------------------|:-----------------------------------|:---------------------------------------------|
| studentai10000.txt     | -               |  s             |  s                 |  s                     |  s                                                    |  s |  s
| studentai100000.txt    | -               |  s             |  s                  |  s                      |  s                                                    |  s |  s
| studentai1000000.txt   | -               |  s             |  s                 |  s                     |  s                                                    |  s |  s
| kursiokai.txt          | -               |  s             |  s               |  s                     |  s                                                    |  s |  s
|                        |                 |                |                         |                         |                          |                                    |                                              |
| 1000studentu.txt       | 0.011 s         |  s             |  s                |  s                     |  s                                                    |  s |  s
| 10000studentu.txt      | 0.043 s         |  s             |  s                 |  s                     |  s                                                    |  s |  s
| 100000studentu.txt     | 0.435 s         |  s             |  s                 |  s                     |  s                                                     |  s |  s
| 1000000studentu.txt    | 4.323 s         |  s             |  s                 |  s                     |  s                                                      |  s |  s
| 10000000studentu.txt   | 42.89 s         |  s             |  s                 |  s                    |  s                                                   |  s       |  s

##### Komentaras:
```
1 - Kietiakas - tai studentas, kurio galurinis vidurkis >=5;
2 - Vargšiukas - tai studentas, kurio galutinis vidurkis < 5;
Greičio spartos analizės lentelėje pateikti 3 testavimų laikų vidurkiai.
```
