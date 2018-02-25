#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include "dtd.h"

void ClgetDtd::getDtd(ifstream &datei){


    enum zustand {direktive, element, abhaengig, noise};

    //enum zustand {inElement, elementName, erwarteAttribut, erwarteTag,tagName};
    enum zustand zustand=noise; //was heißt das??


    for (datei.get(zeichen);!datei.eof();datei.get(zeichen))
    {


        switch(zeichen){

        case '<':
               zustand=direktive;
               zaehler=0;
               break;
            case '>':
               if (zustand!=noise)
                  {
              puffer[zaehler]='\0';
              cout << puffer << ".";
              }

               zustand=noise;
               break;
            case ' ':
               puffer[zaehler]='\0';
               zaehler=0;
               switch(zustand)
                  {
               case direktive:
                  if (strcmp(puffer,"!ELEMENT"))
                 {
                 cout << endl << "Diese Direktive verstehe ich nicht: " << puffer;
                 zustand=noise;
                 }
              else zustand=element;
                  break;
               case element:
                  cout << endl << "Element " << puffer << " enthält die Tags: ";
              zustand=abhaengig;
                  break;
               case abhaengig:
                  cout << puffer << ", ";
                  break;
              }
               break;

            default:
               if (zustand!=noise) puffer[zaehler] = zeichen;
               zaehler++;
               break;
               }
            }
        cout << endl;
        }








