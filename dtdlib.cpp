#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include "datendtd.h"


ClgetDtd::ClgetDtd(char*string)
{
zahl=0;
zahlAttribute=0;
strcpy(name,string);
status=frei;
naechstes=NULL;
}

ClgetDtd * ClgetDtd::verarbeite(ifstream &datei)
{
char puffer [1000];
char zeichen, letztes;
int zaehler;
enum zustand {direktive, element, attribut, abhaengigElement, abhaengigAttribut, noise};

enum zustand zustand = noise;
ClgetDtd *jetzt=NULL, *wurzel, *neu;

for (datei.get(zeichen);!datei.eof();datei.get(zeichen))
 {
  switch(zeichen)
   {
     case '<':
              zustand=direktive;
              zaehler=0;
              break;
     case '>':
              if (letztes!=' ')
              zustand=noise;
              break;
     case ' ':
              if (letztes==' ')continue;
              puffer[zaehler]='\0';
              zaehler=0;
              switch(zustand)
               {
                case direktive:
                            if (!strcmp(puffer,"!ELEMENT"))zustand=element;
                            else if (!strcmp(puffer, "!ATTLIST"))zustand=attribut;
                            else
                            {
                                 cout << "Diese Dierektive verstehe ich nicht"<<endl;
                                zustand =noise;
                             }
                            break;
                case element:
                            neu=new ClgetDtd(puffer);
                            if (jetzt!=NULL)jetzt->setNext(neu);
                            else wurzel=neu;
                            jetzt=neu;
                            zustand=abhaengigElement;
                            break;
                case attribut:
                            if (wurzel==NULL) neu=NULL;
                            else neu=wurzel->sucheElement(puffer,wurzel);
                            if (neu==NULL) zustand=noise;
                            else
                             {
                                zustand=abhaengigAttribut;
                                jetzt=neu;
                             }
                            break;
                case abhaengigAttribut:
                            jetzt->addAttribute(puffer);
                            break;
                case noise:
                            break;
                }
                break;

     case '(':
              zustand=abhaengigElement;
              zaehler=0;
              break;
     case ',':
             zustand=abhaengigElement;
             puffer[zaehler]='\0';
             jetzt->addTag(puffer);
             zaehler=0;
             break;
    case ')':
            zustand=noise;
            puffer[zaehler]='\0';
            jetzt->addTag(puffer);
            zaehler=0;
            break;
   case '\n':
            if (zustand == abhaengigAttribut)
                {
                puffer[zaehler]='\0';
                zaehler=0;
                jetzt->addAttribute(puffer);
                }
            break;

   default:
           if (zustand!=noise) puffer[zaehler] = zeichen;
           zaehler++;
           break;
   }
 letztes=zeichen;
 }
return wurzel;
}


void ClgetDtd::addTag(char*string)
{
strcpy(tags[zahl],string);
zahl++;
}

void ClgetDtd::addAttribute(char *string)
{
strcpy(attributes[zahlAttribute],string);
zahlAttribute++;
}

void ClgetDtd::druckeDtd(int ebene,ClgetDtd *wurzel)
{
ClgetDtd *abhaengig;
int j,i;

status=inBearbeitung;
for (j=0;j<ebene;j++)cout <<"|   ";
cout <<"Element " << name << " erlaubt die Attribute: "<< endl;

for (i=0;i<zahlAttribute;i++)
 {
  for (j=0; j<ebene; j++)cout << "|   ";
  cout << "   " << attributes[i] << endl;
 }
for (j=0; j<ebene; j++)cout << "|   ";
cout << "und enthaelt die Tags: "<< endl;
for (i=0;i<zahl;i++)
 {
  for (j=0;j<ebene;j++) cout << "|   ";
  cout <<"   "<< tags[i] << endl;
  abhaengig=sucheElement(tags[i],wurzel); // sorgt dafür, dass alles dreifach gelesen wird und die Verbindungen erkannt werden
  if (abhaengig != NULL) abhaengig->druckeDtd(ebene+1,wurzel);
 }
status=frei;
}

ClgetDtd *ClgetDtd::sucheElement(char *suche,ClgetDtd *element)
{
if (element==NULL)return NULL;
if (!strcmp(suche,element->name))
 {
    if(element->status==frei)return element;
    else return NULL;
  }
return sucheElement(suche,element->naechstes);
}

int ClgetDtd::elementIstErlaubt(char *name)
{
    for (int i=0; i<zahl;i++)

        if(!strcmp(name,tags[i]))return i;
         return -1;
}
int ClgetDtd::attributeIstErlaubt(
char                            *name)
{
for (int i=0;i<zahlAttribute;i++)
    if (!strcmp(name,attributes[i])) return i;

return -1;

}
