#include "NormalAnimals.h"
#include <cstdio>

void Cat::makeSound() {
    printf("Meow\n");
}

void Cat::walk() {
    printf("I step step with mz cat paws\n");
}

void Cat::eat(int foodAmount) {
    belly += foodAmount;
    printf("Meow i like the cat food. My belly is this full: %d\n", belly);
    printf("I will walk to my bed now to take a nap.\n");
    walk();

}


void Dog::makeSound() {
    printf("Woof\n");
}

void Dog::walk() {
    printf("I gots the zoomies\n");
}

void Dog::eat(int foodAmount) {
    belly += foodAmount;
    printf("I am a hungry dog. My belly is this full: %d\n", belly);
    printf("i will bark now\n");
    makeSound(); 


}
