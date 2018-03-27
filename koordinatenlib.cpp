#include <iostream>

using namespace std;
#include "koordinaten.h"
#include <fstream>




int ClKoordinaten::getTxt(ifstream &datei){

    char zeichen;
    char puffer [100];
    int zaehler;

   enum zustand {ID, Land, Koordinaten};

   enum zustand zustand;



 for (zaehler=0, zustand=ID, zahl=0;;){
    datei.get(zeichen);
     if (datei.eof())return 0;


     switch (zeichen){

     case ';':
         if (zustand == ID){
             zustand = Land;
             puffer[zaehler] = '\0';

             identification[zahl]=new char[zaehler+1];
             strcpy(identification[zahl],puffer);

             zaehler = 0;
         }
         else if (zustand == Land){
             zustand = Koordinaten;
             puffer [zaehler] = '\0';

             attName[zahl]=new char [zaehler +1];
             strcpy(attName[zahl],puffer);

             zaehler = 0;

         }
         break;
     case '\n':
         zustand = ID;
         puffer [zaehler] = '\0';

         tagInhalt[zahl]=new char [zaehler+1];
         strcpy(tagInhalt[zahl],puffer);

           zaehler = 0;
          zahl++;

break;
     default:
     puffer[zaehler] = zeichen;
     zaehler++;
       break;
}
}
 return 0;
}



void ClKoordinaten::druckeTxt(){



    for (int i=0; i<getZahl();i++)
    {
        cout << "ID: "<< getID(i)<< " Land: "<< getAttribut(i) << " Koordinaten: "<< getTagInhalt(i)<<endl;
    }


}

