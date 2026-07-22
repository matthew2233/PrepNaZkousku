#include "Ucet.h"
#include "SporiciUcet.h"
#include <iostream>
#include <string>
#include <vector>

// Konstruktor potomka MUSÍ zavolat konstruktor předka. Zde to děláš pomocí " : Ucet(cisloUctu)" (tzv. list inicializace).
SporiciUcet::SporiciUcet(string cisloUctu, double urokovaSazba) : Ucet(cisloUctu)
{
    // cisloUctu se teoreticky nemusí nastavovat znovu, udělal to už konstruktor Ucet(cisloUctu), ale chybou to není.
    this->cisloUctu = cisloUctu;
    this->urokovaSazba = urokovaSazba;
}

void SporiciUcet::vypisInfo() const
{
    cout << "Cislo uctu je: " << cisloUctu << endl;
    cout << "Pocet transakci: " << historieTransakci.size() << endl;
    cout << "Vyse uroku je: " << urokovaSazba << "%" << endl;
}

void SporiciUcet::analyzujUcet() const
{
    int count = 0;
    // Změněno na double kvůli přesnosti zkouškového zadání.
    double sum = 0;
    double average = 0;
    // h je double, aby se neztratily desetinné hodnoty.
    for(double h : historieTransakci)
    {
        if(h > 0)
        {
            sum += h;
            count++;
        }
    }
    // Pojistka proti dělení nulou, která by program shodila!
    if(count > 0)
    {
        average = sum / count;
        cout << average <<  endl;
    }
}
