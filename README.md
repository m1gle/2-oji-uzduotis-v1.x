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

Testavimo sistemos parametrai: 
- CPU: Intel i5 8250U (4 cores, 8 threads)
- RAM: 12GB DDR4
- SSD: Hynix 256GB SATA 3.0 (OS)
- SSD: Crucial 1TB SATA 3.0

**Norint keisti kuriamo failo dydį, 'header.h' reikia pakeisti konstantą N.**

**const int N = 100;**\
vector:
```
Failo nuskaitymas uztruko: 0.001992
Rusiavimas uztruko: 0
```
list:
```
Failo nuskaitymas uztruko: 0
Rusiavimas uztruko: 0  
```
deque:
```
Failo nuskaitymas uztruko: 0
Rusiavimas uztruko: 0  
```
**const int N = 1000;**\
vector:
```
Failo nuskaitymas uztruko: 0.008974
Rusiavimas uztruko: 0.000998
```
list:
```
Failo nuskaitymas uztruko: 0.008941
Rusiavimas uztruko: 0.000997 
```
deque:
```
Failo nuskaitymas uztruko: 0.015709
Rusiavimas uztruko: 0.000997 
```
**const int N = 10000;**\
vector:
```
Failo nuskaitymas uztruko: 0.087806
Rusiavimas uztruko: 0.007964
```
list:
```
Failo nuskaitymas uztruko: 0.093727
Rusiavimas uztruko: 0.012942
```
deque:
```
Failo nuskaitymas uztruko: 0.078106
Rusiavimas uztruko: 0.012964
```
**const int N = 100000;**\
vector:
```
Failo nuskaitymas uztruko: 0.826023
Rusiavimas uztruko: 0.10834
```
list:
```
Failo nuskaitymas uztruko: 0.813411
Rusiavimas uztruko: 0.124971
```
deque:
```
Failo nuskaitymas uztruko: 0.782703
Rusiavimas uztruko: 0.124971
```
**const int N = 1000000;**\
vector:
```
Failo nuskaitymas uztruko: 7.92043
Rusiavimas uztruko: 0.961516
```
list:
```
Failo nuskaitymas uztruko: 8.02455
Rusiavimas uztruko: 1.22438
```
deque:
```
Failo nuskaitymas uztruko: 7.77574
Rusiavimas uztruko: 1.27689
```
**const int N = 10000000;**\
vector:
```
Failo nuskaitymas uztruko: 82.42103
Rusiavimas uztruko: 7.87416
```
list:
```
Failo nuskaitymas uztruko: 89.48153
Rusiavimas uztruko: 12.81638
```
deque:
```
Failo nuskaitymas uztruko: 7.77574
Rusiavimas uztruko: 1.27689
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
Programos sukurtos naudojant std::vector ("vector"), std::list ("list"), std::deque ("deque").

**Įdiegimo instrukcija:**\
Atsisiųsti _release ir jį išarchivuoti. Terminale nuėjus į išarchivuotą aplanką atlikti:
- Paleidžiant užduotį su std::vector:\
g++ -c function.cpp\
g++ -o vector vector.cpp function.o\
./vector
- Paleidžiant užduotį su std::list:\
g++ -c function.cpp\
g++ -o vector list.cpp list.o\
./list
- Paleidžiant užduotį su std::deque:\
g++ -c function.cpp\
g++ -o deque deque.cpp function.o\
./deque
