#include "header.h"

int main(){
vector<Studentas> sarasas, vargsiukai, galvociai;
int kiek,pazymiai,x,size;
string ats;
bool error,repeat;
string input;
//kurimas();
try {
    skaitymas(sarasas,size);
    } catch (const char* msg) {
    std::cerr << msg << endl;
    exit (EXIT_FAILURE);
}

vidurkisGalutinis(sarasas,size);
rusiavimas(sarasas,vargsiukai,galvociai);
vSpausdinimas(vargsiukai,true);
gSpausdinimas(galvociai,true);
galvociai.erase (galvociai.begin(),galvociai.begin()+galvociai.size());
vargsiukai.erase (vargsiukai.begin(),vargsiukai.begin()+vargsiukai.size());
return 0;
}
