/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:51:06 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/23 23:51:11 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) : _type("default") {
}

AMateria::AMateria(std::string const & type) : _type(type) {
}

AMateria::AMateria(AMateria const & other) : _type(other._type) {
}

AMateria& AMateria::operator=(AMateria const & other) {
    if (this != &other) {
        (void)other;
    }
    return *this;
}

AMateria::~AMateria(void) {
}

std::string const & AMateria::getType() const {
    return this->_type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}
