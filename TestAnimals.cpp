#include "TestAnimals.h"
#include <cstdio>

void DeadNeverInstantiatedAnimal::makeSound() {
    printf("I am dead\n");
}

void DeadNeverInstantiatedAnimal::walk() {
    printf("I am dead\n");
}

void DeadNeverInstantiatedAnimal::eat(int foodAmount) {
    printf("I am dead\n");
}
void InstantiatedButUnusedAnimal::makeSound() {
    printf("I am dead\n");
}

void InstantiatedButUnusedAnimal::walk() {
    printf("I am dead\n");
}

void InstantiatedButUnusedAnimal::eat(int foodAmount) {
    printf("I am dead\n");
}


void Human::talk(){
        printf(" blah blah ");
 }

void Hybrid::makeSound() {
    printf(" ahh");
}
    void Hybrid::walk(){
    printf(" ahh");
}
    void Hybrid::eat(int foodAmount) {
    printf(" ahh %d", foodAmount);
}
    void Hybrid::talk(){
    printf(" ahh");
}
