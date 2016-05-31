#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

using namespace std;

int main()
{
    int Aufg;
    char str1[11]; char str2[11]; char str3[11]; //char str4[11];
    int i; int q, w, e;
    char c;
    bool boo;


Start:
    cout<<"Zum Beenden druecken Sie die 0!"<<endl<<"Aufgabe (1-7): ";cin>>Aufg;
    switch (Aufg) {

case 0:
    cout << endl << endl;
    cout << "Danke!" << endl << endl;
break;

case 1:
    cout<<"Komma zu Punkt!"<<endl<<endl;

    cout<<"Bitte Kommazahl (max. 9 Ziffern) eingeben: "; cin>>str1;
    for (i = 0; i <= 10; i++)
    {
        if (str1[i] == ',')
            str1[i] = '.';
    }
    cout<<endl<<endl<<str1;
break;


case 2:
    cout<<"Stringlaenge!"<<endl<<endl;

    i = 0;
    cout<<"Bitte 1 Wort (max 10 Zeichen) eingeben: "; cin>>str2;
    while(str2[i]!='\0') {
        i++;
    }
    cout<<endl<<endl<<"while: " << i << "\t strlen: " << strlen(str2);
break;


case 3:
    cout<<"Klein- zu Grossschreibung! (1)"<<endl<<endl;

    cout<<"Bitte 1 Wort (max. 10 Zeichen) eingeben: "; cin>>str3;
    if (str3[0] >= 97 && str3[0] <= 122)
        str3[0] = str3[0] - 32;
    cout<<endl<<endl<<str3;
break;


default:
    cout << endl << endl;
    cerr << "Die Loesung zu einer solchen Aufgabe existiert in diesem Programm nicht..." << endl << "damn ._." << endl << endl << endl << endl;
    goto Start;
break;
    }
}
