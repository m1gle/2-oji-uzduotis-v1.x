#include "header.h"

struct Studentas {
string vardas, pavarde;
int* nd;
int kiekis;
double egz, galutinis;
};

double vidurkis (int kiek, int A[]) {
double v;
double sum=0;
 for(int i=0;i<kiek;i++){
    sum=sum+A[i];
 }
 v=sum*1.00/kiek;
return v;
}

void rikiuoti(int x[], int n) {
 bool exchanges;
    do {
        exchanges = false;
       for (int i=0; i<n-1; i++) {
          if (x[i] > x[i+1]) {
             double temp = x[i]; x[i] = x[i+1]; x[i+1] = temp;
             exchanges = true; 
          }
       }
    } while (exchanges);
}

int main(){
int kiek,pazymiai,x;
string ats;
bool error;
srand (time(NULL));


//Duomenų įvestis
do {
    error = false;
    cout<<"Iveskite studentu kieki: ";
    cin>>kiek;
    if(cin.fail() or kiek<1)
    {
        error = true;
        cout<<"Klaida! Netinkamas ivedimas. "<<endl;
        }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}while(error);

Studentas* sarasas = new Studentas[kiek];
cout<<"Iveskite studento varda ir pavarde: ";
for(int i=0;i<kiek;i++){
    cin>>sarasas[i].vardas;
    cin>>sarasas[i].pavarde;
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

sarasas[i].kiekis=pazymiai;
sarasas[i].nd=new int [pazymiai];
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
    sarasas[i].nd[j]=x;
}
cout<<"Sugeneruoti "<<pazymiai<<" pazymiai: ";
for(int j=0;j<pazymiai;j++) cout<<sarasas[i].nd[j]<<" ";
cout<<endl;
sarasas[i].egz=rand()%10+1;
cout<<"Sugeneruotas egzamino pazymys: "<<sarasas[i].egz<<endl;
}

if(ats=="n" or ats=="N"){                           //N- Skaičių įvedimas
cout<<"Iveskite "<<pazymiai<<" pazymius: ";
for(int j=0;j<pazymiai;j++){
cin>>sarasas[i].nd[j];
}

// for(int j=0;j<pazymiai;j++){                        //Tikrinami ar pazymiai tinkami ivesti
// do {
//     error=false;

//     if(cin.fail() or sarasas[i].nd[j]>10 or sarasas[i].nd[j]<1){
//         error = true;
//         cout<<"Klaida! Netinkamas "<<j+1<<" elementas, iveskite per nauja."<<endl;
//         cin>>sarasas[i].nd[j];
//     }
//     cin.clear();
//     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// }while(error);
// }


 do {
    cout<<"Iveskite egzamino pazymi: ";
    cin>>sarasas[i].egz;
    error=false;
    if(cin.fail() or sarasas[i].egz>10 or sarasas[i].egz<1){
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
    sarasas[i].nd=new int [20];
    sarasas[i].kiekis=20;        
    int n=0;                                     //Įvedimas rankiniu būdu limitas 20 (neišsiaiškinau)
 cout << "Iveskite skaicius, atskiriant juos 'enter', jeigu skaicius paskutinis, iveskite raide, arba skaiciu >10 arba <1: ";
 do {
    cin>>sarasas[i].nd[n];
    error=true;
    if(cin.fail() or sarasas[i].nd[n]>10 or sarasas[i].nd[n]<1){
    error = false;
    cout<<"Issaugota!"<<endl;
    }
    if(error==true) n++;
     cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}while(error);
sarasas[i].kiekis=n;
 do {
    cout<<"Iveskite egzamino pazymi: ";
    cin>>sarasas[i].egz;
    error=false;
    if(cin.fail() or sarasas[i].egz>10 or sarasas[i].egz<1){
        error = true;
        cout<<"Klaida! Netinkamas ivedimas. "<<endl;
    }
     cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}while(error);
}

if(ats=="Y" or ats=="y"){                   ///Random reikšmių generacija (?)
    pazymiai=rand()%20;
    sarasas[i].nd=new int [pazymiai];
    sarasas[i].kiekis=pazymiai;
for(int j=0;j<pazymiai;j++){
    x=rand()%10+1;
    sarasas[i].nd[j]=x;
}
cout<<"Sugeneruoti "<<pazymiai<<" pazymiai: ";
for(int j=0;j<pazymiai;j++) cout<<sarasas[i].nd[j]<<" ";
cout<<endl;
sarasas[i].egz=rand()%10+1;
cout<<"Sugeneruotas egzamino pazymys: "<<sarasas[i].egz<<endl;
}
}

if(i!=kiek-1) cout<<"Kitas studentas: ";
}

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
 for(int i=0;i<kiek;i++){
    rikiuoti(sarasas[i].nd,sarasas[i].kiekis);
    if(sarasas[i].kiekis%2==0) sarasas[i].galutinis=((sarasas[i].nd[sarasas[i].kiekis/2]+sarasas[i].nd[sarasas[i].kiekis/2-1])*1.00/2)*0.4+sarasas[i].egz*0.6;
    else sarasas[i].galutinis=(sarasas[i].nd[sarasas[i].kiekis/2])*0.4+sarasas[i].egz*0.6;
    }
    cout<<"Pavarde        "<<"Vardas         "<<"Galutinis (Med.)"<<endl;
}

if(ats=="n" or ats=="N"){       //Suskaičiuoja vidurkį
    for(int i=0;i<kiek;i++){
    sarasas[i].galutinis=0.4*vidurkis(sarasas[i].kiekis,sarasas[i].nd)+0.6*sarasas[i].egz;
    }
    cout<<"Pavarde        "<<"Vardas         "<<"Galutinis (Vid.)"<<endl;
}

//Spausdinimas
cout<<"-----------------------------------------------"<<endl;
for(int i=0;i<kiek;i++){
cout<<sarasas[i].pavarde;
for(int j=0;j<15-(sarasas[i].pavarde.size());j++)cout<<" ";
cout<<sarasas[i].vardas;
for(int j=0;j<15-(sarasas[i].vardas.size());j++)cout<<" ";
cout<<setprecision(3)<<sarasas[i].galutinis<<endl;
}
delete[] sarasas;

return 0;
}
