
//1. Agregace a extrémy (1-10)
//Tyto algoritmy slouží k výpočtu jedné konkrétní hodnoty na základě celého pole.
// 1. Maximum
double getMaximum(const vector<double>& v) {
    if(v.empty()) return 0; // Ošetření prázdného pole
    double max = v[0]; // Nikdy nezačínej nulou, pole může mít jen záporná čísla!
    for(double prvek : v) {
        if(prvek > max) max = prvek;
    }
    return max;
}

// 2. Minimum
double getMinimum(const vector<double>& v) {
    if(v.empty()) return 0;
    double min = v[0];
    for(double prvek : v) {
        if(prvek < min) min = prvek;
    }
    return min;
}

// 3. Součet (Suma)
double getSoucet(const vector<double>& v) {
    double sum = 0;
    for(double prvek : v) sum += prvek;
    return sum;
}

// 4. Průměr
double getPrumer(const vector<double>& v) {
    if(v.empty()) return 0; // Pojistka proti dělení nulou
    double sum = 0;
    for(double prvek : v) sum += prvek;
    return sum / v.size(); // Velikost vrací počet prvků
}

// 5. Počet kladných čísel
int pocetKladnych(const vector<double>& v) {
    int count = 0;
    for(double prvek : v) {
        if(prvek > 0) count++;
    }
    return count;
}

// 6. Rozptyl (Amplituda) - rozdíl mezi maximem a minimem
double getRozptyl(const vector<double>& v) {
    if(v.empty()) return 0;
    return getMaximum(v) - getMinimum(v); // Využívá funkce 1 a 2
}

// 7. Index největšího prvku
int getIndexMaxima(const vector<double>& v) {
    if(v.empty()) return -1; // -1 znamená, že index neexistuje
    double max = v[0];
    int maxIdx = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > max) {
            max = v[i];
            maxIdx = i; // Uložíme si pozici, kde jsme max našli
        }
    }
    return maxIdx;
}

// 8. Druhé největší číslo
double getDruheMaximum(const vector<double>& v) {
    double max1 = getMaximum(v);
    double max2 = -999999; // Nastavíme na hodně malé číslo
    for(double prvek : v) {
        // Hledáme číslo menší než absolutní maximum, ale větší než aktuální max2
        if(prvek > max2 && prvek < max1) {
            max2 = prvek;
        }
    }
    return max2;
}

// 9. Absolutní součet (ignoruje znaménka)
double absolutniSoucet(const vector<double>& v) {
    double sum = 0;
    for(double prvek : v) {
        sum += abs(prvek); // abs() je z knihovny <cmath>
    }
    return sum;
}

// 10. Suma sudých indexů
double sumaSudychIndexu(const vector<double>& v) {
    double sum = 0;
    // Začínáme od 0 (sudý) a skáčeme o 2 dopředu
    for(int i = 0; i < v.size(); i += 2) {
        sum += v[i];
    }
    return sum;
}


//2. Filtrace a vyhledávání (11-20)
//Zde se zaměřujeme na hledání konkrétních vlastností nebo prvků.
// 11. Obsahuje prvek (Contains)
bool obsahujePrvek(const vector<double>& v, double hledane) {
    for(double prvek : v) {
        if(prvek == hledane) return true; // Jakmile najdeme, hned končíme funkci
    }
    return false; // Pokud cyklus doběhne do konce, prvek tam není
}

// 12. Počet výskytů (Frekvence)
int pocetVyskytu(const vector<double>& v, double hledane) {
    int count = 0;
    for(double prvek : v) {
        if(prvek == hledane) count++;
    }
    return count;
}

// 13. Všechna čísla nad prahovou hodnotu (Vrací nové pole)
vector<double> filtrujNadPrah(const vector<double>& v, double prah) {
    vector<double> vysledek;
    for(double prvek : v) {
        if(prvek > prah) vysledek.push_back(prvek);
    }
    return vysledek;
}

// 14. První záporný prvek
double prvniZaporny(const vector<double>& v) {
    for(double prvek : v) {
        if(prvek < 0) return prvek; // Hned po prvním nálezu vyskočíme
    }
    return 0; // Nenašli jsme (ideálně by se ošetřovalo výjimkou)
}

// 15. Poslední záporný prvek (Cyklus odzadu)
double posledniZaporny(const vector<double>& v) {
    // Začínáme na posledním indexu (size-1) a couváme, dokud i >= 0
    for(int i = v.size() - 1; i >= 0; i--) {
        if(v[i] < 0) return v[i];
    }
    return 0;
}

