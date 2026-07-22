#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ucet
{
    // protected znamená, že tyto proměnné vidí tato třída a všechny třídy z ní poděděné (SporiciUcet, BeznyUcet).
    // Kdyby byly private, potomci by k nim nemohli napřímo přistupovat.
    protected:
    string cisloUctu;
    vector<double> historieTransakci;

    // private znamená, že proměnnou vidí POUZE tato třída.
    // static znamená, že proměnná je sdílená pro všechny objekty této třídy (existuje jen jedna pro celý program).
    private:
    static int pocetUctu;

    public:
    // Konstruktor: Předávání referencí (string&) je rychlejší, nevytváří se zbytečná kopie.
    // Lepší by sice bylo "const string&", ale toto funguje. Vektor tu není, protože se zakládá prázdný.
    Ucet(string& cisloUctu);
    
    // Virtuální destruktor je EXTRÉMNĚ DŮLEŽITÝ. Zajišťuje, že se při mazání přes ukazatel (delete ucet)
    // zavolá i destruktor potomka, nejen předka. Zabraňuje to memory leakům.
    virtual ~Ucet();

    // Statická metoda může pracovat pouze se statickými proměnnými (zde pocetUctu).
    static int getPocetUctu();

    // Přetěžování metod (Overloading) - dvě metody se stejným jménem, ale jinými parametry.
    void pridejTransakci(double hodnota);
    // const vector<double>& znamená: "pošli mi odkaz na existující vektor (zabráníš kopírování) 
    // a slibuji (const), že ho uvnitř funkce nezměním."
    void pridejTransakci(const vector<double>& hodnoty);

    // Vrací referenci na vektor, takže s ním můžeme venku pracovat a nevracíme jen jeho kopii.
    vector<double>& getHistorie();
    // const na konci metody znamená, že tato metoda nesmí změnit žádné členské proměnné objektu.
    string getCisloUctu() const;

    // Čistě virtuální metoda (pure virtual). "= 0" dělá z třídy Ucet ABSTRAKTNÍ TŘÍDU.
    // Znamená to, že nemůžeš vytvořit objekt typu Ucet (new Ucet()), musíš vytvořit vždy potomka.
    // Každý potomek MUSÍ tuto metodu implementovat, jinak se program nezkompiluje.
    virtual void analyzujUcet() const = 0;
    
    // Virtuální metoda s vlastní implementací. Potomek ji MŮŽE (ale nemusí) přepsat (override).
    virtual void vypisInfo() const;
};
