#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <daten.h>


void convert();

int main()
{
 char aktion [10];
 char dateiname [10];
 char kategorie [10];
 char sucheingabe[100];
 int menue;
ofstream ausgabe;
ifstream eingabe;
ClgetXml getDaten;
ClKoordinaten getKoordinaten;
ClgetDtd *jetzt=NULL, *wurzel, *objekt;


//- Menü -

menue=0;
while (menue==0){

 cout << "MENUE"<<endl;
 cout << "Herzlich Willkommen im Tourismus-Informations-Programm des Regierungsbezirks Koeln"<< endl;
 cout << "Was moechten Sie als naechstes tun?"<<endl;
 cout << "XML-Datei oeffnen (X)" <<endl;
 cout << "Dtd-datei oeffnen (D) "<< endl;
 cout << "Txt-Datei oeffnen (T)"<< endl;
 cout << "Daten Konvertieren (K) "<< endl;
 cout << "Nach bestimmten Daten sucen (S)"<<endl;
 cout << "Ich brauche Hilfe (H)"<< endl;
 cout << "Programm beenden (B)"<<endl;
 cin >> aktion;

// - DTD-Datei öffnen und ausdrucken -

 if (strcmp(aktion,"D")==0)
 {
 eingabe.open("Daten.dtd");
 wurzel=objekt->verarbeite(eingabe);

 for (jetzt=wurzel;jetzt!=NULL;jetzt=jetzt->getNext())
     jetzt->druckeDtd(0,wurzel);
 eingabe.close();

 }

// - XML Datei öffnen und ausdrucken -

 if (strcmp(aktion,"X")==0)
 {
     eingabe.open("Daten.dtd");
     wurzel=objekt->verarbeite(eingabe);

     //for (jetzt=wurzel;jetzt!=NULL;jetzt=jetzt->getNext()) --> DtD ausdrucken, wird aber nicht gebraucht
     //jetzt->druckeDtd(0,wurzel);
     eingabe.close();
     eingabe.open("Daten.xml");
     if (getDaten.getXml(eingabe,NULL,wurzel)!=0) getDaten.druckeXml(1);
     eingabe.close();
 }

// - TXT Datei öffnen und ausdrucken -

 if (strcmp(aktion,"T")==0)
 {
     eingabe.open("Koordinaten.txt");
     getKoordinaten.getTxt(eingabe);
     getKoordinaten.druckeTxt();
     eingabe.close();
 }

//  - XML und Txt konvertieren

if (strcmp(aktion,"K")==0)
{

    eingabe.open("Koordinaten.txt");
    getKoordinaten.getTxt(eingabe);     //Txt Datei laden
    eingabe.close();

    eingabe.open("Daten.dtd");
    wurzel=objekt->verarbeite(eingabe);     //Dtd für xml laden
    eingabe.close();

    eingabe.open("Daten.xml");
    getDaten.getXml(eingabe,NULL,wurzel);   //xml Datei laden
    eingabe.close();

    cout << "Wie soll die neue Datei heißen? "<< endl;
    cin >>dateiname;

    ausgabe.open (dateiname);
    getDaten.druckeNewXml(ausgabe, getKoordinaten,0);
    ausgabe.close();


    /* - Dateiausgabe Test --> txt als xml ausgeben -
    ofstream ausgabe;
    ausgabe.open("TXT.xml");
    for (int i=0; i<=98; i++)
    {
    ausgabe << "<ID>" << getKoordinaten.getID(i)<<"</ID"<< "\n"
            << "<Bundesland>"<< getKoordinaten.getAttribut(i)<< "</Bundesland>"<<"\n"
            << "<Koordinaten>" << getKoordinaten.getTagInhalt(i)<< "</Koordinaten>"<< endl;
    }
    ausgabe.close();*/



}

// - Suche

if(strcmp(aktion,"S")==0)
{
    eingabe.open("Daten.dtd");
    wurzel=objekt->verarbeite(eingabe);     //Dtd für xml laden
    eingabe.close();

    eingabe.open("Daten.xml");
    getDaten.getXml(eingabe,NULL,wurzel);   //xml Datei laden
    eingabe.close();

    cout << "Geben Sie eine Kategorie ein: ";
    cin >> kategorie;
    cout << "Wonach soll gesucht werden?"<<endl;
    cin >> sucheingabe;

    getDaten.suche(kategorie,sucheingabe);

}


// - Hilfe

if (strcmp(aktion,"H")==0)
{
    cout << "Das Tourismus-Informationsprogramm des Regierungsbezirk Koeln dient der Recherche von Tourismus-Daten aus allen Geminden des Bezirks. "
            "Wenn Sie den Punkt Konvertieren anwaehlen so oeffnet sich eine XML-Datei sowohl mit den allgemeinen Daten (Name, Gaesteanzhal, Aufenthaltsdauer, kurzer Text) als auch mit den geografischen Daten (Bundesland und Koordinaten) aller Gemeinden."
            "Waehlen Sie den Punkt Suche so koennen Sie nach einzelnen Gemeinden Suchen und bekommen alle Daten dazu ausgegeben."
            "Moechten Sie das Programm schließen, waehlen Sie den Punkt beenden aus." <<endl;
}

// - Beenden

if (strcmp(aktion,"B")==0)return 0;


}

 return 0;
}

