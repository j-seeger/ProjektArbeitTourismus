#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include "dtd.h"

int main()
{
    char dateiname [10];
    ifstream eingabe;
    ClgetDtd getDtd;

    cout << "Geben Sie einen Dateinamen ein:"<< endl;
    cin >> dateiname;
    eingabe.open(dateiname);

    if (strcmp(dateiname, "Daten.dtd")==0){
         getDtd.getDtd(eingabe);
         cout << Hallo<< endl;
     }

    else {
         cout << "Die Datei '"<< dateiname << "' existiert nicht."<< endl;
     }

     eingabe.close();
     return 0;
}
