#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <limits>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::vector;
using std::string;
using std::left;
using std::right;
using std::fixed;

class Zmogus{
protected:
    string vardas_;
    string pavarde_;
public:
    virtual string getVardas() = 0;
    virtual string getPavarde() = 0;
};

class Studentas: public Zmogus{
private:
  string vardas_;
  string pavarde_;
  int egzaminas_;
  vector<int> nd_;
  int galutinis_;
  
public:
    Studentas(): egzaminas_(0){}
    ~Studentas() {nd_.clear();}
// Seteriai:
    void setVardas(string vardas){this->vardas_ = vardas;}
    void setPavarde (string pavarde){this->pavarde_ = pavarde;}
    void setEgzaminas (int egzaminas){this->egzaminas_ = egzaminas;}
    void setPazymys (int pazymys){nd_.push_back(pazymys);}
    void setGalutinis (double galutinis){this->galutinis_ = galutinis;}
// Geteriai:
    string getVardas() override { return vardas_; }
    string getPavarde() override { return pavarde_; }
    int getEgzaminas (){return egzaminas_;}
    vector<int> getPazymiai (){return nd_;}
    int getPazymys (){return nd_[0];}
    int getGalutinis() {return galutinis_;}
};

void skaitymas(vector<Studentas> &sarasas, int n);
void vidurkisGalutinis (vector<Studentas> &sarasas);
void rusiavimas (vector<Studentas> sarasas, vector<Studentas> &vargsiukai, vector<Studentas> &galvociai);
void vSpausdinimas (vector<Studentas> vargsiukai, int n);
void gSpausdinimas (vector<Studentas> galvociai, int n);


#endif 
