#include <iostream>

using namespace std;
#include <fstream>
#include <string.h>
#include <koordinaten.h>
#include <daten.h>
#include <datendtd.h>


int main()
{
 char dateiname [100];

ifstream eingabe;
ClgetXml getDaten;
ClKoordinaten getKoordinaten;
ClgetDtd *jetzt=NULL, *wurzel, *objekt;



 cout << "Geben Sie einen Dateinamen ein:"<< endl;
 cin >> dateiname;
 eingabe.open(dateiname);

 if (strcmp(dateiname, "Koordinaten.txt")==0){
     getKoordinaten.druckeTxt(eingabe);

 }
 else if (strcmp(dateiname, "Daten.xml")==0)
 { //getDaten.druckeXml(eingabe);

     if (getDaten.getXml(eingabe)!=0) getDaten.druckeXml(1);


}

 else if (strcmp(dateiname, "Daten.dtd")==0){
     wurzel=objekt->verarbeite(eingabe);

     for (jetzt=wurzel;jetzt!=NULL;jetzt=jetzt->getNext())
         jetzt->druckeDtd(0,wurzel);
 }

else {
     cout << "Die Datei '"<< dateiname << "' existiert nicht."<< endl;
 }

 eingabe.close();
 return 0;
}

