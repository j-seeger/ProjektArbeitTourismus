#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include "datendtd.h"

void ClgetDtd::getDtd(ifstream &datei){



    enum zustand {inElement, elementName, erwarteAttribut, inAttribut, attributInfo,erwarteTag,tagName};
    enum zustand zustand;


    for (zaehler=0, zustand =inElement;;){
        datei.get(zeichen);

        switch(zeichen){

        case ' ':
            if (zustand==inElement){
                zustand=elementName;
                zaehler=0;

            }

            else if (zustand==elementName){
                zustand=erwarteTag;
                puffer[zaehler]='\0';
                cout <<"Element "<< puffer;
                letztes=new char [zaehler+1];
                strcpy(letztes,puffer);
                zaehler=0;

            }



            break;
         case '(':
            zustand=tagName;
            zaehler=0;
            break;


         case ')':

            zustand = inElement;
            puffer[zaehler]='\0';
            if (!strcmp(puffer,"#PCDATA"))
            {
                cout << " enthaelt: Daten"<< endl;
            }
            else cout << " enthaelt die Tags: "<< puffer<<endl;

            zaehler=0;
            break;

         case '\n':
            if (zustand==elementName){
                zustand=erwarteAttribut;
                zaehler=0;
            }
            else if (zustand==erwarteAttribut){

                puffer[zaehler]='\0';

             if (strcmp(puffer, ">"))
                {
                    cout<< "Element "<< letztes <<" enthaelt das Attribut: "<< puffer<<endl;
                   zustand=erwarteAttribut;
                }
                else zustand=inElement;
                zaehler=0;
            }

            else {
                zustand = inElement;
                zaehler=0;
            }
            break;

         default:
            puffer[zaehler]=zeichen;
            zaehler++;
            break;


        }

    }



}
