#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>
#include <vector>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
private:
    int Cash;
    std::vector<std::string> Menu;
    std::vector<int> Prices;
    STATES State;

public:
    Automata();
    void On();
    void Off();
    void Coin(int amount);
    std::vector<std::string> GetMenu();
    STATES GetState();
    void Choice(int numDrink);
    bool Check();
    void Cancel();
    void Cook();
    void Finish();
};

#endif