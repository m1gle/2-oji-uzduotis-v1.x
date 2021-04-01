# [2-oji-užduotis v0.5]

Programa suskaičiuoja studento vidurkį arba medianą.

**Programos veikimas:**\
Su v0.1:
- įvesti vardą ir pavardę
- įvesti arba sugeneruoti namų darbų pažymius bei egzamino balą
- suskaičiuoja suvestų pažymių vidurkį arba mediana

Su v0.2:
- pasirinkti nuskaityti arba įvesti duomenis pačiam
- nuskaityti duomenis iš failo
- duomenys yra suruošiuojami pagal pavardes
- vidurkis ir mediana apvalinami iki sviekosios dalies

Su v0.3
- funkcijos perkeltos į naują "function.cpp" failą
- sukurtas išimpčių valdymas, kuris tikrina ar nuskaitomi tesingi pažymiai bei ar skaitomas failas egzistuoja

Su v0.4
- programa nieko vartotojo nebeklausia
- sukuriamas failas
- nuskaitomas failas
- studentai surušiuojami į dvi grupes pagal galutinį pažymį <5: "vargsiukai", >=5: "galvociai"
- skaičiuojamas bendras programos ir kiekvienos funkcijos veikimo laikas bei atspausdinamas

Su v0.5 (Konteinerių testavimas)
- programa papildomai parašyta naudojant std::list ir std::deque
- testuotjamas nuskaitymo ir rūšiavimo į dvi grupes greitis


**Norint keisti kuriamo failo dydį, 'header.h' reikia pakeisti konstantą N.**

Pavyzdys:\
**const int N = 10;**\
Programa paleidžiama.\
Sukuriamas failas failas ("stud10.txt"):
```
Pavarde        Vardas         ND1     ND2     ND3     ND4     ND5     EGZ
Pavarde0       Vardas0        7       10      7       1       3       8
Pavarde1       Vardas1        8       3       10      8       3       6
Pavarde2       Vardas2        9       7       2       7       6       3
Pavarde3       Vardas3        8       1       5       5       7       10
Pavarde4       Vardas4        9       7       1       4       7       6
Pavarde5       Vardas5        3       3       4       10      5       7
Pavarde6       Vardas6        8       4       7       7       4       3
Pavarde7       Vardas7        1       8       8       2       10      2
Pavarde8       Vardas8        5       4       3       5       8       5
Pavarde9       Vardas9        6       4       5       2       2       9
```
Atspausdinimo rezultatas:
```
Failo kurimas uztruko: 0.004987
Failo nuskaitymas uztruko: 0
Vargsiuku irasymas uztruko: 0.00399
Galvociu irasymas uztruko: 0.004987
Bendrai uztruko: 0.019947
```

**const int N = 1000;**
```
Failo kurimas uztruko: 0.023946
Failo nuskaitymas uztruko: 0.009972
Rusiavimas uztruko: 0.001008
Vargsiuku irasymas uztruko: 0.010874
Galvociu irasymas uztruko: 0.014961
Bendrai uztruko: 0.067546
```
**const int N = 10000;**
```
Failo kurimas uztruko: 0.139806
Failo nuskaitymas uztruko: 0.10682
Rusiavimas uztruko: 0.008979
Vargsiuku irasymas uztruko: 0.041861
Galvociu irasymas uztruko: 0.071683
Bendrai uztruko: 0.391316
```
**const int N = 100000;**
```
Failo kurimas uztruko: 1.29286
Failo nuskaitymas uztruko: 0.913612
Rusiavimas uztruko: 0.126279
Vargsiuku irasymas uztruko: 0.307575
Galvociu irasymas uztruko: 0.687843
Bendrai uztruko: 3.48651
```
**const int N = 1000000;**
```
Failo kurimas uztruko: 12.8814
Failo nuskaitymas uztruko: 7.99245
Rusiavimas uztruko: 1.01187
Vargsiuku irasymas uztruko: 3.01465
Galvociu irasymas uztruko: 5.99765
Bendrai uztruko: 32.3834
```
**Išimčių valdymas:**\
Jeigu neranda skaitymo failo gaunama žinutė:
```
Nerastas failas!
```
Blogas pažymio ir egzamino įvedimas faile išmeta:
```
Netinkamas namu darbu pazymis skaitymo failel! Pazymis turi buti >=0 && <=10!
Netinkamas egzamino pazymis skaitymo failel! Pazymis turi buti >=0 && <=10!
```
Programa sukurta naudojant std::vector ("vector")

**Įdiegimo instrukcija:**\
Atsisiųsti _release ir jį išarchivuoti. Terminale nuėjus į išarchivuotą aplanką atlikti:
- Paleidžiant užduotį su std::vector:\
g++ -c function.cpp\
g++ -o vector vector.cpp function.o\
./vector
