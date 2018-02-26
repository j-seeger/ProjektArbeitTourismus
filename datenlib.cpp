#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <daten.h>


int ClgetXml::druckeXml(ifstream &datei){

    char puffer [1000];
    char zeichen;
    int zaehler;
    enum zustand {startTag,tagInhalt,inAttribut, endTag,noise};

    enum zustand zustand;

    for (zaehler=0;;){
       datei.get(zeichen);
       if (datei.eof()) break;
       switch (zeichen){

       case '<':
           datei.get(zeichen);
           if (zeichen =='/')
           {
               zustand=endTag;
               if (zaehler-1>0)
               {
               puffer[zaehler]='\0';
//               inhaltTag[anzahlTag]=new char [zaehler+1];
//               strcpy(inhaltTag[anzahlTag],puffer);
               cout << "Tag Inhalt: " << puffer << endl;
              }

            }
           else {
           datei.putback(zeichen);
           zustand=startTag;
           }
            zaehler=0;
          break;


        case '>':


           if (zustand==startTag){
              //zustand = tagInhalt;
               puffer [zaehler]='\0';
//               tagStart[anzahlTag]=new char[zaehler+1];
//               strcpy(tagStart[anzahlTag],puffer);
               cout << "Tag Name: " << puffer << endl;
             att.getAttlist(puffer);
             zaehler =0;
           }


           else if (zustand==endTag){
               zustand=startTag;
               puffer [zaehler]='\0';
               zaehler=0;
                       }


            break;



       default:

           puffer[zaehler]=zeichen;
           zaehler++;

           break;

       }


    }
return 0;
}

