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

void vedimasRanka (vector<Studentas> &sarasas,int &size);
void skaitymas (vector<Studentas> &sarasas, int &size);
void rikiavimas (vector<Studentas> &sarasas, int size);
double vidurkis (int kiek, vector<int> a);
double vidurkisGalutinis (vector<Studentas> &sarasas, int size);
double medianaGalutinis (vector<Studentas> &sarasas, int size);
double spausdinimas (vector<Studentas> sarasas, int size);


#endif 
