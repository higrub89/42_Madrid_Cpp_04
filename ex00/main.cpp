/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:31:06 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/22 17:31:07 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

/* int main(void) {
    std::cout << "\n=== TEST 1: Basic polymorphism (should work) ===\n" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();    
    meta->makeSound(); 
    delete meta;
    delete j;
    delete i;

    std::cout << "\n========================================\n";
    std::cout << "  TEST 2: WRONG NO POLYMORPHISM           \n";
    std::cout << "========================================\n\n";
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

    std::cout << wrongI->getType() << " " << std::endl;
    wrongI->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongI;

    std::cout << "\n=== TEST COPY ===\n" << std::endl;

    Dog basic;
    {
        Dog tmp = basic;
    } 

    Cat copyCat;
    copyCat = Cat();

    return 0;
}
 */

 int main()
 {
    Animal animal ("Perro");
    return 0;
 }