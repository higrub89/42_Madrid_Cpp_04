/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:08:47 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/23 22:08:49 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        this->type = other.type;
        if (this->brain) {
            delete this->brain;
        }
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog(void) {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "Woof Woof!" << std::endl;
}

void Dog::setIdea(int index, std::string const & idea) {
    this->brain->setIdea(index, idea);
}

std::string const & Dog::getIdea(int index) const {
    return this->brain->getIdea(index);
}
