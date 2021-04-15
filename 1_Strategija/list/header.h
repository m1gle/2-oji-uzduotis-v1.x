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
#include <list>
#include <deque>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::vector;
using std::string;
using std::list;
using std::deque;

struct Studentas {
string vardas, pavarde;
list<int> nd;
double egz, galutinis,med,vid;
};

// const int N= 100000;
// const int nd= 5;

void kurimas ();
void skaitymas (list<Studentas> &sarasas, int &size, int N);
void rikiavimas (list<Studentas> &sarasas, int size);
double vidurkis (int kiek, list<int> a);
double vidurkisGalutinis (list<Studentas> &sarasas, int size);
double medianaGalutinis (list<Studentas> &sarasas, int size);
void rusiavimas (list<Studentas> sarasas, list<Studentas> &vargsiukai, list<Studentas> &galvociai);
void vSpausdinimas (list<Studentas> vargsiukai,bool vm, int N);
void gSpausdinimas (list<Studentas> galvociai, bool vm, int N);


#endif 
