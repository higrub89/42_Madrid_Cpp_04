/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:38:52 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/22 16:38:53 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "Meow!" << std::endl;
}
