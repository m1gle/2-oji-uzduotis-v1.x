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
- SSD: Hynix 256GB SATA 3

**Norint keisti kuriamo failo dydį, 'header.h' reikia pakeisti konstantą N.**

**const int N = 1000;**
```

```
**const int N = 10000;**
```

```
**const int N = 100000;**
```

```
**const int N = 1000000;**
```

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
./vector\
- Paleidžiant užduotį su std::list:\
g++ -c function.cpp\
g++ -o vector list.cpp list.o\
./list\
- Paleidžiant užduotį su std::deque:\
g++ -c function.cpp\
g++ -o deque deque.cpp function.o\
./deque
