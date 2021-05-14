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
  string vardas_;
  string pavarde_;
  int egzaminas_;
  vector<int> nd_;
  int galutinis_;
  
public:
    Studentas() { setReiksmes("", "", 0, 0); }
// Seteriai:
    void setVardas(string vardas){this->vardas_ = vardas;}
    void setPavarde (string pavarde){this->pavarde_ = pavarde;}
    void setEgzaminas (int egzaminas){this->egzaminas_ = egzaminas;}
    void setPazymys (int pazymys){nd_.push_back(pazymys);}
    void setGalutinis (double galutinis){this->galutinis_ = galutinis;}
    void setReiksmes(string vardas, string pavarde, int egzaminas, int galutinis){ // vienas konstruktorius užpildyti visą vektorių:
        this->vardas_ = vardas;
        this->pavarde_ = pavarde;
        this->egzaminas_ = egzaminas;
        this->galutinis_= galutinis;
    }
// Geteriai:
    string getVardas (){return vardas_;}
    string getPavarde (){return pavarde_;}
    int getEgzaminas (){return egzaminas_;}
    vector<int> getPazymiai (){return nd_;}
    int getPazymys (){return nd_[0];}
    int getGalutinis() {return galutinis_;}


//Priskyrimo operatorius
    Studentas& operatorASSIGN (const Studentas& that) {
        this->vardas_ = that.vardas_;
        this->pavarde_ = that.pavarde_;
        this->egzaminas_ = that.egzaminas_;
        this->galutinis_ = that.galutinis_;
        return *this;
}   
//Kopijavimo
    Studentas (const Studentas &sarasas) {
        vardas_ = sarasas.vardas_; 
        pavarde_ = sarasas.pavarde_; 
        egzaminas_ = sarasas.egzaminas_;
        galutinis_ = sarasas.galutinis_;}
    
    ~Studentas() {nd_.clear();}
};


void skaitymas(vector <Studentas> &sarasas, int n);
void vidurkisGalutinis (vector<Studentas> &sarasas);
void rusiavimas (vector<Studentas> sarasas, vector<Studentas> &vargsiukai, vector<Studentas> &galvociai);
void vSpausdinimas (vector<Studentas> vargsiukai, int n);
void gSpausdinimas (vector<Studentas> galvociai, int n);


#endif 
