# [2-oji-užduotis v2.0]

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

Pritaikytų strategijų rezultatai:\
1 Strategija:
| Tipas | 1000 Skaitymas | 1000 Rūšiavimas | 1000 Bendrai  | 10000 Skaitymas | 10000 Rūšiavimas | 10000 Bendrai  | 100000 Skaitymas | 100000 Rūšiavimas | 100000 Bendrai | 1000000 Skaitymas | 1000000 Rūšiavimas | 1000000 Bendrai | 10000000 Skaitymas | 10000000 Rūšiavimas | 10000000 Bendrai  |
|--------|-----------|------------|----------|-----------|------------|----------|-----------|------------|---------|-----------|------------|---------|-----------|------------|----------|
| Vector | 0.007975  | 0.000996   | 0.025861 | 0.093882  | 0.010782   | 0.240121 | 0.94586   | 0.110199   | 2.02733 | 8.51009   | 0.885945   | 22.1732 | 82.421    | 7.87416    | 256.2716 |
| Deque  | 0.012879  | 0.000997   | 0.038816 | 0.100252  | 0.016954   | 0.290561 | 0.848139  | 0.265716   | 3.13089 | 12.3588   | 2.44689    | 30.7859 | 89.7757   | 14.2768    | 284.7558 |
| List   | 0.010971  | 0.001002   | 0.032993 | 0.085769  | 0.011974   | 0.255352 | 0.828948  | 0.134699   | 2.54121 | 10.4445   | 2.33591    | 32.8529 | 87.4815   | 11.8163    | 287.4582 |

2 Strategija:
| Tipas | 1000 Skaitymas | 1000 Rūšiavimas | 1000 Bendrai  | 10000 Skaitymas | 10000 Rūšiavimas | 10000 Bendrai  | 100000 Skaitymas | 100000 Rūšiavimas | 100000 Bendrai |
|--------|-----------|------------|----------|-----------|------------|----------|-----------|------------|---------|
| Vector | 0.007975  | 0.067948   | 0.092375 | 0.091948  | 6.25084    | 6.46164  | 0.798945  | 659.071    | 660.93  |
| Deque  | 0.010042  | 0.02893    | 0.057732 | 0.085061  | 2.68303    | 2.92414  | 0.811928  | 293.035    | 295.179 |
| List   | 0.02642   | 0          | 0.046306 | 0.095331  | 0.004984   | 0.246347 | 0.858934  | 0.055927   | 2.71802 |

Rezultatas: 1 strategijoje greičiau veikia vector, o deque ir list sparta priklauso nuo studentų sarašo dydžio. 2 strategijoje vector ir deque naudojant vector::erase ir deque::erase programa žymiai lėčiau veikia, nei list, kurioje irgi buvo naudota list::erase.

2 strategiją pakeičiau naudojant remove_if, kuriuo iš sarašo ištryniau studentus, kurių pažymys <5:
| Tipas | 1000 Skaitymas | 1000 Rūšiavimas | 1000 Bendrai | 10000 Skaitymas | 10000 Rūšiavimas | 10000 Bendrai  | 100000 Skaitymas | 100000 Rūšiavimas | 100000 Bendrai | 1000000 Skaitymas | 1000000 Rūšiavimas | 1000000 Bendrai | 10000000 Skaitymas | 10000000 Rūšiavimas | 10000000 Bendrai |
|--------|-----------|------------|---------|-----------|------------|----------|-----------|------------|---------|-----------|------------|---------|-----------|------------|---------|
| Vector | 0.00999   | 0.000997   | 0.01763 | 0.084436  | 0.006992   | 0.131163 | 0.795588  | 0.069971   | 1.22628 | 7.97509   | 0.635962   | 12.0685 | 81.456    | 6.3146     | 164.268 |

Rezultatas: std::vector pakoreguota 2 strategija ir vietoj vector::erase panaudota std::remove_if bei tai gerokai paspartino rūšiavimo greitį.

Su v1.1
- vietoj vektoriaus struktūros naudojama vectoriaus klasė
- palyginimi programos veikimo laikai su ankščiau kurta std::vector struktūra
- panaudojami optimizavimo flag'ai, palyginami rezultatai

| Versija  | Naudojamas tipas | Flag'as | 100000 studentų failas | 1000000 studentų failas | Failo dydis |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| v1.0 | struktūra | nėra | 2.1747 | 20.9054 | 188KB |
| v1.1 | struktūra | O1 | 2.0345 | 20.0918 | 184KB |
| v1.1 | struktūra| O2 | 2.1033 | 19.5852 | 184KB |
| v1.1 | struktūra| O3 | 2.0104 | 19.5326 | 184KB |
| v1.1 | klasė | nėra | 2.0273 | 22.1732 | 178KB |
| v1.1 | klasė | O1 | 2.1664 | 21.0803 | 178KB |
| v1.1 | klasė| O2 | 2.2216 | 20.8976 | 178KB |
| v1.1 | klasė| O3 | 2.1694 | 20.8815 | 178KB |

Su v1.2
- sukurtas vienas seteris visoms reikšmėms perduoti
- sukurtas konstruktorius ir desturktorius

Su v1.5
- Sukurtos dvi klasės: bazinė Zmogus klasė bendrai aprašyti žmogų ir iš jos išvestinė (derived) klasė - Studentas
- Žmogui skirta bazinė klasė yra abstrakčioji klasė, t.y. negalima sukurti žmogaus tipo objektų, o tik objektus gautus iš jos išvestinių klasiu

Sy v2.0
- Sukurta dokumentacija panaudojant Doxygen, norint pamatyti dokumentaciją, reikia atsidaryti index.html failą, kuris yra /doxygen/html/ aplankale.
- Atlikti Unit testai
- Sukurtas automatinis įdiegimo failas

Su Unit Test : Catch atliekami testai:
```
TEST_CASE("Studentas class tikrinimas") {

  SECTION("Studentas::vardas") {
    Studentas student;
    student.setVardas("Testas");
    REQUIRE(student.getVardas() == "Testas");
  }

  SECTION("Studentas::pavarde") {
    Studentas student;
    student.setPavarde("Testerauskas");
    REQUIRE(student.getPavarde() == "Testerauskas");
  }

    SECTION("Studentas::egzaminas") {
    Studentas student;
    student.setEgzaminas(5);
    REQUIRE(student.getEgzaminas() == 5);
  }

    SECTION("Studentas::galutinis") {
    Studentas student;
    student.setGalutinis(10);
    REQUIRE(student.getGalutinis() == 10);
  }
  
}
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
