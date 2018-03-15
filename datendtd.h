#include <string.h>

enum status {frei, inBearbeitung};


class ClgetDtd {


public:
    ClgetDtd *verarbeite(ifstream &datei);
    ClgetDtd(char *string);
    char *getName(void){return name;}
    void addTag(char * string);
    void addAttribute(char *string);
    int getAnzahlTags() { return zahl; }
    char *getTagName(int slot) { return tags[slot]; }
    void druckeDtd(int ebene,ClgetDtd *wurzel);
    ClgetDtd *getNext(void) { return naechstes; }
    void setNext(ClgetDtd *neu) { naechstes = neu; }
    ClgetDtd *sucheElement (char *suche, ClgetDtd *element);
    int elementIstErlaubt (char *name);

private:
  int zahl;
  char name[64];
  char tags [10][64];
  ClgetDtd *naechstes;
  enum status status;
   int zahlAttribute;
   char attributes [10][64];


};
