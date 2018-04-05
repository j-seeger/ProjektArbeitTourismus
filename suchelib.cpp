#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <daten.h>

void ClgetXml::suche(char category[], char search[])
{
   /* cout << category << " und "<< search<<endl; --> Test ob Daten übergeben werden - funktioniert*/
    if (strcmp(name(),category)==0)
    {
        if (strcmp(inhalt(),search)==0)
        {
        cout << "Zur Kategorie: "<< category<< " und der Eingabe: "<< search << " wurden diese Ergebnisse gefunden: "<<endl;
        druckeSuche();
        }

    }

    //else cout<<"Fehler"; // Fehler kommt ganz oft

    if (tagChild!=NULL)tagChild->suche(category,search);
    if (tagSibling!=NULL)tagSibling->suche(category,search);


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
