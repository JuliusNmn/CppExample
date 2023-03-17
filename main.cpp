#include <stdio.h>
#include <stdlib.h>
class Animal {

    public:
    Animal* parent;
    virtual void makeSound() {
        printf("I do not exist");
    }
    virtual void walk() {
        printf("I do not exist");
    }
    virtual void eat(int foodAmount) {
        printf("I do not exist. someone fed me %d but i am unable to consume.", foodAmount);
    }
};

class DeadNeverInstantiatedAnimal : public Animal  {
    virtual void makeSound() {
        printf("I am dead");
    }
    virtual void walk() {
        printf("I am dead");
    }
    virtual void eat(int foodAmount) {
        printf("I am dead");
    }
};

class InstantiatedButUnusedAnimal : public Animal {
    virtual void makeSound() {
        printf("I am dead");
    }
    virtual void walk() {
        printf("I am dead");
    }
    virtual void eat(int foodAmount) {
        printf("I am dead");
    }
};

class Cat : public Animal {

    public:
    int belly;
    virtual void makeSound() {
            printf("Meow");
    }
    virtual void walk() {
        printf("I step step with mz cat paws");
    }
    virtual void eat(int foodAmount) {
        belly += foodAmount;
        printf("Meow i like the cat food. My belly is this full: %d", belly);
    }
};
class Dog : public Animal {

    public:
    int belly;
    virtual void makeSound() {
            printf("Woof");
    }
    virtual void walk() {
        printf("I gots the zoomies");
    }
    virtual void eat(int foodAmount) {
        belly += foodAmount;
        printf("I am a hungry dog. My belly is this full: %d", belly);
    }
};
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


void valueArrayMalloc(){
    Dog* dogs = (Dog*)malloc(sizeof(Dog) * 10);
    for (int i = 0; i < 10; i++) {
        Dog d = Dog();
        dogs[i] = d;
    }

    dogs[0x5].eat(0x4);
}

void valueArray(){
    Dog* dogs = new Dog[10];
    for (int i = 0; i < 10; i++) {
        Dog d = Dog();
        dogs[i] = d;
    }

    dogs[0x5].eat(0x5);
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
    valueArrayMalloc();
    valueArray();

    storePointerInField();


    return 0;
}
