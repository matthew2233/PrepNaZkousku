#include "Ucet.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Inicializace statické proměnné MUSÍ proběhnout v .cpp souboru, mimo jakoukoliv funkci/konstruktor.
int Ucet::pocetUctu = 0;

Ucet::Ucet(string &cisloUctu)
{
    this->cisloUctu = cisloUctu;
    // Pokaždé, když se vytvoří nějaký účet (i potomek), zvedneme počítadlo.
    pocetUctu++;
}

Ucet::~Ucet()
{
    // Pokaždé, když účet zanikne, počítadlo snížíme.
    pocetUctu--;
}

int Ucet::getPocetUctu()
{
    return pocetUctu;
}

void Ucet::pridejTransakci(double hodnota)
{
    // push_back přidá prvek na konec vektoru.
    historieTransakci.push_back(hodnota);
}

void Ucet::pridejTransakci(const vector<double> &hodnoty)
{
    // Range-based for cyklus. Jde prvek po prvku ve vektoru "hodnoty".
    for(double h : hodnoty)
    {
        historieTransakci.push_back(h);
    }
}

vector<double> &Ucet::getHistorie()
{
    return historieTransakci;
}

string Ucet::getCisloUctu() const
{
    return cisloUctu;
}

void Ucet::vypisInfo() const
{
    cout << "Cislo uctu je: " << cisloUctu << endl;
    cout << "Pocet transakci: " << historieTransakci.size();
}
