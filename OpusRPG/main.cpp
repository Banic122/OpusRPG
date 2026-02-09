#include <iostream>
#include <string>
#include <cstdlib>
#include <clocale>
class Bohater {
public:
    std::string name;
    int strength;
    int agility;
    int health;

    void przedstawsie() {
        std::cout << "Witaj " << name << "\nsi³a: " << strength << "\nzrêcznoœæ " << agility << "\nzdrowie " << health << '\n';
    }

    void atak(Bohater &cel) {
        this->health = health - strength;
    }

    Bohater() {
        health = 100;
        strength = 10;
        agility = 10;
        name = "Bezimienny";
    }

    Bohater(std::string name, int health, int strength, int agility) {
        this->health = health;
        this->strength = strength;
        this->agility = agility;
        this->name = name;
    }
    ~Bohater() {
        std::cout << "umieram " << name <<'\n';
    }
};

Bohater tworzeniePostaci() {
    Bohater gracz;
    Bohater smok("Smok Wawelski", 2000, 50, 0);
    smok.przedstawsie();
    std::cout << "Jak masz na imiê przyjacielu?\n";
    std::cin >> gracz.name;
    do {
        std::cout << "Podaj wartoœæ zdrowia,\n";
        std::cout << "Suma si³y i zrêcznoœcinie mo¿e przekraczaæ 20\n";
        std::cin >> gracz.health;
        std::cout << "Podaj wartoœæ si³y,\n";
        std::cin >> gracz.strength;
        std::cout << "Podaj wartoœæ zrêcznoœci,\n";
        std::cin >> gracz.agility;

    } while (gracz.strength + gracz.agility > 20 || gracz.strength < 0 || gracz.agility < 0);
    std::cout << "Statystyki zaakceptowane!\n";

    if (gracz.name == "Geralt") {
        std::cout << "Witaj, WiedŸminie!\n";
    }
    gracz.przedstawsie();
    return gracz;
}


int main()
{
    setlocale(LC_CTYPE, "Polish");
    int choose;
    Bohater smok("Smok Wawelski", 2000, 50, 0);
    Bohater glownyBohater;
    do {
        std::cout << "Witaj w œwiecie Opus RPG\n\n";
        std::cout << "\t1. Nowa Gra\n";
        std::cout << "\t2. Wyjœcie\n";
        std::cin >> choose;
        switch (choose) {
        case 1:
            glownyBohater = tworzeniePostaci();
        break;
        case 2:
            std::cout << "Zegnaj\n";
            break;
        default:
            std::cout << "Wybierz 1 albo 2";
            break;
        }
    } while (choose != 2);
    glownyBohater.przedstawsie();
    
}