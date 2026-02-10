#include <iostream>
#include <string>
#include "Mechanika.h"

Bohater tworzeniePostaci() {
    Bohater gracz;
    std::cout << "Jak masz na imiê przyjacielu?\n";
    std::string tempName;
    std::cin >> tempName;
    gracz.setName(tempName);
    do {
        std::cout << "Podaj wartoœæ zdrowia,\n";
        std::cout << "Suma si³y i zrêcznoœcinie mo¿e przekraczaæ 20\n";
        int tempHealth;
        int tempStrength;
        int tempAgility;
        std::cin >> tempHealth;
        gracz.setMaxHealth(tempHealth);
        gracz.setHealth(tempHealth);
        std::cout << "Podaj wartoœæ si³y,\n";
        std::cin >> tempStrength;
        gracz.setStrength(tempStrength);
        std::cout << "Podaj wartoœæ zrêcznoœci,\n";
        std::cin >> tempAgility;
        gracz.setAgility(tempAgility);

    } while (gracz.getStrength() + gracz.getAgility() > 20 || gracz.getStrength() < 0 || gracz.getAgility() < 0);
    std::cout << "Statystyki zaakceptowane!\n";

    if (gracz.getName() == "Geralt") {
        std::cout << "Witaj, WiedŸminie!\n";
    }
    gracz.przedstawsie();
    return gracz;
}

void walka(Bohater& atakujacy, Bohater& obronca) {
    
    
    do {
        if (atakujacy.getHealth() > 0) {
            atakujacy.atak(obronca);
        }
        
        if (obronca.getHealth() > 0) {
            obronca.przedstawsie();
            obronca.atak(atakujacy);
            atakujacy.przedstawsie();
        }

    } while (atakujacy.getHealth() > 0 && obronca.getHealth() > 0);
    if (atakujacy.getHealth() > 0) {
        std::cout << "\n\n\nWygra³eœ " << atakujacy.getName() << '\n';
        atakujacy.przedstawsie();
    }
    else
    {
        std::cout << "\n\n\nWygra³ " << obronca.getName() << '\n';
        obronca.przedstawsie();
    }
}