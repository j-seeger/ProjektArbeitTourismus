#include <string.h>

class ClgetDtd {
private:
    char *letztes;
    char puffer [1000];
    char zeichen;
    int zaehler;

public:
  void getDtd(ifstream &datei);
  char *letztesElement();


};
