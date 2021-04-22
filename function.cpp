#include "header.h"

void skaitymas (vector<Studentas> &sarasas, int n) {
int size=0;
int i;
string temp;
int tempr;
string eil,line;
vector<Studentas> tempClass;
tempClass.push_back(Studentas());
auto start = std::chrono::high_resolution_clock::now(); auto st=start;
std::ifstream inf ("stud" + std::to_string(n) + ".txt");
if(!inf.good()) throw "Nerastas failas!";
getline(inf,eil);
    while(!inf.eof()){
    inf>>temp;
    tempClass[0].setPavarde(temp);
    inf>>temp;
    tempClass[0].setVardas(temp);
        while(!inf.eof()){
            inf>>tempr;
            if (tempr>10 || tempr<1) throw "Netinkamas pazymis skaitymo faile! Pazymis turi buti >=0 && <=10!";
            if(inf.peek()=='\n'||inf.peek() == inf.eof()){
                tempClass[0].setEgzaminas(tempr);
                break;
            }
            tempClass[0].setPazymys(tempr); 
            i++;
        }
    sarasas.push_back(tempClass[0]);
    tempClass[0] = {};
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

double vidurkisGalutinis (vector<Studentas> &sarasas){
    double vid;
   for(int i=0;i<sarasas.size();i++){
      if(sarasas[i].getPazymiai().size()==0) vid=0.6*sarasas[i].getEgzaminas();
      else vid=0.4*vidurkis((sarasas[i].getPazymiai().size()),sarasas[i].getPazymiai())+0.6*sarasas[i].getEgzaminas();
      sarasas[i].setGalutinis(round(vid));
    } 
}

void rusiavimas (vector<Studentas> sarasas, vector<Studentas> &vargsiukai, vector<Studentas> &galvociai){
auto start = std::chrono::high_resolution_clock::now(); auto st=start;
for(int i=0;i<sarasas.size();i++){
    if(sarasas[i].getGalutinis()>=5) galvociai.push_back(sarasas[i]);
    if(sarasas[i].getGalutinis()<5) vargsiukai.push_back(sarasas[i]);
}
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; // Skirtumas (s)
cout<<"Rusiavimas uztruko: "<<diff.count()<<endl;
}

void vSpausdinimas (vector<Studentas> vargsiukai, int n){
    string temp; 
    std::ofstream ofs ("vargsiukai" + std::to_string(n) + ".txt", std::ofstream::out);
ofs<<"Pavarde        "<<"Vardas         "<<"Galutinis (Vid.)"<<endl;
ofs<<"---------------------------------------------------------------------"<<endl;
for(int i=0;i<vargsiukai.size();i++){
temp += vargsiukai[i].getPavarde();
for(int j=0;j<15-(vargsiukai[i].getPavarde().size());j++)temp +=" ";
temp += vargsiukai[i].getVardas();
for(int j=0;j<20-(vargsiukai[i].getVardas().size());j++)temp +=" ";
temp += std::to_string(vargsiukai[i].getGalutinis());
ofs<<temp<<endl;
temp.clear();
}
ofs.close();
}

void gSpausdinimas (vector<Studentas> galvociai, int n){
    string temp; 
    std::ofstream ofs ("galvociai" + std::to_string(n) + ".txt", std::ofstream::out);
ofs<<"Pavarde        "<<"Vardas         "<<"Galutinis (Vid.)"<<endl;
ofs<<"---------------------------------------------------------------------"<<endl;
for(int i=0;i<galvociai.size();i++){
temp += galvociai[i].getPavarde();
for(int j=0;j<15-(galvociai[i].getPavarde().size());j++)temp +=" ";
temp += galvociai[i].getVardas();
for(int j=0;j<20-(galvociai[i].getVardas().size());j++)temp +=" ";
temp += std::to_string(galvociai[i].getGalutinis());
ofs<<temp<<endl;
temp.clear();
}
ofs.close();
}
