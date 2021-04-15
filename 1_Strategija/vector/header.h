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

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::vector;
using std::string;

struct Studentas {
string vardas, pavarde;
vector<int> nd;
double egz, galutinis,med,vid;
};

//const int N= 100000;
const int nd= 5;

void skaitymas (vector<Studentas> &sarasas, int &size, int N);
void rikiavimas (vector<Studentas> &sarasas, int size);
double vidurkis (int kiek, vector<int> a);
double vidurkisGalutinis (vector<Studentas> &sarasas, int size);
double medianaGalutinis (vector<Studentas> &sarasas, int size);
void rusiavimas (vector<Studentas> sarasas, vector<Studentas> &vargsiukai, vector<Studentas> &galvociai);
void vSpausdinimas (vector<Studentas> vargsiukai,bool vm, int N);
void gSpausdinimas (vector<Studentas> galvociai, bool vm, int N);


#endif 
