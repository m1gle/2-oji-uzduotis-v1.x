#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <limits>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::vector;
using std::string;

class Studentas {
private:
  string vardas;
  string pavarde;
  int egzaminas;
  vector<int> nd;
  int galutinis;
  
public:
// Konstruktoriai:
    Studentas(){
        setReiksmes("a","b",10,10);
    }
// Destruktorius:
    Studentas::~Studentas(){}
// Seteriai:
    void setVardas(string vardas){this->vardas = vardas;}
    void setPavarde (string pavarde){this->pavarde = pavarde;}
    void setEgzaminas (int egzaminas){this->egzaminas = egzaminas;}
    void setPazymys (int pazymys){nd.push_back(pazymys);}
    void setGalutinis (double galutinis){this->galutinis = galutinis;}
    void setReiksmes(string vardas, string pavarde, int egzaminas, int galutinis){ // vienas konstruktorius užpildyti visą vektorių:
        this->vardas = vardas;
        this->pavarde = pavarde;
        this->egzaminas = egzaminas;
        this->galutinis = galutinis;
    }
// Geteriai:
    string getVardas (){return vardas;}
    string getPavarde (){return pavarde;}
    int getEgzaminas (){return egzaminas;}
    vector<int> getPazymiai (){return nd;}
    int getPazymys (){return nd[0];}
    int getGalutinis() {return galutinis;}
};


void skaitymas(vector <Studentas> &sarasas, int n);
void vidurkisGalutinis (vector<Studentas> &sarasas);
void rusiavimas (vector<Studentas> sarasas, vector<Studentas> &vargsiukai, vector<Studentas> &galvociai);
void vSpausdinimas (vector<Studentas> vargsiukai, int n);
void gSpausdinimas (vector<Studentas> galvociai, int n);


#endif 
