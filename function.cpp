#include "header.h"

void kurimas (){
int x;
srand (time(NULL));
string temp;
std::ofstream ofs ("stud" + std::to_string(N) + ".txt");
auto start = std::chrono::high_resolution_clock::now(); auto st=start;
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
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; // Skirtumas (s)
cout<<"Failo kurimas uztruko: "<<diff.count()<<endl;
}

void skaitymas (vector<Studentas> &sarasas, int &size) {
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
    tempStruct[0].vardas= temp;
    inf>>temp;
    tempStruct[0].pavarde= temp;
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

void rikiavimas (vector<Studentas> &sarasas, int size){
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;

    for(int i=0;i<size;i++){
        for(int j=i+1;j<size-i;j++){
            if(sarasas[j].pavarde<sarasas[j++].pavarde){
            std::swap(sarasas[j++],sarasas[j]);
}}}
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; // Skirtumas (s)
cout<<"Rikiavimas uztruko: "<<diff.count()<<endl;
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

double medianaGalutinis (vector<Studentas> &sarasas, int size) {
     for(int i=0;i<sarasas.size();i++){
    sort(sarasas[i].nd.begin(),sarasas[i].nd.end());
    if(sarasas[i].nd.size()%2==0 && sarasas[i].nd.size()!=0) {
       sarasas[i].med=((sarasas[i].nd[(sarasas[i].nd.size())/2]+sarasas[i].nd[(sarasas[i].nd.size())/2-1])*1.00/2)*0.4+sarasas[i].egz*0.6;
    }
    else if (sarasas[i].nd.size()%2!=0 && sarasas[i].nd.size()!=0) sarasas[i].med=(sarasas[i].nd[(sarasas[i].nd.size())/2])*0.4+sarasas[i].egz*0.6;
    if(sarasas[i].nd.size()==0) sarasas[i].med=0.6*sarasas[i].egz;
    sarasas[i].galutinis=round(sarasas[i].med);
    }
}

void rusiavimas (vector<Studentas> sarasas, vector<Studentas> &vargsiukai, vector<Studentas> &galvociai){
std::ofstream ofs ("vargsiukai.txt", std::ofstream::out);
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

void vSpausdinimas (vector<Studentas> vargsiukai,bool vm){
    string temp; 
    std::ofstream ofs ("vargsiukai.txt", std::ofstream::out);
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
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
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; // Skirtumas (s)
cout<<"Vargsiuku irasymas uztruko: "<<diff.count()<<endl;
}

void gSpausdinimas (vector<Studentas> galvociai, bool vm){
    string temp; 
    std::ofstream ofs ("galvociai.txt", std::ofstream::out);
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
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
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; // Skirtumas (s)
cout<<"Galvociu irasymas uztruko: "<<diff.count()<<endl;
}
