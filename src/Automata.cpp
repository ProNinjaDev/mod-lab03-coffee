#include "../include/Automata.h"

Automata::Automata() {
    Cash = 0;
    State = OFF;
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
        State = CHECK;
    }
}

bool Automata::Check() {
    if (State == CHECK) {
        return true;
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
    Cash = 0;
    State = WAIT;
} 