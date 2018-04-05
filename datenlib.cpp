#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <daten.h>


ClgetXml::ClgetXml()
{
    *tagStart='\0';
    tagChild=NULL;
    tagSibling=NULL;
    inhaltTag=new char [1];
    *inhaltTag='\0';
}

int ClgetXml::getXml(ifstream&datei, ClgetDtd *element, ClgetDtd *wurzel)
{

    char puffer [1000];
    char zeichen;
    int zaehler;
    char *ziel, *quelle;
    enum zustand {startTag,tagInhalt,inAttribut, endTag,noise};
    enum zustand zustand;
    ClgetXml *child;
    int isChild;


    cleantag();

    for (zaehler=0;;)
    {
       datei.get(zeichen);
       if (datei.eof())
       {
           if(*tagStart == '\0' && tagChild == NULL && inhaltTag == NULL)
               return fillTag(0);
           return fillTag(1);
       }


       switch (zeichen)
       {

       case '<':
           datei.get(zeichen);
           if (zeichen =='/')
           {
               zustand=endTag;
               if (zaehler-1>0)
               {
               puffer[zaehler]='\0';
               inhaltTag=new char [zaehler+1];
               strcpy(inhaltTag,puffer);

              }
            }
        else
           {
           datei.putback(zeichen);
           if (*tagStart!='\0')
           {
               datei.putback('<');
               if (tagChild==NULL)
               {
                   tagChild= new ClgetXml;
                   if (tagChild->getXml(datei,element,wurzel)==0)return fillTag(0);

               }
               else
                  {
                 for (child=tagChild;;child=child->tagSibling)
                    {
                      if (child->tagSibling==NULL)
                        {
                            child->tagSibling=new ClgetXml;
                            if (child->tagSibling->getXml(datei,element,wurzel)==0)return fillTag(0);
                            break;
                        }
                     }
                    }
           }
           else zustand=startTag;
           }
          zaehler=0;
          break;


        case '>':
            puffer[zaehler]='\0';
            if (zustand==endTag)
            {
                if (strcmp(tagStart,puffer))
                {
                    cout << "Fehlerhaftes End Tag" << endl;
                    cout << "Erhalten: '" << puffer << "'; erwartet: '"
                         << tagStart << "'" << endl;
                 return fillTag(0);
                }
                return fillTag(1);
             }
            if (zustand==startTag)
            {
                for (ziel=tagStart,quelle=puffer;*quelle!=' ' && *quelle!= '\0';
                            ziel++,quelle++) *ziel=*quelle;
                       *ziel='\0';
                       if (!strcmp(tagStart,wurzel->getName()))element=wurzel;
                       else
                          {
                            if (element==NULL)isChild=-1;
                            else isChild=element->elementIstErlaubt(tagStart);
                            if (isChild < 0)
                             {
                                cout << "Fehlerhaftes Start Tag: '" << tagStart << "'" << endl;
                                return fillTag(0);
                             }
                            element=element->sucheElement(tagStart,wurzel);
                          }
                       att.getAttlist(puffer,element);

             }
            zaehler=0;
            break;

       default:
           puffer[zaehler]=zeichen;
           zaehler++;
           break;
           }

        }
}

int ClgetXml::fillTag(int mode)
{
    if (*tagStart=='\0')
        strcpy(tagStart,"Unbekanntes Element");
    if (inhaltTag==NULL)
    {
        inhaltTag=new char [1];
        *inhaltTag='\0';
    }
   return mode;
}

void ClgetXml::cleantag(void)
{
   *tagStart='\0';
    if (tagChild!=NULL)
    {
        delete tagChild;
        tagChild=NULL;
    }
    if (inhaltTag!=NULL)
    {
        delete inhaltTag;
        inhaltTag=NULL;
    }
}

void ClgetXml::druckeXml(int ebene)
{


    druckeTagEbene(ebene);
    cout << "Tag: "<<name()<< "\n" << "Inhalt: " << inhalt()<< endl;
    if (att.zahlAtt()>0)
    {
        //druckeTagEbene(ebene);
        for (int i=0; i<att.zahlAtt();i++)        
            cout << "Attribut: "<< att.zeigeAttName(i) << "\n"
                 << " Attributwert: "<< att.zeigeAttWert(i)<< endl;
     }

    if (tagChild!=NULL) tagChild->druckeXml(ebene+1);
    if (tagSibling!=NULL)tagSibling->druckeXml(ebene);


}

