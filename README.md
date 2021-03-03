# [2-oji-užduotis v0.1] Vidurkio arba medianos skaičiavimas

Programa suskaičiuoja studento vidurkį arba medianą.

Programos veikimas:
- įvesti vardą ir pavardę
- įvesti arba sugeneruoti namų darbų pažymius bei egzamino balą
- suskaičiuoja suvestų pažymių vidurkį arba medianą

Programos veikimo pavyzdys:
```
Iveskite studento varda: Vardas
Iveskite studento pavarde: Pavardenis
Ar zinomas namu darbu kiekis (y/n): y
Iveskite namu darbu kieki: 10
Generuoti random reiksmes? (y/n): y
Sugeneruoti 10 pazymiai: 8 8 8 9 8 6 10 4 3 2
Sugeneruotas egzamino pazymys: 5
Prideti mokini? (y/n) n
Ar norite suskaiciuoti mediana? (y/n): n
```
Atspausdinimo rezultatas:
```
Pavarde        Vardas         Galutinis (Vid.)
-----------------------------------------------
Pavardenis     Vardas         5.64
```

Programa sukurta dviem būdais:
1) naudojant C masyvą ("array.cpp")
2) naudojant std::vector ("vector")

Įdiegimo instrukcija:  
Atsisiųsti _release ir jį išarchivuoti. Terminale nuėjus į išarchivuotą aplanką atlikti:
- Paleidžiant užduotį su C masyvu:\
g++ array.cpp -o array\
./array
- Paleidžiant užduotį su std::vector:\
g++ vector.cpp -o vector\
./vector
