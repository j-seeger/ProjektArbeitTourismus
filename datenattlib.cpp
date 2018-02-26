#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <datenatt.h>


int ClgetAttlist::getAttlist(
char                    *eingabe)
{
char puffer[1000];
int zaehler;
enum zustand {inName, attributName, erwarteAtributWert,attributWert};
enum zustand zustand;

for (zaehler=0,zustand=inName,anzahlatt=0;*eingabe!='\0';
//for (zaehler=0,zustand=inName;*eingabe!='\0';
     eingabe=eingabe+1)
   {

  switch(*eingabe)
     {
  case ' ':
    if (zustand ==inName)
       {
        zustand = attributName;
        *eingabe='\0';
        zaehler =0;
       }
   else if(zustand==attributWert)
       {
      puffer[zaehler]=*eingabe;
      zaehler++;
       }
      break;

  case '=':
           if (zustand==attributName)
            {
            zustand=erwarteAtributWert;
            puffer [zaehler]='\0';
            //cout << "attributname: "<< puffer << endl;
            attname[anzahlatt] = new char[zaehler+1];
            strcpy(attname[anzahlatt],puffer);
            zaehler =0;
            }
         //else if (zustand==attributWert)
         //  {
         //      puffer[zaehler]=*eingabe;
         //      zaehler++;
         //  }
              break;
   case '"':
           if (zustand == erwarteAtributWert)
           {
               zustand= attributWert;
               zaehler=0;
           }
           else if (zustand==attributWert)
           {
             zustand=attributName;
             puffer [zaehler]='\0';
             attwert[anzahlatt] = new char[zaehler+1];
             strcpy(attwert[anzahlatt],puffer);
             zaehler =0;
             anzahlatt++;
             //cout << "Attributanzahl:" << anzahlatt <<endl;
           }
         break;

  default:
    if (zustand >=attributName)
        {
           puffer[zaehler]=*eingabe;
           zaehler++;

         }
       break;
      }
    }
return 1;
}