void ClgetXml::druckeTagEbene(int ebene)
{
    while (ebene>0)
    {
        cout << " |";
        ebene = ebene -1;
    }
}

void ClgetXml::druckeNewXml(ofstream &datei, ClKoordinaten kord, int en) //drucke Funktion kopiert; Hier soll nun die neue XMl mit Txt gedruckt werden
{

    druckeEinruecker(en,datei);

    /*cout << kord.getID(10); - Test ob txt über Objekt übergebn wird-*/

   datei << "<"<<name()<< ">" << " " << inhalt();
   if (!tagChild&&!tagSibling)datei <<"</"<< name()<< ">"<<endl; //Wenn es weder ein TagCHild noch ein TagSibling ist, soll der Tag direkt wieder geschlossen werden
   else datei << endl;
    if (att.zahlAtt()>0)
    {
       for (int i=0; i<att.zahlAtt();i++)
        {
            druckeEinruecker(en,datei);
            datei << "<"<< att.zeigeAttName(i) << "> "
                 << att.zeigeAttWert(i)<< " </"<< att.zeigeAttName(i)<< ">"<<endl;
           for (int a=0; a<=98; a++)//for-Schleife für IDs aus der TXT-Datei
            {
                if (strcmp(att.zeigeAttWert(i),kord.getID(a))==0)
                    {
                   druckeEinruecker(en,datei);
                   //cout << "ID: "<< kord.getID(a)<< "und" << att.zeigeAttWert(i)<< endl; - Test ob es funktioniert, die IDs miteinander zu vergleichen
                  datei << "<Geografie>"<< endl;
                  druckeEinruecker(en+1,datei);
                  datei << "<Koordinaten bundesland = '" << kord.getAttribut(a)<< "'> "<<kord.getTagInhalt(a)<<" </Koordinaten>"<<endl;
                    druckeEinruecker(en,datei);
                  datei <<"</Geografie>" <<endl;
                    druckeEinruecker(en,datei);
                  datei << "<Allgemein>"<< endl;
                    }
            }
        }
    }

    if (tagChild!=NULL) tagChild->druckeNewXml(datei,kord, en+1);
    if(strcmp(name(),"Text"))
    {
        if (strcmp(name(),"Gemeinde")==0)// wird benötigt um den Allgemein-Tag zu schließen
            {
            druckeEinruecker(en,datei);
            datei << "</Allgemein>"<<endl;
            }
        druckeEinruecker(en,datei);
        datei << "</"<< name()<< ">"<<endl; //wird benötigt um das Kreis-Tag zu schließen
    }

    if (tagSibling!=NULL)tagSibling->druckeNewXml(datei, kord, en);


}

void ClgetXml::druckeEinruecker(int en, ofstream &datei) // damit die Daten in der neuen Xml eingerückt werden.
{
    while (en>0)
    {
        datei << "   ";
        en = en -1;
    }
}

//void ClgetXml::suche(char category[], char search[])
//{
//int wert=0;
//while(wert==0){

//   /* cout << category << " und "<< search<<endl; --> Test ob Daten übergeben werden - funktioniert*/
//    if (strcmp(name(),category)==0)
//    {
//        if (strcmp(inhalt(),search)==0)
//        {
//        cout << "Zur Kategorie: "<< category<< " und der Eingabe: "<< search << " wurden diese Ergebnisse gefunden: "<<endl;
//        druckeSuche();
//        }
//       wert=1;
//    }

//    //else cout<<"Fehler"; // Fehler kommt ganz oft

//    if (tagChild!=NULL) tagChild->suche(category,search);
//    if (tagSibling!=NULL)tagSibling->suche(category,search);


//  }
//return;
//}



//void ClgetXml::druckeSuche()
//{
//    cout << name()<< ": "<<inhalt();

//    if (att.zahlAtt()>0)
//    {
//       for (int i=0; i<att.zahlAtt();i++)
//            cout << " "<<att.zeigeAttName(i) << ": "<< att.zeigeAttWert(i);
//     }
//    cout << endl;
//   if (tagChild!=NULL)tagChild->druckeSuche();
//   if (tagSibling!=NULL)tagSibling->druckeSuche();
//}









