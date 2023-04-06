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