// 16. Zjištění, zda je pole rostoucí
bool jeRostouci(const vector<double>& v) {
    if(v.size() < 2) return true;
    // Jdeme jen do předposledního prvku, protože kontrolujeme prvek [i] a [i+1]
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i] > v[i+1]) return false; // Pokud je dřívější větší než pozdější, kleslo to
    }
    return true;
}

// 17. Jsou všechny prvky kladné?
bool jsouVsechnyKladne(const vector<double>& v) {
    for(double prvek : v) {
        if(prvek <= 0) return false; // Jeden průšvih a končíme
    }
    return true;
}

// 18. Unikátní prvky (Odstranění duplicit přes nový vektor)
vector<double> unikatniPrvky(const vector<double>& v) {
    vector<double> vysledek;
    for(double prvek : v) {
        // Využijeme už hotovou funkci 11
        if(!obsahujePrvek(vysledek, prvek)) {
            vysledek.push_back(prvek);
        }
    }
    return vysledek;
}

// 19. Kopírování pole pozpátku (Reverz do nového)
vector<double> reverzPole(const vector<double>& v) {
    vector<double> vysledek;
    for(int i = v.size() - 1; i >= 0; i--) {
        vysledek.push_back(v[i]);
    }
    return vysledek;
}

// 20. Porovnání dvou polí
bool jsouStejnaPoli(const vector<double>& v1, const vector<double>& v2) {
    if(v1.size() != v2.size()) return false; // Nemají stejnou délku, nemohou být stejná


  //3. Práce s indexy a sekvencemi (21-30)
//Tyto algoritmy operují nad strukturou a uspořádáním pole.
 // 21. Výměna prvků (Swap) in-place
void vymenPrvky(vector<double>& v, int index1, int index2) {
    double temp = v[index1]; // Uložíme dočasně
    v[index1] = v[index2];   // Přepíšeme první druhým
    v[index2] = temp;        // Do druhého dáme zálohovaný první
}

// 22. Otočení pole in-place (bez vytvoření nového vektoru)
void otoctPole(vector<double>& v) {
    int n = v.size();
    for(int i = 0; i < n / 2; i++) { // Jdeme jen do půlky!
        vymenPrvky(v, i, n - 1 - i); // Využití funkce 21
    }
}

// 23. Nejdelší řada stejných čísel
int nejdelsiRadaStejnych(const vector<double>& v) {
    if(v.empty()) return 0;
    int maxSerie = 1, aktualniSerie = 1;
    
    for(int i = 1; i < v.size(); i++) {
        if(v[i] == v[i-1]) {
            aktualniSerie++;
        } else {
            if(aktualniSerie > maxSerie) maxSerie = aktualniSerie;
            aktualniSerie = 1; // Reset
        }
    }
    // Ošetření konce pole
    if(aktualniSerie > maxSerie) maxSerie = aktualniSerie;
    return maxSerie;
}

// 24. Rozdělení pole na dvě (Vklady a Výběry)
void rozdelPole(const vector<double>& zdroj, vector<double>& vklady, vector<double>& vybery) {
    for(double prvek : zdroj) {
        if(prvek > 0) vklady.push_back(prvek);
        else if(prvek < 0) vybery.push_back(prvek);
    }
}

// 25. Spojení dvou polí
vector<double> spojPoli(const vector<double>& v1, const vector<double>& v2) {
    vector<double> vysledek = v1; // Zkopírujeme první
    for(double prvek : v2) {
        vysledek.push_back(prvek); // Přilepíme na konec druhé
    }
    return vysledek;
}

// 26. Rotace pole doleva (posun prvků o 1 vlevo)
void rotaceDoleva(vector<double>& v) {
    if(v.empty()) return;
    double prvni = v[0]; // Záloha prvního (ten přepíšeme)
    for(int i = 0; i < v.size() - 1; i++) {
        v[i] = v[i+1]; // Posouváme hodnoty doleva
    }
    v[v.size() - 1] = prvni; // Na poslední místo dáme původně první
}

// 27. Zda pole tvoří palindrom (Čte se zepředu i zezadu stejně)
bool jePalindrom(const vector<double>& v) {
    int n = v.size();
    for(int i = 0; i < n / 2; i++) {
        if(v[i] != v[n - 1 - i]) return false; // Neshoda krajních prvků
    }
    return true;
}

// 28. Hledání extrému na určitém intervalu (od indexu A do B)
double maxVIntervalu(const vector<double>& v, int start, int end) {
    double max = v[start];
    for(int i = start; i <= end; i++) { // Pracujeme jen v daném rozmezí
        if(v[i] > max) max = v[i];
    }
    return max;
}

// 29. Počet přechodů nulou (Změna znaménka)
int prechodyNulou(const vector<double>& v) {
    int count = 0;
    for(int i = 1; i < v.size(); i++) {
        if((v[i] > 0 && v[i-1] < 0) || (v[i] < 0 && v[i-1] > 0)) {
            count++;
        }
    }
    return count;
}

// 30. Výběr každého N-tého prvku
vector<double> kazdyNTyPrvek(const vector<double>& v, int N) {
    vector<double> vysledek;
    for(int i = 0; i < v.size(); i += N) {
        vysledek.push_back(v[i]);
    }
    return vysledek;
}


//4. Modifikace vektorů (31-40)
//Kódy pro úpravu struktury stávajícího vektoru. Všechny přijímají referenci vector<double>& v.

// 31. Odstranění určité hodnoty (pomocí <algorithm> iteratorů) - PROFI PŘÍSTUP
void odstranHodnotuProfi(vector<double>& v, double hodnota) {
    // remove přeskládá pole tak, že smazané věci hodí na konec pole a vrátí na ně iterátor (ukazatel)
    // erase to pole pak na tomto bodě usekne.
    v.erase(remove(v.begin(), v.end(), hodnota), v.end());
}

// 32. Odstranění podle podmínky in-place (bez std::remove) - KLASICKÝ PŘÍSTUP
void odstranZaporne(vector<double>& v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < 0) {
            v.erase(v.begin() + i); // smaže prvek a VŠECHNO vpravo od něj posune o 1 doleva
            i--; // musíme couvnout iterátorem, abychom nepřeskočili právě posunutý prvek
        }
    }
}

