#pragma once
#include "Ucet.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// "public Ucet" znamená, že SporiciUcet dědí od Ucet. 
// Všechny public/protected věci z Ucet se stávají public/protected ve SporiciUcet.
class SporiciUcet : public Ucet
{
    protected:
    double urokovaSazba;

    public:
    SporiciUcet(string cisloUctu, double urokovaSazba);

    // override je pojistka (best practice) pro překladač. Kontroluje, že metoda s tímto jménem 
    // a parametry skutečně existuje u předka jako virtual.
    void vypisInfo() const override;
    void analyzujUcet() const override;
};
