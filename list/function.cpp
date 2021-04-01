#include "header.h"

void kurimas (){
int x;
srand (time(NULL));
string temp;
std::ofstream ofs ("stud" + std::to_string(N) + ".txt");
ofs<<"Pavarde        "<<"Vardas         ";
for(int i=0;i<nd;i++) ofs<<"ND"<<i+1<<"     ";
ofs<<"EGZ"<<endl;
for(int i=0;i<N;i++){
temp="Pavarde"+std::to_string(i);
ofs<<temp;
    for(int j=0;j<15-temp.size();j++) ofs<<" ";
temp="Vardas"+std::to_string(i);
ofs<<temp;
    for(int j=0;j<15-temp.size();j++) ofs<<" ";
    for(int j=0;j<nd;j++) {
        x=rand() % 10 + 1;
        ofs<<x;    
        if(x==10) ofs<<"      ";
        else ofs<<"       ";
    }
x=rand() % 10 + 1;
ofs<<x;
ofs<<endl;
}
ofs.close();
}

void skaitymas (list<Studentas> &sarasas, int &size) {
size=0;
int i;
string temp;
int tempr;
string eil,line;
Studentas tempStruct;
auto start = std::chrono::high_resolution_clock::now(); auto st=start;
std::ifstream inf ("stud" + std::to_string(N) + ".txt");
if(!inf.good()) throw "Nerastas failas!";
getline(inf,eil);
    while(!inf.eof()){
    inf>>temp;
    tempStruct.vardas= temp;
    inf>>temp;
    tempStruct.pavarde= temp;
        while(!inf.eof()){
            inf>>tempr;
            if (tempr>10 || tempr<1) throw "Netinkamas pazymis skaitymo faile! Pazymis turi buti >=0 && <=10!";
            if(inf.peek()=='\n'||inf.peek() == inf.eof()){
                tempStruct.egz = tempr;
                break;
            }
            tempStruct.nd.push_back(tempr); 
            i++;
        }
    sarasas.push_back(tempStruct);
    tempStruct = {};
    i=0;
    size++;
    inf.ignore();
    }
inf.close();
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; // Skirtumas (s)
cout<<"Failo nuskaitymas uztruko: "<<diff.count()<<endl;
}

double vidurkis (int kiek, list<int> a) {
double v;
double sum=0;
list<int>::iterator it;
it = a.begin();
 while (it != a.end()) {
    sum = sum + *it;
    it++;
 }
 v=sum*1.00/kiek;
return v;
}

double vidurkisGalutinis (list<Studentas> &sarasas, int size){
    list<Studentas>::iterator it;
    it = sarasas.begin();
   for(int i=0;i<sarasas.size();i++){
      if(it->nd.size()==0) it->vid=0.6*it->egz;
      else it->vid=0.4*vidurkis((it->nd.size()),it->nd)+0.6*it->egz;
      it->galutinis=round(it->vid);
      it++;
    } 
}

void rusiavimas (list<Studentas> sarasas, list<Studentas> &vargsiukai, list<Studentas> &galvociai){
list<Studentas>::iterator it;
list<Studentas> tempStruct;
std::ofstream ofs ("vargsiukai.txt", std::ofstream::out);
auto start = std::chrono::high_resolution_clock::now(); auto st=start;
for (it = sarasas.begin(); it != sarasas.end(); ++it){
    if(it->galutinis>=5) galvociai.push_back(*it);
    if(it->galutinis<5) vargsiukai.push_back(*it);
}
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; // Skirtumas (s)
cout<<"Rusiavimas uztruko: "<<diff.count()<<endl;
sarasas.clear();
}

void vSpausdinimas (list<Studentas> vargsiukai,bool vm){
    string temp; 
    list<Studentas>::iterator it;
    std::ofstream ofs ("vargsiukai.txt", std::ofstream::out);
if(vm==true)
ofs<<"Pavarde        "<<"Vardas         "<<"Galutinis (Vid.)"<<endl;
if(vm==false)
ofs<<"Pavarde        "<<"Vardas         "<<"Galutinis (Med.)"<<endl;
ofs<<"---------------------------------------------------------------------"<<endl;
for (it = vargsiukai.begin(); it != vargsiukai.end(); ++it){
temp += it->pavarde;
for(int j=0;j<15-(it->pavarde.size());j++)temp +=" ";
temp += it->vardas;
for(int j=0;j<20-(it->vardas.size());j++)temp +=" ";
//temp += std::to_string(vargsiukai[i].galutinis);
ofs<<temp<<std::setprecision(0)<<it->galutinis<<endl;
temp.clear();
it++;
}
ofs.close();
}

void gSpausdinimas (list<Studentas> galvociai, bool vm){
    string temp; 
    list<Studentas>::iterator it;
    std::ofstream ofs ("galvociai.txt", std::ofstream::out);
if(vm==true)
ofs<<"Pavarde        "<<"Vardas         "<<"Galutinis (Vid.)"<<endl;
if(vm==false)
ofs<<"Pavarde        "<<"Vardas         "<<"Galutinis (Med.)"<<endl;
ofs<<"---------------------------------------------------------------------"<<endl;
for (it = galvociai.begin(); it != galvociai.end(); ++it){
temp += it->pavarde;
for(int j=0;j<15-(it->pavarde.size());j++)temp += " ";
temp += it->vardas;
for(int j=0;j<20-(it->vardas.size());j++)temp += " ";
//temp += std::to_string(galvociai[i].galutinis);
ofs<<temp<<std::setprecision(0)<<it->galutinis<<endl;
temp.clear();
}
ofs.close();
}
