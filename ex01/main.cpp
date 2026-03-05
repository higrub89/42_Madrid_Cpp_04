/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:05:05 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/23 22:05:07 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main(void) {

    std::cout << "\n==================================================\n";
    std::cout << "          TEST 1: BASIC DELETE                       \n";
    std::cout << "==================================================\n\n";
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
    }

    std::cout << "\n==================================================\n";
    std::cout << "          TEST 2:  ANIMALS ARRAYS                   \n";
    std::cout << "==================================================\n\n";
    
    const int numAnimals = 4;
    Animal* animals[numAnimals];
    
    for (int i = 0; i < numAnimals; ++i) {
        if (i < numAnimals / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }
    
    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->makeSound();
    }
    
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    std::cout << "\n==================================================\n";
    std::cout << "          TEST 3: DEEP COPY                         \n";
    std::cout << "==================================================\n\n";
    
    Dog originalDog;
    originalDog.setIdea(0, "Chase the ball!");
    
    Dog copyDog = originalDog; 
    originalDog.setIdea(0, "Bark at mailman!"); 
    
    std::cout << "Original Dog Idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copy Dog Idea 0:     " << copyDog.getIdea(0) << " ( must be 'Chase the ball!' )\n " << std::endl;

    Cat originalCat;
    originalCat.setIdea(0, "Sleep all day");
    
    Cat assignedCat;
    assignedCat = originalCat; 
    originalCat.setIdea(0, "Scratch furniture"); 
    
    std::cout << "Original Cat Idea 0: " << originalCat.getIdea(0) << std::endl;
    std::cout << "Assigned Cat Idea 0: " << assignedCat.getIdea(0) << " (must be: 'Sleep all day')\n " << std::endl;

    return 0;
}
