#include "Bohater.h"
//////////////////////////metody///////////////////////////////////
void Bohater::przedstawsie() {
    std::cout << "Witaj " << name << "\nsi³a: " << strength << "\nzrêcznoœæ " << agility 
        << "\nzdrowie " << health << '\n' << "Zdrowie maksymalne"<< maxHealth << '\n';
}

void Bohater::atak(Bohater& cel) {   //odebranie obiektu cel i zmniejszenie zycia celu o si³ê obiektu, który wywo³uje metodê atak
    int podstawa = this->strength / 2;
    int losowy_bonus = rand() % ((this->strength / 2) + 1);
    int dmg = podstawa + losowy_bonus;
    int szansa_na_unik = rand() % 100;
    if (szansa_na_unik < cel.agility)
    {
        dmg = 0;
        std::cout << "unik\n";
    }
    else{
        std::cout << name <<'\t' << dmg << "\n\n";
        cel.setHealth(cel.getHealth() - dmg);
    }
}

void Bohater::odpoczynek() {
    this->health = maxHealth;
}
//////////////////////////settery//////////////////////////////////
void Bohater::setHealth(int health) {
    if (health < 0)
    {
        this->health = 0;
    }
    else
        this->health = health;
}

void Bohater::setStrength(int strength) {
    if (strength < 0)
    {
        this->strength = 5;
    }
    else
        this->strength = strength;
}

void Bohater::setAgility(int agility) {
    if (agility < 0)
    {
        this->agility = 5;
    }
    else
        this->agility = agility;
}

void Bohater::setName(std::string name) {
    this->name = name;
}

void Bohater::setMaxHealth(int maxHealth) {
    this->maxHealth = maxHealth;
}
/////////////////gettery///////////////////////////
int Bohater::getStrength() { return strength; }
int Bohater::getAgility() { return agility; }
int Bohater::getHealth() { return health; }
int Bohater::getMaxHealth() { return maxHealth; }
std::string Bohater::getName() { return name; }

Bohater::Bohater() {
    health = 100;
    maxHealth = health;
    strength = 10;
    agility = 10;
    name = "Bezimienny";
}

Bohater::Bohater(std::string name, int health, int strength, int agility) {
    this->health = health;
    this->maxHealth = health;
    this->strength = strength;
    this->agility = agility;
    this->name = name;
}
Bohater::~Bohater() {
    std::cout << "umieram " << name << '\n';
}