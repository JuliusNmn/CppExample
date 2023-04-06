#include <stdio.h>
#include <stdlib.h>
#include "Animal.h"
#include "NormalAnimals.h"
#include "TestAnimals.h"

Animal* createAnimalPointer() {
    return new Cat();
}
Animal createWholeAnmimal(){
    Dog d;
    return d;
}
void multiArgFunction(Animal* a, Animal* b, int c, long d) {
	Animal* x;
    if (c > d) {
        x = a;
    } else {
        x = b;
    }
    x->eat(15);
    if (x->parent) {
        x->parent->eat(64);
    }
}
void feedAnimalPointer(Animal* a) {
    a->eat(10);
}
void feedWholeAnimal(Animal a) {
    a.eat(20);
}



void callMultiArgFunction() {
    Dog* d = new Dog();
    Cat* c = new Cat();
    multiArgFunction(c, d, 0x10, 0x100);
}

void callMultiArgFunctionByValue(){
    Dog d =  Dog();
    Cat c =  Cat();
    multiArgFunction(&c, &d, 0x10, 0x100);
}

void callValueFunction(){
    Cat c = Cat();
    c.eat(0x10);
    printf("cat belly %d",c.belly);
    feedWholeAnimal(c);
}

void pointerArrayMalloc(){
    Dog** dogs = (Dog**)malloc(sizeof(Dog*) * 10);
    for (int i = 0; i < 10; i++) {
        Dog* d = new Dog();
        dogs[i] = d;
    }

    dogs[0x5]->eat(0x2);
}

void pointerArray(){
    Dog** dogs = new Dog*[10];
    for (int i = 0; i < 10; i++) {
        Dog* d = new Dog();
        dogs[i] = d;
    }

    dogs[0x5]->eat(0x3);
}


void valueArray(){
    Dog* dogs = new Dog[10];
    for (int i = 0; i < 10; i++) {
        Dog* d = new Dog();
        dogs[i] = *d;
    }
    Dog* d = &(dogs[0x5]);
    d->eat(0x4);
}


void feedParent(Animal* c) {
    c->parent->eat(15);
}

void addParent(Animal* a) {
    a->parent = new Cat();
}

void storePointerInField(){
    Cat* c = new Cat();
    addParent(c);
    feedParent(c);
}

int main(){
    printf("Hello World.\n");
    Animal* c = new Cat();
    c->makeSound();
    c->walk();
    c->eat(0x69);
    Animal* d = createAnimalPointer();
    feedAnimalPointer(d);
    Dog* doggo = new Dog();
    doggo->eat(0x79);

    feedWholeAnimal(*doggo);
    
    Animal e = createWholeAnmimal();

    feedWholeAnimal(e);

    InstantiatedButUnusedAnimal* xxx = new InstantiatedButUnusedAnimal();
    printf("%x", sizeof(xxx));

    multiArgFunction(d, &e, 0x10, 0x100);



    callMultiArgFunction();
    callMultiArgFunctionByValue();
    callValueFunction();
    
    pointerArrayMalloc();
    pointerArray();
    valueArray();

    storePointerInField();


    return 0;
}
