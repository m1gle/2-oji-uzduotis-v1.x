#include "header.h"

struct Studentas {
string vardas, pavarde;
vector<int> nd;
double egz, galutinis,med,vid;
};

void vedimasRanka (vector<Studentas> &sarasas,int &size) {

int kiek,pazymiai,x;
string ats;
bool error,repeat;
string input;
srand (time(NULL));
size=0;
sarasas.push_back(Studentas());

do{
repeat=true;
cout<<"Iveskite studento varda: ";
cin>>sarasas[size].vardas;
cout<<"Iveskite studento pavarde: ";
cin>>sarasas[size].pavarde;
   do {
  cout<<"Ar zinomas namu darbu kiekis (y/n): ";
cin>>ats;
 error=false;
 if(ats!="Y" and ats!="y" and ats!="n" and ats!="N"){
    error = true;
     cout<<"Klaida! Netinkamas ivedimas. "<<endl;
}
cin.clear();
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}while(error);

if(ats=="y" or ats=="Y"){    //Jeigu žinomas studento pažymių kiekis
    do {
    cout<<"Iveskite namu darbu kieki: ";
    cin>>pazymiai;
    error=false;
    if(cin.fail()){
        error = true;
        cout<<"Klaida! Netinkamas ivedimas. "<<endl;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}while(error);

 do {
    cout<<"Generuoti random reiksmes? (y/n): ";    //Random reikšmių generacija
    cin>>ats;
    error=false;
    if(ats!="Y" and ats!="y" and ats!="n" and ats!="N"){
        error = true;
        cout<<"Klaida! Netinkamas ivedimas. "<<endl;
    }
     cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}while(error);

if(ats=="y" or ats=="Y"){                           //Y- Random skaičių generacija
    for(int j=0;j<pazymiai;j++){
    x=rand()%10+1;
    sarasas[size].nd.push_back(int());
    sarasas[size].nd[j]=x;
}
cout<<"Sugeneruoti "<<pazymiai<<" pazymiai: ";
for(int j=0;j<pazymiai;j++) cout<<sarasas[size].nd[j]<<" ";
cout<<endl;
sarasas[size].egz=rand()%10+1;
cout<<"Sugeneruotas egzamino pazymys: "<<sarasas[size].egz<<endl;
}

if(ats=="n" or ats=="N"){                           //N- Skaičių įvedimas
cout<<"Iveskite "<<pazymiai<<" pazymius: ";
for(int j=0;j<pazymiai;j++){
sarasas[size].nd.push_back(int());
cin>>sarasas[size].nd[j];
}

 do {
    cout<<"Iveskite egzamino pazymi: ";
    cin>>sarasas[size].egz;
    error=false;
    if(cin.fail() or sarasas[size].egz>10 or sarasas[size].egz<1){
        error = true;
        cout<<"Klaida! Netinkamas ivedimas. "<<endl;
    }
     cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}while(error);
}
}

else if(ats=="n" or ats=="N"){                  //Nežinant pažymių kiekio
    do {
    cout<<"Generuoti random reiksmes? (y/n): ";    
    cin>>ats;
    error=false;
    if(ats!="Y" and ats!="y" and ats!="n" and ats!="N"){
        error = true;
        cout<<"Klaida! Netinkamas ivedimas. "<<endl;
    }
     cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}while(error);

if(ats=="N" or ats=="n"){       
    int n=0;   
    int x;                                //Įvedimas rankiniu būdu limitas 20 (neišsiaiškinau)
cout << "Iveskite skaicius, atskiriant juos 'enter', jeigu skaicius paskutinis, iveskite raide, arba skaiciu >10 arba <1: ";
 do {
    cin>>x;
    error=true;
    if(cin.fail() or x>10 or x<1){
    error = false;
    cout<<"Issaugota!"<<endl;
    }
    if(error==true) {
       sarasas[size].nd.push_back(int());
       sarasas[size].nd[n]=x;
       n++;
    }
     cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}while(error);

 do {
    cout<<"Iveskite egzamino pazymi: ";
    cin>>sarasas[size].egz;
    error=false;
    if(cin.fail() or sarasas[size].egz>10 or sarasas[size].egz<1){
        error = true;
        cout<<"Klaida! Netinkamas ivedimas. "<<endl;
    }
     cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}while(error);
}

if(ats=="Y" or ats=="y"){                   ///Random reikšmių generacija (?)
    int j=0;
do{
    x=rand()%10;
    if(x!=0){
    sarasas[size].nd.push_back(int());
    sarasas[size].nd[j]=x;
    }
    j++;
}while(x!=0);
cout<<"Sugeneruoti "<<sarasas[size].nd.size()<<" pazymiai: ";
for(int j=0;j<sarasas[size].nd.size();j++) cout<<sarasas[size].nd[j]<<" ";
cout<<endl;
sarasas[size].egz=rand()%10+1;
cout<<"Sugeneruotas egzamino pazymys: "<<sarasas[size].egz<<endl;
}
}
do {
    cout<<"Prideti mokini? (y/n) ";
    cin>>ats;
    error=false;
    if(ats!="Y" and ats!="y" and ats!="n" and ats!="N"){
        error = true;
        cout<<"Klaida! Netinkamas ivedimas. "<<endl;
    }
}while(error);
if(ats=="n" or ats=="n") repeat=false;
if(ats=="y" or ats=="Y") sarasas.push_back(Studentas());
size++;
}while (repeat);

}

void skaitymas (vector<Studentas> &sarasas, int &size) {
size=0;
string eil;
std::ifstream inf ("kursiokai.txt");
getline(inf,eil);
while (inf){
if(!inf.eof()){
sarasas.push_back(Studentas());
inf>>sarasas[size].vardas>>sarasas[size].pavarde;
for(int j=0;j<15;j++) {
sarasas[size].nd.push_back(int());
inf>>sarasas[size].nd[j];
}
inf>>sarasas[size].egz;
size++;
inf.ignore();
}
else break;
}
inf.close();
}

void rikiavimas (vector<Studentas> &sarasas, int size){
for(int i=0;i<size-1;i++){
for(int j=i+1;j<size;j++){
if(sarasas[j].pavarde<sarasas[i].pavarde){
std::swap(sarasas[i],sarasas[j]);
}}}
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
    } 
}

