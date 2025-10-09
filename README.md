# v0.2

## Versijos aprašymas
Versija [v0.1](https://github.com/guscila/objektinis/tree/v0.1-nauja) papildyta funkcija leidžiančia naudotojui sugeneruoti studentų duomenų failus pagal žemiau pateiktą šabloną ( *žr. 'Programos įvesties/generavimo failų formatas'* ). Taip pat, programa papildyta failų spartos analizės funkcija leidžiančia testuoti failus bei sužinoti jų nuskaitymo, duomenų rūšiavimo bei išvedimo į failus spartas. Galiausiai, programoje atliktas refactoring'as - struktūros bei funkcijos perkeltos į atskirus failus; sutvarkytas meniu; funkcijoms suteikti aiškesni pavadinimai. <br>
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
## Greičio spartos analizė
| Failas                 | Failo sukūrimas | Duomenų nuskaitymas | Studentų rūšiavimas | Išvedimas į failus |
|:-----------------------|:----------------|:--------------------|:--------------------|:-------------------|
| studentai10000.txt     | -               | 0.062 s             | 0.003 s             | 0.044 s            |
| studentai100000.txt    | -               | 0.66 s              | 0.035 s             | 0.427 s            |
| studentai1000000.txt   | -               | 3.295 s             | 0.326 s             | 4.114 s            |
| kursiokai.txt          | -               | 0.002 s             | 0.00001 s           | 0.004 s            |
|                        |                 |                     |                     |                    |
| 1000studentu.txt       | 0.011 s         | 0.004 s             | 0.0002 s            | 0.006 s            |
| 10000studentu.txt      | 0.043 s         | 0.039 s             | 0.005 s             | 0.093 s            |
| 100000studentu.txt     | 0.435 s         | 0.269 s             | 0.055 s             | 0.413 s            |
| 1000000studentu.txt    | 4.323 s         | 2.296 s             | 0.28 s              | 4.104 s            |
| 10000000studentu.txt   | 42.89 s         | 24.07 s             | 7.603 s             | 59.189 s           |
