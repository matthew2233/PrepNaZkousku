#pragma once
#include "Ucet.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BeznyUcet : public Ucet
{
    protected:
    double poplatek;

    public:
    BeznyUcet(string cisloUctu, double poplatek);

    void vypisInfo() const override;
    void analyzujUcet() const override;

    // Přetížení operátoru == pro porovnání dvou objektů třídy. 
    // První objekt je ten, na kterém se to volá (this), druhý je "other".
    bool operator== (const BeznyUcet& other) const;
    
    // Vrací referenci na sebe sama (BeznyUcet&), aby šlo řetězit (napr. u1 += 50 += 10;).
    BeznyUcet& operator+=(double castka);
    
    // Přetížení << pro výpis cout. MUSÍ to být friend, protože operátor << patří třídě ostream (z knihovny), 
    // a my potřebujeme, aby mohl přistupovat k našim private/protected proměnným.
    friend ostream& operator<<(ostream& os, const BeznyUcet& b);
};
