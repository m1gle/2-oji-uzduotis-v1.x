# [2-oji-užduotis v0.2]

Programa suskaičiuoja studento vidurkį arba medianą.

Programos veikimas:\
Su v0.1:
- įvesti vardą ir pavardę
- įvesti arba sugeneruoti namų darbų pažymius bei egzamino balą
- suskaičiuoja suvestų pažymių vidurkį arba mediana

Su v0.2:
- pasirinkti nuskaityti arba įvesti duomenis pačiam
- nuskaityti duomenis iš failo
- duomenys yra suruošiuojami pagal pavardes

Skaitomas failas ("kursiokai.txt"):
```
Vardas                   Pavarde                    ND1       ND2       ND3       ND4       ND5       ND6       ND7       ND8       ND9      ND10      ND11      ND12      ND13      ND14      ND15      Egz.
Povilas                 Povilaitis                    8         5         8         3         3         7         3        10         2         3         7         5         6         3         5         3
Brone                   Broniene                      6         6         5         5         1         8         4         3         3         8         5         4         5         5         5         7
Antanas                 Antanaitis                    8         3         2         7         7         9         5        10         9         9        10         4         3         3         8         5
Aldona                  Aldoniene                     7         9         8         9         6         8         8         8         3         9         5         2         5         5         5         1
Zygis                   Zygiokas                      7         4         6         5         8         2         1         2         8         9         1         6         5         5         2         9
Saulius                 Saulenas                     10         4        10        10         2         3        10         7         8         5         3         9         5         1         5         2
Dovile                  Doviliene                     8         4         5         2         8         9         2         3         8        10         8         7         3         5         9         9
Dovydas                 Dovydenas                     3         5         2         1         3         8         3         6         7        10         9         8         9         8         4         1
```

Programos veikimo pavyzdys:
```
Skaityti faila (y) ar ivesti ranka (n) ?: y
```
Atspausdinimo rezultatas:
```
Pavarde        Vardas         Galutinis (Vid.) | Galutinis (Med.)
---------------------------------------------------------------------
Aldoniene      Aldona         3.19               3.4
Antanaitis     Antanas        5.59               5.8
Broniene       Brone          6.15               6.2
Doviliene      Dovile         7.83               8.2
Dovydenas      Dovydas        2.89               3
Povilaitis     Povilas        3.88               3.8
Saulenas       Saulius        3.65               3.2
Zygiokas       Zygis          7.29               7.4
```

Programa sukurta naudojant std::vector ("vector")

Įdiegimo instrukcija:  
Atsisiųsti _release ir jį išarchivuoti. Terminale nuėjus į išarchivuotą aplanką atlikti:
- Paleidžiant užduotį su std::vector:\
g++ vector.cpp -o vector\
./vector
