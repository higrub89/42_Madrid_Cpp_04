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

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main(void) {
    std::cout << "\n==================================================\n";
    std::cout << "  TEST 1: RESTRIC ABSTRACT CLASS                    \n";
    std::cout << "==================================================\n\n";

    /* AAnimal prueba = AAnimal(); */

    Dog AmericanPitbull;
    Cat Tommy;
    
    std::cout << "\n==================================================\n";
    std::cout << "  TEST 2: POLYMORFISM AND BÁSIC DELETE              \n";
    std::cout << "==================================================\n\n";
    

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    std::cout << "\n--- Sound Test ---/n" << std::endl;
    j->makeSound();
    i->makeSound(); 
    
    std::cout << "\n--- free memory ---/n" << std::endl;
    delete j;
    delete i;

    std::cout << "\n==================================================\n";
    std::cout << "  TEST 3: ARRAY ANIMALS AND DEEP COPY               \n";
    std::cout << "==================================================\n\n";
    
    const int numAnimals = 4;
    AAnimal* animals[numAnimals];
    
    for (int idx = 0; idx < numAnimals; ++idx) {
        if (idx < numAnimals / 2) {
            animals[idx] = new Dog();
        } else {
            animals[idx] = new Cat();
        }
    }

    std::cout << "\n--- sound---\n" << std::endl;
    for (int idx = 0; idx < numAnimals; ++idx) {
        animals[idx]->makeSound();
    }
    std::cout << "\n" << std::endl;
    for (int idx = 0; idx < numAnimals; ++idx) {
        delete animals[idx];
    }

    return 0;
}
