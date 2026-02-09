// OpusRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <clocale>

int main()
{
    setlocale(LC_CTYPE, "Polish");
    int choose;
    do {
        std::cout << "Witaj w œwiecie Opus RPG\n\n";
        std::cout << "\t1. Nowa Gra\n";
        std::cout << "\t2. Wyjœcie\n";
        std::cin >> choose;
        switch (choose) {
        case 1:
        {
            std::cout << "Jak masz na imiê przyjacielu?\n";
            std::string name;
            std::cin >> name;
            int strength, health, agility;
            do {
                std::cout << "Podaj wartoœæ zdrowia,\n";
                std::cout << "Suma si³y i zrêcznoœcinie mo¿e przekraczaæ 20\n";
                std::cin >> health;
                std::cout << "Podaj wartoœæ si³y,\n";
                std::cin >> strength;
                std::cout << "Podaj wartoœæ zrêcznoœci,\n";
                std::cin >> agility;
                
            } while (strength + agility > 20 || strength < 0 || agility < 0);
            std::cout << "Statystyki zaakceptowane!\n";

            if (name == "Geralt") {
                std::cout << "Witaj, WiedŸminie!\n";
            }
            std::cout << "Witaj " << name << "\nsi³a: " << strength << "\nzrêcznoœæ " << agility << "\nzdrowie " << health << '\n';
        }

        break;
        case 2:
            std::cout << "Zegnaj\n";
            break;
        default:
            std::cout << "Wybierz 1 albo 2";
            break;
        }
    } while (choose != 2);
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
