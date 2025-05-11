#include <iostream>
#include "Szyfrator.h"
#include <string>
using namespace std; //żeby nie pisać std::string
int main() {
    string klucz1 = "qwertyuiop";
    string klucz2 = "abcdefghijkl";
    string testowy = "Jaka prosta praca domowa!";

    Szyfrator *szyfr1 = new Szyfrator;
    szyfr1->ustawKlucz(klucz1);
    Szyfrator *szyfr2 = new Szyfrator(klucz2);

    //określam dla klucza testowego i nr 1
    string zaszyfrowanyt = szyfr1->szyfruj(testowy);
    string odszyfrowanyt = szyfr1->deszyfruj(zaszyfrowanyt);
    string zaszyfrowany2 = szyfr1->szyfruj(klucz1);
    string odszyfrowany2 = szyfr1->deszyfruj(zaszyfrowany2);

    //wyświetlam tekst przed szyfrowaniem, po szyfrowaniu i po odszyfrowaniu - upewnienie, że wszystko działą
    cout << "Oryginalny tekst: " << testowy << endl;
    cout << "Po zaszyfrowaniu: " << zaszyfrowanyt << endl;
    cout << "Po odszyfrowaniu: " << odszyfrowanyt << endl;
    cout << "Oryginalny tekst: " << klucz1 << endl;
    cout << "Po zaszyfrowaniu: " << zaszyfrowany2 << endl;
    cout << "Po odszyfrowaniu: " << odszyfrowany2 << endl;

    cout << szyfr1->deszyfruj(szyfr1->szyfruj(testowy)) << endl; //sprawdzenie z oryginału/pobranego pliku
    cout << szyfr2->deszyfruj(szyfr2->szyfruj(testowy)) << endl;
    return 0;
}
