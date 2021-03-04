#include "header.h"

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
    if(ats!="Y" && ats!="y" && ats!="n" && ats!="N"){
        error = true;
        cout<<"Klaida! Netinkamas ivedimas. "<<endl;
    }
cin.clear();
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}while(error);

if(ats=="y" || ats=="Y"){
try {
    skaitymas(sarasas,size);
    } catch (const char* msg) {
    std::cerr << msg << endl;
    exit (EXIT_FAILURE);
}
}

if(ats=="n" || ats=="N"){  
vedimasRanka(sarasas,size);
}      

medianaGalutinis(sarasas,size);
vidurkisGalutinis(sarasas,size);
rikiavimas(sarasas,size);
spausdinimas(sarasas,size);

sarasas.erase (sarasas.begin(),sarasas.begin()+size);

return 0;
}
