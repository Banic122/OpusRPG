#include <iostream>
#include <string>
#include <cstdlib>
#include <clocale>
#include "Bohater.h"
#include "Mechanika.h"
#include <ctime>


int main()
{
    srand(time(0));
    setlocale(LC_CTYPE, "Polish");
    int choose;
    Bohater smok("Smok Wawelski", 2000, 10, 0);
    Bohater glownyBohater;
    do {
        std::cout << "Witaj w œwiecie Opus RPG\n\n";
        std::cout << "\t1. Nowa Gra\n";
        std::cout << "\t2. Wyjœcie\n";
        std::cout << "\t3. Atakuj smoka\n";
        std::cout << "\t4. Odpoczynek\n";
        std::cout << "\t5. Pokaz smoka\n";
        std::cout << "\t6. Pokaz Bohatera\n";
        std::cin >> choose;
        switch (choose) {
        case 1:
            glownyBohater = tworzeniePostaci();
        break;
        case 2:
            std::cout << "Zegnaj\n";
            break;
        case 3:
            if (glownyBohater.getHealth() <= 0) {
                std::cout << "Lepiej odpocznij\n";
            }else
            walka(glownyBohater, smok);
            break;
        case 4:
            glownyBohater.odpoczynek();
            break;
        case 5:
            smok.przedstawsie();
            break;
        case 6:
            glownyBohater.przedstawsie();
            break;
        default:
            std::cout << "Wybierz 1,2,3 albo 4";
            break;
        }
    } while (choose != 2);
    glownyBohater.przedstawsie();
}