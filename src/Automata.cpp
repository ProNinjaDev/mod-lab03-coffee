// Copyright 2024 UNN-IASR

#include <string>
#include <vector>
#include "../include/Automata.h"

Automata::Automata() {
    Cash = 0;
    State = OFF;
    SelectedDrink = -1;

    Menu = {
        "Espresso",
        "Americano",
        "Cappuccino",
        "Latte"
    };

    Prices = {
        100,
        150,
        200,
        250
    };
}

void Automata::On() {
    State = WAIT;
}

void Automata::Off() {
    State = OFF;
}

void Automata::Coin(int amount) {
    if (State == WAIT || State == ACCEPT) {
        Cash += amount;
        State = ACCEPT;
    }
}

std::vector<std::string> Automata::GetMenu() {
    return Menu;
}

STATES Automata::GetState() {
    return State;
}

void Automata::Choice(int numDrink) {
    if (State == ACCEPT) {
        if (numDrink >= 0 && numDrink < Menu.size()) {
            SelectedDrink = numDrink;
            State = CHECK;
        }
    }
}

bool Automata::Check() {
    if (State == CHECK) {
        if (SelectedDrink >= 0 && SelectedDrink < Prices.size()) {
            if (Cash >= Prices[SelectedDrink]) {
                Cash -= Prices[SelectedDrink];
                return true;
            }
        }
        State = WAIT;
        return false;
    }
    return false;
}

void Automata::Cancel() {
    if (State == ACCEPT || State == CHECK) {
        Cash = 0;
        State = WAIT;
    }
}

void Automata::Cook() {
    if (State == CHECK) {
        State = COOK;
    }
}

void Automata::Finish() {
    if (State == COOK) {
        Cash = 0;
        SelectedDrink = -1;
        State = WAIT;
    }
}

bool Automata::ProcessOrder(int numDrink) {
    if (State != ACCEPT) {
        return false;
    }
    
    Choice(numDrink);
    if (State != CHECK) {
        return false;
    }
    
    if (!Check()) {
        return false;
    }
    
    Cook();
    Finish();
    return true;
} 