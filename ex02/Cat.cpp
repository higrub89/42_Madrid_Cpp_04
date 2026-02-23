/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:04:44 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/23 22:04:45 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        this->type = other.type;
        if (this->brain) {
            delete this->brain;
        }
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat(void) {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, std::string const & idea) {
    this->brain->setIdea(index, idea);
}

std::string const & Cat::getIdea(int index) const {
    return this->brain->getIdea(index);
}
