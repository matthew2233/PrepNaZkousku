#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <numeric>
#include "BeznyUcet.h"
#include "SporiciUcet.h"
#include "Ucet.h"

using namespace std;

    // Funkce by v ideálním případě braly const Ucet*, pokud účet jen čtou, ale tvůj algoritmus 2 ho i mění, 
    // takže obyčejný ukazatel Ucet* je zde správně.
    void Algoritmus1(Ucet* u);
    void Algoritmus2(Ucet* u);

    int main()
    {
        cout << Ucet::getPocetUctu() << endl; // Mělo by vypsat 0
        
        // Vektor ukazatelů na BÁZOVOU třídu. Zásadní pro polymorfismus. 
        // Umožňuje nám do jednoho pole narvat jak běžné, tak spořící účty.
        vector<Ucet*> pole;
        
        // Alokace na haldě (heap) pomocí 'new'. Vrací ukazatel (pointer).
        BeznyUcet* u1 = new BeznyUcet("idk123456", 500.0);
        BeznyUcet* u2 = new BeznyUcet("idk654321", 700.0);
        SporiciUcet* u3 = new SporiciUcet("idk987654", 20.0);

        u1->pridejTransakci({20,50,-26, 40, 60, 70, 80});
        u2->pridejTransakci({80,90,40});
        u3->pridejTransakci({100,-45,-55});

        pole.push_back(u1);
        pole.push_back(u2);
        pole.push_back(u3);
        
        // Protože operátor== očekává objekt nebo referenci, musíme ukazatel 'dereferencovat' pomocí hvězdičky.
        // Tím vytáhneme samotný objekt, na který ukazatel ukazuje.
        if(*u1 == *u2)
        {
            cout << "ano" << endl;
        }
        else{
            cout << "ne" << endl;
        }
 
        // Totéž zde: *u1 znamená "aplikuj to na ten objekt, na který u1 ukazuje".
        *u1 += 5000;
        cout << *u1 << endl; // Přidal jsem endl pro hezčí formátování ve výstupu

        // Cyklus využívající POLYMORFISMUS. 
        // Přestože vektor obsahuje jen "Ucet*", díky klíčovému slovu 'virtual' v hlavičce Ucet.h 
        // si program sám za běhu zjistí, jaký je to doopravdy účet a zavolá správnou funkci.
        for(Ucet* i : pole)
        {
            i->vypisInfo();
            i->analyzujUcet();
        }

        Algoritmus1(u1);
        Algoritmus2(u1);

        // Uvolnění paměti. Všechno, co bylo vytvořeno přes 'new', musí být zničeno přes 'delete'.
        // Pokud by toto chybělo, vznikne tzv. Memory Leak.
        for(Ucet* i : pole)
        {
            delete i; 
        }

        // Výpis by nyní měl být opět 0.
        cout << Ucet::getPocetUctu() << endl;
        return 0;
    }

    void Algoritmus1(Ucet* u)
    {
        int max = 0;
        int count = 0;
        for(double i : u->getHistorie())
        {
            if(i > 0)
            {
                count++;
            }
            else
            {
                if(count > max)
                {
                    max = count;
                }
                count = 0;
                
            }
        }
        // Kontrola pro případ, že pole končí kladnou sérií a nestihne se zapsat v "else" větvi.
        if(count > max)
        {
            max = count;
        }
        cout << "Nejdelsi delka vkladu za sebou je: " << max << endl;
    }

    void Algoritmus2(Ucet* u)
    {
        // Tvůj algoritmus - správný přístup, když modifikuješ vektor, přes který právě iteruješ.
        // Reference '&' zajišťuje, že úpravy se projeví přímo v originálním vektoru.
        vector<double>& pomocnyVector = u->getHistorie();
        for(int i = 0; i < pomocnyVector.size(); i++ )
        {
            if(pomocnyVector[i] < 0 && pomocnyVector[i] > -50)
            {
                // vector::erase posune všechny zbylé prvky doleva, proto musíme i snížit i (i--),
                // jinak bychom přeskočili prvek, který se právě posunul na naši pozici.
                pomocnyVector.erase(pomocnyVector.begin() + i);
                i--;
            }
        }
    }
