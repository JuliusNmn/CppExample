#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
    int belly;
    virtual void makeSound() override;
    virtual void walk() override;
    virtual void eat(int foodAmount) override;
};
class Dog : public Animal {
public:
    int belly;
    virtual void makeSound() override;
    virtual void walk() override;
    virtual void eat(int foodAmount) override;
};

