#include <string.h>
#include "datenatt.h"

class ClgetXml
{

public:
    //ClgetXml();
    //char *Name(){if (tagStart !=NULL)return tagStart;else return "";}
    //char *Inhalt(){if (inhaltTag!=NULL)return inhaltTag;else return "";}
   int druckeXml(ifstream &datei);
    ClgetAttlist att;

private:
    //char *tagStart;
    //char *inhaltTag;
};