double medianaGalutinis (vector<Studentas> &sarasas, int size) {
     for(int i=0;i<sarasas.size();i++){
    sort(sarasas[i].nd.begin(),sarasas[i].nd.end());
    if(sarasas[i].nd.size()%2==0 and sarasas[i].nd.size()!=0) {
       sarasas[i].med=((sarasas[i].nd[(sarasas[i].nd.size())/2]+sarasas[i].nd[(sarasas[i].nd.size())/2-1])*1.00/2)*0.4+sarasas[i].egz*0.6;
    }
    else if (sarasas[i].nd.size()%2!=0 and sarasas[i].nd.size()!=0) sarasas[i].med=(sarasas[i].nd[(sarasas[i].nd.size())/2])*0.4+sarasas[i].egz*0.6;
    if(sarasas[i].nd.size()==0) sarasas[i].med=0.6*sarasas[i].egz;
    }
}

int main(){
vector<Studentas> sarasas;
int kiek,pazymiai,x,size;
string ats;
bool error,repeat;
string input;

do {
    cout<<"Skaityti faila (y) ar ivesti ranka (n) ?: ";
    cin>>ats;
    error=false;
    if(ats!="Y" and ats!="y" and ats!="n" and ats!="N"){
        error = true;
        cout<<"Klaida! Netinkamas ivedimas. "<<endl;
    }
cin.clear();
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}while(error);
cout<<endl;

if(ats=="y" or ats=="Y"){
skaitymas(sarasas,size);
}

if(ats=="n" or ats=="N"){  
vedimasRanka(sarasas,size);
}      
 //Randa medianą
medianaGalutinis(sarasas,size);
vidurkisGalutinis(sarasas,size);
rikiavimas(sarasas,size);
//Spausdinimas
cout<<"Pavarde        "<<"Vardas         "<<"Galutinis (Vid.) | Galutinis (Med.)"<<endl;
cout<<"---------------------------------------------------------------------"<<endl;
for(int i=0;i<sarasas.size();i++){
cout<<sarasas[i].pavarde;
for(int j=0;j<15-(sarasas[i].pavarde.size());j++)cout<<" ";
cout<<sarasas[i].vardas;
for(int j=0;j<15-(sarasas[i].vardas.size());j++)cout<<" ";
cout<<setprecision(3)<<sarasas[i].vid;
for(int j=0;j<15;j++)cout<<" ";
cout<<setprecision(3)<<sarasas[i].med<<endl;
}

sarasas.erase (sarasas.begin(),sarasas.begin()+size);

return 0;
}
