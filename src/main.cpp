#include "../include/Automata.h"
#include <iostream>

int main() {
    Automata coffeeMachine;
    
    coffeeMachine.On();
    
    std::vector<std::string> menu = coffeeMachine.GetMenu();
    
    coffeeMachine.Coin(50);
    
    coffeeMachine.Choice(0);
    
    if (coffeeMachine.Check()) {
        coffeeMachine.Cook();
        coffeeMachine.Finish();
    }
    
    coffeeMachine.Off();
    
    return 0;
} 