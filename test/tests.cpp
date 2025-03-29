// Copyright 2024 UNN-IASR

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../include/Automata.h"

TEST(AutomataTest, Initialization) {
    Automata coffeeMachine;
    EXPECT_EQ(coffeeMachine.GetState(), OFF);
    std::vector<std::string> menu = coffeeMachine.GetMenu();
    EXPECT_EQ(menu.size(), 4);
    EXPECT_EQ(menu[0], "Espresso");
    EXPECT_EQ(menu[1], "Americano");
    EXPECT_EQ(menu[2], "Cappuccino");
    EXPECT_EQ(menu[3], "Latte");
}

TEST(AutomataTest, TurnOn) {
    Automata coffeeMachine;
    coffeeMachine.On();
    EXPECT_EQ(coffeeMachine.GetState(), WAIT);
}

TEST(AutomataTest, TurnOff) {
    Automata coffeeMachine;
    coffeeMachine.On();
    coffeeMachine.Off();
    EXPECT_EQ(coffeeMachine.GetState(), OFF);
}

TEST(AutomataTest, InsertMoney) {
    Automata coffeeMachine;
    coffeeMachine.On();
    coffeeMachine.Coin(100);
    EXPECT_EQ(coffeeMachine.GetState(), ACCEPT);
}

TEST(AutomataTest, SelectDrink) {
    Automata coffeeMachine;
    coffeeMachine.On();
    coffeeMachine.Coin(200);
    coffeeMachine.Choice(2);
    EXPECT_EQ(coffeeMachine.GetState(), CHECK);
}

TEST(AutomataTest, CancelOrder) {
    Automata coffeeMachine;
    coffeeMachine.On();
    coffeeMachine.Coin(200);
    coffeeMachine.Cancel();
    EXPECT_EQ(coffeeMachine.GetState(), WAIT);
}

TEST(AutomataTest, SuccessfulOrder) {
    Automata coffeeMachine;
    coffeeMachine.On();
    coffeeMachine.Coin(200);
    EXPECT_TRUE(coffeeMachine.ProcessOrder(2));
    EXPECT_EQ(coffeeMachine.GetState(), WAIT);
}

TEST(AutomataTest, InsufficientFunds) {
    Automata coffeeMachine;
    coffeeMachine.On();
    coffeeMachine.Coin(100);
    EXPECT_FALSE(coffeeMachine.ProcessOrder(2));
    EXPECT_EQ(coffeeMachine.GetState(), WAIT);
}

TEST(AutomataTest, InvalidDrinkChoice) {
    Automata coffeeMachine;
    coffeeMachine.On();
    coffeeMachine.Coin(200);
    coffeeMachine.Choice(5);
    EXPECT_EQ(coffeeMachine.GetState(), ACCEPT);
}

TEST(AutomataTest, CompleteOrderSequence) {
    Automata coffeeMachine;
    coffeeMachine.On();
    EXPECT_EQ(coffeeMachine.GetState(), WAIT);
    coffeeMachine.Coin(200);
    EXPECT_EQ(coffeeMachine.GetState(), ACCEPT);
    EXPECT_TRUE(coffeeMachine.ProcessOrder(2));
    EXPECT_EQ(coffeeMachine.GetState(), WAIT);
}
