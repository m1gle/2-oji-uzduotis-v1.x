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
deque<int> nd;
double egz, galutinis,med,vid;
};

const int N= 1000000;
const int nd= 5;

void kurimas ();
void skaitymas (deque<Studentas> &sarasas, int &size);
void rikiavimas (deque<Studentas> &sarasas, int size);
double vidurkis (int kiek, deque<int> a);
double vidurkisGalutinis (deque<Studentas> &sarasas, int size);
double medianaGalutinis (deque<Studentas> &sarasas, int size);
void rusiavimas (deque<Studentas> sarasas, deque<Studentas> &vargsiukai, deque<Studentas> &galvociai);
void vSpausdinimas (deque<Studentas> vargsiukai,bool vm);
void gSpausdinimas (deque<Studentas> galvociai, bool vm);


#endif 
