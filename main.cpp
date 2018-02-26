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
ClgetDtd getDtd;




 cout << "Geben Sie einen Dateinamen ein:"<< endl;
 cin >> dateiname;
 eingabe.open(dateiname);

 if (strcmp(dateiname, "Koordinaten.txt")==0){
     getKoordinaten.druckeTxt(eingabe);

 }
 else if (strcmp(dateiname, "Daten.xml")==0)
 { getDaten.druckeXml(eingabe);

   for(;;)
     {

       if(getDaten.druckeXml(eingabe)==0)break;

         for (int i=0;i<getDaten.att.zahlAtt();i++)
             cout << "Attributname: " << getDaten.att.zeigeAttName(i)<<"\n" << " Attributwert: "
                  << getDaten.att.zeigeAttWert(i) << endl;
     }
}

 else if (strcmp(dateiname, "Daten.dtd")==0){
     getDtd.getDtd(eingabe);
 }

else {
     cout << "Die Datei '"<< dateiname << "' existiert nicht."<< endl;
 }

 eingabe.close();
 return 0;
}

