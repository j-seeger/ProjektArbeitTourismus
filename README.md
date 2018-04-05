# ProjektArbeitTourismus


Mein Programm speichert und verarbeitet die Tourismus-Daten von 2016 der Gemeinden des Regierungsbezirks Köln. 
Dieses Programm könnte mit einer entsprechenden Visualisierung (z.B. interaktive Karte) datenjournalistisch veröffentlicht werden. 
Menschen aus den einzelnen Gemeinden können mit Hilfe des Programms ganz einfach erfahren, wie viele Gäste 2016 in ihrer Gemeinde waren und wie lange sie im Durchschnitt blieben. 
Außerdem gibt das Programm Wissenswertes zu den Gemeinden aus.

In meiner XML-Datei habe ich dazu die Daten zu Gästeanzahl und Aufenthaltsdauer sowie einen kurzen Text zu allen Gemeinden gespeichert. Diese XML-Datei wird mit datenlib.cpp und daten.h sowie datenattlib.cpp und datenatt.h gelesen und verarbeitet.
Zudem wird sie mit einer Dtd-Datei abgeglichen. Die nötigen Funktionen dazu stehen in dtdlib.cpp und sind im datendtd.h definiert. 
In der TXT-Datei stehen zusätzlich die Koordinaten sowie das Bundesland. Die Txt-Datei wird mit koordinaten.lib und koordinaten.h gelesen und verarbeitet.
Über die Auswahl "Konvertieren" im Menü wird eine neue XML-Datei erstellt, die sowohl die Daten als auch die Koordinaten enthält. Die nötigen Funktionen dazu stehen in der daten.lib und im daten.h.
Mit der Suche kann nach einzelnen Kategorien und darin enthaltenen Inhalten gesucht werden. Die nötigen Funktionen dazu stehen in der suchelib.cpp und sind im daten.h definiert.

Mein Programm ist abgelegt in meinem Repository 'ProjektArbeitTourismus' (https://github.com/j-seeger/ProjektArbeitTourismus).



