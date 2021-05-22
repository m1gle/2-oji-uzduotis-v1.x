#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch.hpp"
#include "../main/header.h"

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
