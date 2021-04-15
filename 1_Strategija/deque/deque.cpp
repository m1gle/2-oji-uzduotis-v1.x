#include "header.h"

int main(){
deque<Studentas> sarasas, vargsiukai, galvociai;
int kiek,pazymiai,x,size;
string ats;
bool error,repeat;
string input;
//kurimas();
int N = 100;
for(int i = 0; i < 5 ; i++) {
cout<<N<<" studentu dydzio failas: "<<endl;
auto start = std::chrono::high_resolution_clock::now(); auto st=start;
try {
    skaitymas(sarasas,size,N);
    } catch (const char* msg) {
    std::cerr << msg << endl;
    exit (EXIT_FAILURE);
}
vidurkisGalutinis(sarasas,size);
rusiavimas(sarasas,vargsiukai,galvociai);
sarasas.clear();
vSpausdinimas(vargsiukai,true,N);
gSpausdinimas(galvociai,true,N);
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; // Skirtumas (s)
cout<<N<<" deque bendrai uztruko: "<<diff.count()<<endl;
cout<<endl;
galvociai.clear();
vargsiukai.clear();
N=N*10;
}
return 0;
}
