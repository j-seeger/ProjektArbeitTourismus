#include <string.h>

class ClKoordinaten
{
public:
   int druckeTxt(ifstream &datei);


private:
   char zeichen;
   char puffer [100];
   int zaehler;

};
