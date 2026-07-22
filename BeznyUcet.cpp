#include <iostream>
#include <string>
#include <vector>
#include "BeznyUcet.h"

BeznyUcet::BeznyUcet(string cisloUctu, double poplatek) : Ucet(cisloUctu)
{
    this->cisloUctu = cisloUctu;
    this->poplatek = poplatek;
}

void BeznyUcet::vypisInfo() const
{
    cout << "Cislo uctu je: " << cisloUctu << endl;
    cout << "Pocet transakci: " << historieTransakci.size() << endl;
    cout << "Vyse poplatku je: " << poplatek << endl;
}

void BeznyUcet::analyzujUcet() const
{
    int count = 0;
    for(double h : historieTransakci)
    {
        if(h < 0)
        {
            count++;
        }
    }   
    cout << count <<  endl;
}

bool BeznyUcet::operator==(const BeznyUcet &other) const
{
    // Přístup k poplatku aktuálního objektu a poplatku druhého objektu.
    return this->poplatek == other.poplatek;
}

BeznyUcet &BeznyUcet::operator+=(double castka)
{
    pridejTransakci(castka);
    // return *this vrací odkaz na samotný objekt (dereferencuje this pointer).
    return *this;
}

ostream &operator<<(ostream& os, const BeznyUcet& b)
{
    // Nesmí tu být 'cout', musí tu být stream 'os', který funkce dostává jako parametr!
    os << "BeznyUcet[" << b.cisloUctu << "], transakci: " << b.historieTransakci.size();
    return os; // Vracíme os, aby fungovalo řetězení cout << a << b << c;
}