// 33. Vložení nuly za každé záporné číslo
void vlozNuluZaZaporne(vector<double>& v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < 0) {
            v.insert(v.begin() + i + 1, 0); // Vlož nulu za tento prvek
            i++; // Musíme přeskočit tu vloženou nulu, abychom nezůstali trčet v cyklu
        }
    }
}

// 34. Sloučení sousedních čísel (Suma párů) do nového vektoru
vector<double> sectiSousedni(const vector<double>& v) {
    vector<double> vysledek;
    for(int i = 0; i < v.size() - 1; i += 2) {
        vysledek.push_back(v[i] + v[i+1]);
    }
    // Pokud je lichý počet prvků, poslední prvek přihodíme nesečtený
    if(v.size() % 2 != 0) vysledek.push_back(v.back());
    return vysledek;
}

// 35. Nahrazení (Find and Replace)
void nahradPrvek(vector<double>& v, double stareCislo, double noveCislo) {
    for(double& prvek : v) { // REFERENCE (&) je klíčová, abychom to přepsali v originále!
        if(prvek == stareCislo) prvek = noveCislo;
    }
}

// 36. Oříznutí nadlimitních hodnot (Ořezávač / Clamp)
void orizniHodnoty(vector<double>& v, double maxLimit) {
    for(double& prvek : v) {
        if(prvek > maxLimit) prvek = maxLimit;
    }
}

// 37. Skalární násobek (Zvětšení všech čísel)
void vynasobPole(vector<double>& v, double nasobitel) {
    for(double& prvek : v) {
        prvek *= nasobitel;
    }
}

// 38. Doplnění pole na požadovanou délku (Padding)
void dopinNaDelku(vector<double>& v, int pozadovanaDelka) {
    while(v.size() < pozadovanaDelka) {
        v.push_back(0); // Přidává nuly na konec
    }
}

// 39. Smazání prázdného účtu v poli účtů (Polymorfismus)
// Předpokládá: vector<Ucet*> pole;
/* 
void smazPrazdneUcty(vector<Ucet*>& pole) {
    for(int i = 0; i < pole.size(); i++) {
        if(pole[i]->getHistorie().empty()) {
            delete pole[i]; // NEJPRVE uvolníme paměť na haldě (Heap)
            pole.erase(pole.begin() + i); // PAK odstraníme ukazatel z vektoru
            i--;
        }
    }
}
*/

