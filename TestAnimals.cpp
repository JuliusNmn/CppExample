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
        printf(" blah blah \n");
 }

 void Human::think(){
        printf(" hmmmm  \n");
 }


void Hybrid::makeSound() {
    printf(" ahh\n");
}
    void Hybrid::walk(){
    printf(" ahh\n");
}
void Hybrid::eat(int foodAmount) {
    printf(" ahh %d\n", foodAmount);
}
    void Hybrid::talk(){
    printf(" ahh bla bla \n");
}
 void Hybrid::think(){
        printf("ahhh  hmmmm  \n");
 }