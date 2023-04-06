#pragma once

class Animal {
public:
    Animal* parent;
    virtual void makeSound();
    virtual void walk();
    virtual void eat(int foodAmount);
};
