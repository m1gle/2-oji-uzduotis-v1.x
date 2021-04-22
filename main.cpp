#include "header.h"

int main(){
int n=100;
vector <Studentas> sarasas,vargsiukai,galvociai;
for(int i=0;i<5;i++){
    cout<<n<<" studentu dydzio failas: "<<endl;
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    try {
    skaitymas(sarasas,n);
    } catch (const char* msg) {
    std::cerr << msg << endl;
    exit (EXIT_FAILURE);
    }
    vidurkisGalutinis(sarasas);
    rusiavimas(sarasas,vargsiukai,galvociai);
    sarasas.clear();
    vSpausdinimas(vargsiukai,n);
    gSpausdinimas(galvociai,n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    cout<<n<<" vector bendrai uztruko: "<<diff.count()<<endl;
    cout<<endl;
    vargsiukai.clear();
    galvociai.clear();
    n=n*10;
}
return 0;
}