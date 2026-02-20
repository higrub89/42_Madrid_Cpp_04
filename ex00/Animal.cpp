/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:00:33 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/20 15:00:35 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructor por defecto
Animal::Animal(void) : type("Animal") {
    std::cout << "[Animal] Constructor por defecto invocado. Chasis ensamblado." << std::endl;
}

// Constructor de copia
Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "[Animal] Constructor de copia invocado." << std::endl;
}

// Operador de asignación
Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal] Operador de asignación invocado." << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// Destructor virtual
Animal::~Animal(void) {
    std::cout << "[Animal] Destructor invocado. Memoria liberada." << std::endl;
}

// Telemetría de lectura
std::string Animal::getType(void) const {
    return this->type;
}

// Función virtual base
void Animal::makeSound(void) const {
    std::cout << "[Animal] * Ruido de motor genérico no especificado *" << std::endl;
}
