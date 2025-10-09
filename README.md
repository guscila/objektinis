# v0.2

## Versijos aprašymas
Versija [v0.1](https://github.com/guscila/objektinis/tree/v0.1-nauja) papildyta funkcija leidžiančia naudotojui sugeneruoti studentų duomenų failus pagal žemiau pateiktą šabloną ( *žr. 'Programos įvesties/generavimo failų formatas'* ). Taip pat, programa papildyta failų spartos analizės funkcija leidžiančia testuoti failus bei sužinoti jų nuskaitymo, duomenų rūšiavimo bei išvedimo į failus spartas. Be to, pridėta funkcija leidžianti naudotojui pasirinkti išvedimo failo rūšiavimo parametrą. Galiausiai, programoje atliktas refactoring'as - struktūros bei funkcijos perkeltos į atskirus failus; sutvarkytas meniu; funkcijoms suteikti aiškesni pavadinimai. <br>
## Programos failai:
### Programos įvesties/generavimo failų formatas:
Vardas1 / Pavarde1 / ND1 / ND2 / ... / Egz. <br>
Jonas / Jonaitis / 8 / 9 / ... / 9 <br>
##### Komentaras:
```
Visi programa sugeneruoti failai buvo sukurti su 5 namų darbų pažymiais studentui.
```
### Programos rezultatų/išvedimo failų formatas:
Vardas1 / Pavarde1 / Galutinis(Vid.) / Galutinis(Med.) <br>
Jonas / Jonaitis / 7.80 / 8.00 <br>
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
| Failas                 | Failo sukūrimas | Duomenų nuskaitymas | Studentų kategorizacija | Išvedimas į failą (*'Kietiakai'* (rez>=5))  | Išvedimas į failą (*'Vargšiukai'* (rez<5)) |
|:-----------------------|:----------------|:--------------------|:------------------------|:----------------------------|:-----------------------------------------------------------|
| studentai10000.txt     | -               | 0.058 s             | 0.003 s                 | 0.026 s                     | 0.019 s                                                    |
| studentai100000.txt    | -               | 0.656 s             | 0.03 s                  | 0.22 s                      | 0.155 s                                                    |
| studentai1000000.txt   | -               | 3.525 s             | 0.266 s                 | 2.241 s                     | 1.519 s                                                    |
| kursiokai.txt          | -               | 0.001 s             | 0.00002 s               | 0.001 s                     | 0.002 s                                                    |
|                        |                 |                     |                         |                             |                                                            |
| 1000studentu.txt       | 0.011 s         | 0.004 s             | 0.0003 s                | 0.004 s                     | 0.004 s                                                    |
| 10000studentu.txt      | 0.043 s         | 0.025 s             | 0.002 s                 | 0.025 s                     | 0.019 s                                                    |
| 100000studentu.txt     | 0.435 s         | 0.294 s             | 0.032 s                 | 0.218 s                     | 0.15 s                                                     |
| 1000000studentu.txt    | 4.323 s         | 2.433 s             | 0.321 s                 | 2.221 s                     | 1.5 s                                                      |
| 10000000studentu.txt   | 42.89 s         | 23.903 s            | 6.856 s                 | 22.169 s                    | 16.193 s                                                   |

##### Komentaras:
```
Greičio spartos analizės lentelėje pateikti 3 testavimų laikų vidurkiai.
```
