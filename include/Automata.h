// Copyright 2024 UNN-IASR

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

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
    int SelectedDrink;

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
    bool ProcessOrder(int numDrink);
};

#endif  // INCLUDE_AUTOMATA_H_
