#include "header.h"

int main(){
vector<Studentas> sarasas, vargsiukai, galvociai;
int kiek,pazymiai,x,size;
string ats;
bool error,repeat;
string input;

auto start = std::chrono::high_resolution_clock::now(); auto st=start;
kurimas();
try {
    skaitymas(sarasas,size);
    } catch (const char* msg) {
    std::cerr << msg << endl;
    exit (EXIT_FAILURE);
}

vidurkisGalutinis(sarasas,size);
//rikiavimas(sarasas,size);
rusiavimas(sarasas,vargsiukai,galvociai);
vSpausdinimas(vargsiukai,true);
gSpausdinimas(galvociai,true);
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; // Skirtumas (s)
cout<<"Bendrai uztruko: "<<diff.count()<<endl;
galvociai.erase (galvociai.begin(),galvociai.begin()+galvociai.size());
vargsiukai.erase (vargsiukai.begin(),vargsiukai.begin()+vargsiukai.size());
return 0;
}
