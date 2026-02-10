#include <iostream>
#include <string>
#include <cstdlib>
#include <clocale>
class Bohater {
private:
    std::string name;
    int strength;
    int agility;
    int health;
public:
    void przedstawsie() {
        std::cout << "Witaj " << name << "\nsi³a: " << strength << "\nzrêcznoœæ " << agility << "\nzdrowie " << health << '\n' << '\n';
    }

    void atak(Bohater& cel) {   //odebranie obiektu cel i zmniejszenie zycia celu o si³ê obiektu, który wywo³uje metodê atak
        cel.health -= this->strength;
    }
    //////////////////////////settery//////////////////////////////////
    void setHealth(int health) {
        if (health < 0)
        {
            this->health = 0;
        }
        else
            this->health = health;
    }

    void setStrength(int strength) {
        if (strength < 0)
        {
            this->strength = 5;
        }
        else
            this->strength = strength;
    }

    void setAgility(int agility) {
        if (agility < 0)
        {
            this->agility = 5;
        }
        else
            this->agility = agility;
    }

    void setName(std::string name) {
        this->name = name;
    }

    /////////////////gettery///////////////////////////
    int getStrength() { return strength; }
    int getAgility() { return agility; }
    int getHealth() { return health; }
    std::string getName() { return name; }
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


int main()
{
    setlocale(LC_CTYPE, "Polish");
    int choose;
    Bohater smok("Smok Wawelski", 2000, 100, 0);
    Bohater glownyBohater;
    do {
        std::cout << "Witaj w œwiecie Opus RPG\n\n";
        std::cout << "\t1. Nowa Gra\n";
        std::cout << "\t2. Wyjœcie\n";
        std::cout << "\t3. Atakuj smoka\n";
        std::cin >> choose;
        switch (choose) {
        case 1:
            glownyBohater = tworzeniePostaci();
        break;
        case 2:
            std::cout << "Zegnaj\n";
            break;
        case 3:
            glownyBohater.atak(smok);
            smok.przedstawsie();
            smok.atak(glownyBohater);
            glownyBohater.przedstawsie();
            break;
        default:
            std::cout << "Wybierz 1,2 albo 3";
            break;
        }
    } while (choose != 2);
    glownyBohater.przedstawsie();
}