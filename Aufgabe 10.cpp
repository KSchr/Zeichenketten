#include <iostream>
#include <string.h> //für strlen
#include <stdio.h> //für getchar
#include <math.h> //für pow

using namespace std;

int countdigits(int x)
{
    int count=0;

    do{
        x = x/10;
        ++count;
    }while(x>0);

    return count;
}

int powa(int b, int p) {
    int erg = 1;
    for (p; p>0; p--) {
        erg = erg * b;
    }
    return erg;
}

int main()
{
    char bin[50], c;
    char oct[50], dec[50], hex[50];
    int i;
    bool boo;

    cout<<"Umwandlung Zeichenkette: Binaer in Oktal/Dezimal/Hexadezimal"<<endl<<endl;
    do{
        boo = true;

        cout<<"Geben Sie eine Binaerzahl ein: ";
        for(int f=0; f<50; f++){
            c = getchar();
            if(c=='\n'){
                bin[f] = '\0'; break;
            }
            bin[f] = c;
        }

        if (strlen(bin) == 0) {
            boo = false;
        }
        else {
            i = 0;
            while (i < strlen(bin)) {
                c = bin[i];
                if (!(c == '0' || c == '1')) {
                    boo = false; break;
                }
            i++;
            }
        }

        cout<<endl<<endl<<"Ihre Eingabe lautete: ";
        if (boo == true) {

/********** UMWANDLUNG Binär->Oktal **********/
            //2^3 = 8 -> drei Binärstellen = eine Oktalstelle -> von rechts nach links
            int len = strlen(bin)-1; char octh[4]; int x;
                                                        cout<<endl<<"Oktal"<<endl;
            do{
                x=0;
                octh[3] = '\0';                         /* Hilfsstring mit \0 beenden */
                for (i=0; i<3; i++) {                   /* hinterer Dreierblock der Binärzahl abtrennen und ggf mit 0 auffüllen */
                    if ((len-i)<0){
                        octh[2-i] = '0';
                    }
                    else{
                        octh[2-i] = bin[len-i];
                    }
                }                                       cout << octh << endl;

                for (i=0; i<3; i++) {                   /* Berechnung des Dezimalwerts des Dreierblocks */
                    if (octh[i] == '1') {
                        x = x + powa(2,(2-i));
                    }                                   cout<<"i: "<<i<<"\tx: "<<x<<endl;
                }
                oct[(len/3)] = '0' + x;                 /* x hat einen Wert zwischen 0&7 und kann so direkt an die entsprechende Stelle als Zeichen eingesetzt werden */
                len = len-3;
            }while(len>=0);
            oct[((strlen(bin)-1)/3+1)] = '\0';          /* Oktalstring mit \0 beenden - muss scheinbar als letztes passieren oO *//* -1 und später +1, weil es sonst bei Fall mod3=0 zu Fehler kommt */

/********** UMWANDLUNG Binär->Dezimal **********/

/********** UMWANDLUNG Binär->Hexadezimal **********/

/********** UMWANDLUNG ENDE **********/

            cout<<endl<<"     Binaer: "<<bin<<endl<<"      Oktal: "<<oct<<endl<<"    Dezimal: "<<dec<<endl<<"Hexadezimal: "<<hex<<endl<<endl;
        }
        else {
            cout<<bin<<endl<<"Dies ist keine gueltige Binaerzahl."<<endl<<"Bitte versuchen Sie es erneut."<<endl<<endl<<endl<<endl;
        }
    }while(boo == false);
}
