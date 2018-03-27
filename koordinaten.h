#include <string.h>

class ClKoordinaten
{
public:
    //ClKoordinaten();
   int getTxt(ifstream &datei);
   char *getID(int nummer){return identification[nummer];}
   char *getAttribut(int nummer){return attName[nummer];}
   char *getTagInhalt(int nummer){return tagInhalt[nummer];}
   int getZahl(){return zahl;}
   void druckeTxt();
//   void addId(char *string);
//   void addAttribut(char *string);
//   void addTagInhalt (char *string);


private:
//   int zahlID;
//   int zahlAtt;
//   int zahlInhalt;
   char *identification [100] ;
   char *attName [100];
   char *tagInhalt [100];
   int zahl;


};
