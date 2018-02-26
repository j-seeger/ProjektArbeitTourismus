#include<string.h>

class ClgetAttlist {
public:
   char *zeigeAttName(int id) {return attname[id];}
   char *zeigeAttWert(int id) {return attwert[id];}
   int zahlAtt() {return anzahlatt;}
   int getAttlist(char *eingabe);

private:
int anzahlatt;
char *attname[100];
char *attwert[100];
};
