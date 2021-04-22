# [2-oji-užduotis v1.1]

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

Su v1.0 (Rūšiavimo optimizavimas)
- std::vector, std::deque ir std::list konteineriams rūšiavimo funkcijai pritaikytos dvi strategijos
- testuojamas dviejų strategijų nuskaitymo, rūšiavimo į dvi grupes ir bendras programos greitis

Strategijos:
- 1 strategija: Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai).
- 2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai. 

Pritaikytų strategijų rezultatai:
![alt text](https://i.imgur.com/Hc91QcR.png)
Rezultatas: 1 strategijoje greičiau veikia vector, o deque ir list sparta priklauso nuo studentų sarašo dydžio. 2 strategijoje vector ir deque naudojant vector::erase ir deque::erase programa žymiai lėčiau veikia, nei list, kurioje irgi buvo naudota list::erase.

2 strategiją pakeičiau naudojant remove_if, kuriuo iš sarašo ištryniau studentus, kurių pažymys <5:
![alt text](https://i.imgur.com/OY0tpCu.png)
Rezultatas: std::vector pakoreguota 2 strategija ir vietoj vector::erase panaudota std::remove_if bei tai gerokai paspartino rūšiavimo greitį.

Su v1.1
- vietoj vektoriaus struktūros naudojama vectoriaus klasė
- palyginimi programos veikimo laikai su ankščiau kurta std::vector struktūra
- panaudojami optimizavimo flag'ai, palyginami rezultatai

Gauti laikai:
![alt text](https://i.imgur.com/TdL4xIa.png)

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
- Kompiliavimui atitinkamai naudoti make vector/deque/list komandą:\
- .o failo ištrinimui naudoti make clean komandą.
- Paleisti ./[pavadinimas]\
Makefile:
```
clean:
	rm *.o
vector: 
	g++ -c function.cpp && g++ -o vector vector.cpp function.o
list: 
	g++ -c function.cpp && g++ -o list list.cpp function.o
deque: 
	g++ -c function.cpp && g++ -o deque deque.cpp function.o
```

Testavimo sistemos parametrai: 
- CPU: Intel i5 8250U (4 cores, 8 threads)
- RAM: 12GB DDR4
- SSD: Hynix 256GB SATA 3.0 (OS)
- SSD: Crucial 1TB SATA 3.0
