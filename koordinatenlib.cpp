#include <iostream>

using namespace std;
#include "koordinaten.h"
#include <fstream>



int ClKoordinaten::druckeTxt(ifstream &datei){


   enum zustand {ID, Land, Koordinaten};

   enum zustand zustand;



 for (zaehler=0, zustand=ID;;){
    datei.get(zeichen);
     if (datei.eof()) break;
     switch (zeichen){

     case ';':
         if (zustand == ID){
             zustand = Land;
             puffer[zaehler] = '\0';
             cout << puffer<< " ";
             zaehler = 0;
         }
         else if (zustand == Land){
             zustand = Koordinaten;
             puffer [zaehler] = '\0';
             cout << puffer << " ";
             zaehler = 0;

         }
         break;
     case '\n':
         zustand = ID;
         puffer [zaehler] = '\0';

         cout << puffer << endl;
         zaehler = 0;

break;
     default:
     puffer[zaehler] = zeichen;
     zaehler++;
       break;
}
}

}
