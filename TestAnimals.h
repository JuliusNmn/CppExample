#pragma once
#include "Animal.h"

class DeadNeverInstantiatedAnimal : public Animal {
public:
    virtual void makeSound() override;
    virtual void walk() override;
    virtual void eat(int foodAmount) override;
};
class InstantiatedButUnusedAnimal : public Animal {
public:
    virtual void makeSound() override;
    virtual void walk() override;
    virtual void eat(int foodAmount) override;
};

class Human {
    public:
    virtual void talk();

};

class Hybrid : public virtual Human, public virtual Animal {
public:
    virtual void makeSound() override;
    virtual void walk() override;
    virtual void eat(int foodAmount) override;
    virtual void talk() override;
};
