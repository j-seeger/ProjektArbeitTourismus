#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <daten.h>

int ClgetXml::suche(char category[], char search[], int x)
{
   /* cout << category << " und "<< search<<endl; --> Test ob Daten übergeben werden - funktioniert*/
    if (x==1)return x;
    if (strcmp(name(),category)==0)
    {
        if (strcmp(inhalt(),search)==0)
        {
        cout << "Zur Kategorie: '"<< category<< "' und der Eingabe: '"<< search << "' wurden diese Ergebnisse gefunden: "<<endl;
        druckeSuche();
        x=1;
        return x;
        }
      }


    if (tagChild!=NULL)x=tagChild->suche(category,search,x); //x= übergibt den return-wert an die anderen Rekursionsschleifen
    if (tagSibling!=NULL)x=tagSibling->suche(category,search,x);
    return x; //stellt sicher, dass returnwert von Childs und Siblings zurückgegeben wird
}


void ClgetXml::druckeSuche()
{
    cout << name()<< ": "<<inhalt();

    if (att.zahlAtt()>0)
    {
       for (int i=0; i<att.zahlAtt();i++)
            cout << " "<<att.zeigeAttName(i) << ": "<< att.zeigeAttWert(i);
     }
    cout << endl;
   if (tagChild!=NULL)tagChild->druckeSuche();
   if (tagSibling!=NULL)tagSibling->druckeSuche();
}


