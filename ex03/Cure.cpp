/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:35:11 by rhiguita          #+#    #+#             */
/*   Updated: 2026/03/06 14:35:12 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructed" << std::endl;
}

Cure::Cure(Cure const & other) : AMateria(other)
{
	std::cout << "Cure copy constructed" << std::endl;
}

Cure & Cure::operator=(Cure const & other)
{
	(void)other;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destroyed" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}