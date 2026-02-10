#ifndef BOHATER_H
#define BOHATER_H

#include <iostream>
#include <string>

class Bohater {
private:
    std::string name;
    int strength;
    int agility;
    int health;
    int maxHealth;
public:
    void przedstawsie();
    void atak(Bohater& cel);
    void odpoczynek();
    //////////////////////////settery//////////////////////////////////
    void setHealth(int health);
    void setStrength(int strength);
    void setAgility(int agility);
    void setName(std::string name);
    void setMaxHealth(int maxHealth);

    /////////////////gettery///////////////////////////
    int getStrength();
    int getAgility();
    int getHealth();
    int getMaxHealth();

    std::string getName();
    Bohater();
    Bohater(std::string name, int health, int strength, int agility);
    ~Bohater();
};

#endif