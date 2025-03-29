// Copyright 2024 UNN-IASR

#include <iostream>
#include <string>
#include <vector>
#include "../include/Automata.h"

int main() {
    Automata coffeeMachine;
    
    std::cout << "Turning on the coffee machine..." << std::endl;
    coffeeMachine.On();
    
    std::cout << "Menu:" << std::endl;
    coffeeMachine.GetMenu();
    
    std::cout << "Inserting money: 200 ninja coins" << std::endl;
    coffeeMachine.Coin(200);
    
    std::cout << "Selecting drink: Cappuccino" << std::endl;
    if (coffeeMachine.ProcessOrder(2)) {
        std::cout << "Drink is ready!" << std::endl;
    } else {
        std::cout << "Failed to process order" << std::endl;
    }
    
    std::cout << "Turning off the coffee machine..." << std::endl;
    coffeeMachine.Off();
    
    return 0;
}