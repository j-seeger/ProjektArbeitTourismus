#include <string.h>
#include "datenatt.h"
#include "koordinaten.h"


class ClgetXml
{

public:
    ClgetXml();
    char *name() { return tagStart;}
    ClgetXml *child(){return tagChild;}
    ClgetXml *sibling(){return tagSibling;}
    char *inhalt(){return inhaltTag;}
    void druckeNewXml(ofstream &datei, ClKoordinaten kord, int en);
    void druckeXml(int ebene);
    void druckeEinruecker(int en, ofstream &datei);
    int getXml(ifstream &datei, ClgetDtd*element, ClgetDtd *wurzel);
    ClgetAttlist att;

    int suche(char category[10], char search[100], int x);
    void druckeSuche();
    int x;





private:
    void cleantag();
    void druckeTagEbene(int ebene);
    int fillTag(int mode);
    char tagStart[64];
    ClgetXml *tagChild;
    ClgetXml *tagSibling;
    char *inhaltTag;



};
