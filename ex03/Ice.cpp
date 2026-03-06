/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:35:21 by rhiguita          #+#    #+#             */
/*   Updated: 2026/03/06 14:35:22 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructed" << std::endl;
}

Ice::Ice(Ice const & other) : AMateria(other)
{
	std::cout << "Ice copy constructed" << std::endl;
}

Ice & Ice::operator=(Ice const & other)
{
	(void)other;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destroyed" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}