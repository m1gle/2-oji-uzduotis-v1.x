#include "header.h"

void skaitymas (vector<Studentas> &sarasas, int &size, int N) {
size=0;
int i;
string temp;
int tempr;
string eil,line;
vector<Studentas> tempStruct;
tempStruct.push_back(Studentas());
auto start = std::chrono::high_resolution_clock::now(); auto st=start;
std::ifstream inf ("stud" + std::to_string(N) + ".txt");
if(!inf.good()) throw "Nerastas failas!";
getline(inf,eil);
    while(!inf.eof()){
    inf>>temp;
    tempStruct[0].pavarde= temp;
    inf>>temp;
    tempStruct[0].vardas= temp;
        while(!inf.eof()){
            inf>>tempr;
            if (tempr>10 || tempr<1) throw "Netinkamas pazymis skaitymo faile! Pazymis turi buti >=0 && <=10!";
            if(inf.peek()=='\n'||inf.peek() == inf.eof()){
                tempStruct[0].egz = tempr;
                break;
            }
            tempStruct[0].nd.push_back(tempr); 
            i++;
        }
    sarasas.push_back(tempStruct[0]);
    tempStruct[0] = {};
    i=0;
    size++;
    inf.ignore();
    }
inf.close();
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; // Skirtumas (s)
cout<<"Failo nuskaitymas uztruko: "<<diff.count()<<endl;
}

double vidurkis (int kiek, vector<int> a) {
double v;
double sum=0;
 for(int i=0;i<kiek;i++){
    sum=sum+a[i];
 }
 v=sum*1.00/kiek;
return v;
}

double vidurkisGalutinis (vector<Studentas> &sarasas, int size){
   for(int i=0;i<sarasas.size();i++){
      if(sarasas[i].nd.size()==0) sarasas[i].vid=0.6*sarasas[i].egz;
      else sarasas[i].vid=0.4*vidurkis((sarasas[i].nd.size()),sarasas[i].nd)+0.6*sarasas[i].egz;
      sarasas[i].galutinis=round(sarasas[i].vid);
    } 
}

void rusiavimas (vector<Studentas> sarasas, vector<Studentas> &vargsiukai, vector<Studentas> &galvociai){
auto start = std::chrono::high_resolution_clock::now(); auto st=start;
for(int i=0;i<sarasas.size();i++){
    if(sarasas[i].galutinis>=5) galvociai.push_back(sarasas[i]);
    if(sarasas[i].galutinis<5) vargsiukai.push_back(sarasas[i]);
}
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; // Skirtumas (s)
cout<<"Rusiavimas uztruko: "<<diff.count()<<endl;
sarasas.erase (sarasas.begin(),sarasas.begin()+sarasas.size());
}

void vSpausdinimas (vector<Studentas> vargsiukai,bool vm, int N){
    string temp; 
    std::ofstream ofs ("vargsiukai" + std::to_string(N) + ".txt", std::ofstream::out);
if(vm==true)
ofs<<"Pavarde        "<<"Vardas         "<<"Galutinis (Vid.)"<<endl;
if(vm==false)
ofs<<"Pavarde        "<<"Vardas         "<<"Galutinis (Med.)"<<endl;
ofs<<"---------------------------------------------------------------------"<<endl;
for(int i=0;i<vargsiukai.size();i++){
temp += vargsiukai[i].pavarde;
for(int j=0;j<15-(vargsiukai[i].pavarde.size());j++)temp +=" ";
temp += vargsiukai[i].vardas;
for(int j=0;j<20-(vargsiukai[i].vardas.size());j++)temp +=" ";
//temp += std::to_string(vargsiukai[i].galutinis);
ofs<<temp<<std::setprecision(0)<<vargsiukai[i].galutinis<<endl;
temp.clear();
}
ofs.close();
}

void gSpausdinimas (vector<Studentas> galvociai, bool vm, int N){
    string temp; 
    std::ofstream ofs ("galvociai" + std::to_string(N) + ".txt", std::ofstream::out);
if(vm==true)
ofs<<"Pavarde        "<<"Vardas         "<<"Galutinis (Vid.)"<<endl;
if(vm==false)
ofs<<"Pavarde        "<<"Vardas         "<<"Galutinis (Med.)"<<endl;
ofs<<"---------------------------------------------------------------------"<<endl;
for(int i=0;i<galvociai.size();i++){
temp += galvociai[i].pavarde;
for(int j=0;j<15-(galvociai[i].pavarde.size());j++)temp += " ";
temp += galvociai[i].vardas;
for(int j=0;j<20-(galvociai[i].vardas.size());j++)temp += " ";
//temp += std::to_string(galvociai[i].galutinis);
ofs<<temp<<std::setprecision(0)<<galvociai[i].galutinis<<endl;
temp.clear();
}
ofs.close();
}