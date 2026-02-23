/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:39:26 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/23 22:39:28 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main(void) {
    std::cout << "\n==================================================\n";
    std::cout << "  TEST 1: RESTRICCIÓN DE CLASE ABSTRACTA            \n";
    std::cout << "==================================================\n\n";

    std::cout << "Intentar instanciar un 'Animal' directamente dará error de compilación.\n";
    std::cout << "Descomenta la línea 26 para comprobar la protección estructural.\n";
    
    // ANIMAL GENÉRICO BLOQUEADO POR EL COMPILADOR:
    // Animal testAnimal; 
    // const Animal* meta = new Animal();

    std::cout << "\n==================================================\n";
    std::cout << "  TEST 2: POLIMORFISMO Y ELIMINACIÓN BÁSICA       \n";
    std::cout << "==================================================\n\n";
    
    // El polimorfismo a través de punteros a la clase base abstracta SIGUE PERMITIDO
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\n--- Audio Test ---" << std::endl;
    j->makeSound(); // Llama a Dog::makeSound()
    i->makeSound(); // Llama a Cat::makeSound()
    
    std::cout << "\n--- Liberación de Memoria ---" << std::endl;
    delete j;
    delete i;

    std::cout << "\n==================================================\n";
    std::cout << "  TEST 3: ARREGLO DE ANIMALES Y DEEP COPY (Control)\n";
    std::cout << "==================================================\n\n";
    
    const int numAnimals = 4;
    Animal* animals[numAnimals];
    
    for (int idx = 0; idx < numAnimals; ++idx) {
        if (idx < numAnimals / 2) {
            animals[idx] = new Dog();
        } else {
            animals[idx] = new Cat();
        }
    }
    
    for (int idx = 0; idx < numAnimals; ++idx) {
        animals[idx]->makeSound();
    }
    
    for (int idx = 0; idx < numAnimals; ++idx) {
        delete animals[idx];
    }

    return 0;
}
