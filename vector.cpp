#include "header.h"

struct Studentas {
string vardas, pavarde;
vector<int> nd;
double egz, galutinis;
};

double vidurkis (int kiek, vector<int> a) {
double v;
double sum=0;
 for(int i=0;i<kiek;i++){
    sum=sum+a[i];
 }
 v=sum*1.00/kiek;
return v;
}

int main(){
vector<Studentas> sarasas;
int kiek,pazymiai,x;
string ats;
bool error,repeat;
string input;
srand (time(NULL));
int size=0;
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

do {
    cout<<"Ar norite suskaiciuoti mediana? (y/n): ";
    cin>>ats;
    error=false;
    if(ats!="Y" and ats!="y" and ats!="n" and ats!="N"){
        error = true;
        cout<<"Klaida! Netinkamas ivedimas. "<<endl;
    }
}while(error);

cout<<endl;
if(ats=="y" or ats=="Y"){         //Randa medianą
 for(int i=0;i<sarasas.size();i++){
    sort(sarasas[i].nd.begin(),sarasas[i].nd.end());
    if(sarasas[i].nd.size()%2==0 and sarasas[i].nd.size()!=0) {
       sarasas[i].galutinis=((sarasas[i].nd[(sarasas[i].nd.size())/2]+sarasas[i].nd[(sarasas[i].nd.size())/2-1])*1.00/2)*0.4+sarasas[i].egz*0.6;
    }
    else if (sarasas[i].nd.size()%2!=0 and sarasas[i].nd.size()!=0) sarasas[i].galutinis=(sarasas[i].nd[(sarasas[i].nd.size())/2])*0.4+sarasas[i].egz*0.6;
    if(sarasas[i].nd.size()==0) sarasas[i].galutinis=0.6*sarasas[i].egz;
    }
    cout<<"Pavarde        "<<"Vardas         "<<"Galutinis (Med.)"<<endl;
}
if(ats=="n" or ats=="N"){       //Suskaičiuoja vidurkį
    for(int i=0;i<sarasas.size();i++){
      if(sarasas[i].nd.size()==0) sarasas[i].galutinis=0.6*sarasas[i].egz;
      else sarasas[i].galutinis=0.4*vidurkis((sarasas[i].nd.size()),sarasas[i].nd)+0.6*sarasas[i].egz;
    }
    cout<<"Pavarde        "<<"Vardas         "<<"Galutinis (Vid.)"<<endl;
}

//Spausdinimas
cout<<"-----------------------------------------------"<<endl;
for(int i=0;i<sarasas.size();i++){
cout<<sarasas[i].pavarde;
for(int j=0;j<15-(sarasas[i].pavarde.size());j++)cout<<" ";
cout<<sarasas[i].vardas;
for(int j=0;j<15-(sarasas[i].vardas.size());j++)cout<<" ";
cout<<setprecision(3)<<sarasas[i].galutinis<<endl;
}
return 0;
}