// 40. Třídění (Bubble sort od nejmenšího po největší)
void bubbleSort(vector<double>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        // Posledních 'i' prvků už je usortovaných
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                vymenPrvky(v, j, j+1); // viz Funkce 21
            }
        }
    }
}



//5. Matematičtější logika & Zabezpečení dat (41-50)
//Tyto typy úloh často prověří schopnost používat logické spojky a specifické aritmetické operace, např. bitové.

// 41. Faktoriál (Iterativně) - Použijeme long long, roste to strašně rychle
long long faktorial(int n) {
    if(n <= 1) return 1;
    long long vysledek = 1;
    for(int i = 2; i <= n; i++) vysledek *= i;
    return vysledek;
}

// 42. Zjištění, zda je číslo prvočíslo
bool jePrvocislo(int cislo) {
    if(cislo <= 1) return false;
    // Stačí testovat dělitele jen do odmocniny čísla, zbytek by se zrcadlil
    for(int i = 2; i <= sqrt(cislo); i++) {
        if(cislo % i == 0) return false; // Našli jsme dělitele (zbytek po dělení je 0)
    }
    return true;
}

// 43. Caesarova šifra (posun znaků) - Skvělý úvod do šifrování
void caesarovaSifra(string& text, int klic) {
    for(char& znak : text) { // Musí to být char&
        // Pokud je to písmeno v abecedě (velmi zjednodušená ASCII rotace)
        znak = znak + klic;
    }
}

// 44. XOR transformace nad polem (Základní symetrické šifrování dat)
// Pokud na pole zavoláš tuto funkci znovu se STEJNÝM klíčem, data se vrátí zpět.
void xorSifra(vector<double>& v, int klic) {
    for(double& prvek : v) {
        // XOR (^) pracuje jen s celými čísly, pro ukázku přetypujeme
        int celeCislo = (int)prvek; 
        prvek = celeCislo ^ klic;
    }
}

// 45. Výpočet kontrolního součtu (Checksum modulu 256)
int spocitejChecksum(const vector<double>& v) {
    int soucet = 0;
    for(double prvek : v) {
        soucet += abs((int)prvek);
    }
    return soucet % 256; // Výsledek bude vždy v rozmezí 0-255 (1 bajt)
}

// 46. Konverze desítkového čísla do binární reprezentace
vector<int> prevodDoBinarni(int cislo) {
    vector<int> binarni;
    if(cislo == 0) return {0};
    while(cislo > 0) {
        binarni.push_back(cislo % 2); // Získáme zbytek (0 nebo 1)
        cislo = cislo / 2; // Zmenšíme číslo na polovinu
    }
    // Zbytky vycházejí obráceně, musíme vektor otočit
    reverse(binarni.begin(), binarni.end()); // Ze <algorithm>
    return binarni;
}

// 47. Zjištění parity (Sudost/Lichost) operátorem Bitwise AND (Nejrychlejší)
bool jeSude(int cislo) {
    // Číslo "1" má v binární soustavě na konci jedničku. 
    // Pokud má číslo také jedničku na konci (je liché), AND vrátí 1.
    return (cislo & 1) == 0; 
}

// 48. Normování dat (Min-Max Scaling do rozsahu 0 až 1)
void normujData(vector<double>& v) {
    if(v.empty()) return;
    double min = getMinimum(v); // Funkce 2
    double max = getMaximum(v); // Funkce 1
    if(max - min == 0) return; // Zabráníme dělení nulou, pokud jsou všechna čísla stejná
    
    for(double& prvek : v) {
        prvek = (prvek - min) / (max - min);
    }
}

// 49. Plošný výpočet masky na pole (Aplikace Masky)
void aplikujMasku(vector<double>& v, const vector<int>& maska) {
    // Zabráníme pádu, pokud je maska kratší než pole
    int delka = min(v.size(), maska.size());
    for(int i = 0; i < delka; i++) {
        if(maska[i] == 0) {
            v[i] = 0; // Kde je v masce 0, tam data "vymažeme"
        }
    }
}

// 50. Průnik dvou množin (Najde čísla, která jsou v poli A i B)
vector<double> prunikMnozin(const vector<double>& a, const vector<double>& b) {
    vector<double> vysledek;
    for(double prvek : a) {
        // Ptáme se: Obsahuje pole B prvek z pole A?
        if(obsahujePrvek(b, prvek) && !obsahujePrvek(vysledek, prvek)) { // + zajištění unikátnosti
            vysledek.push_back(prvek);
        }
    }
    return vysledek;
}
