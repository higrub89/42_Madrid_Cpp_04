/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:34:49 by rhiguita          #+#    #+#             */
/*   Updated: 2026/03/06 14:34:50 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : _name(name), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 64; i++)
		_floor[i] = NULL;
	std::cout << "Character [" << _name << "] constructed" << std::endl;
}

Character::Character(Character const & other) : ICharacter(other), _name(other._name), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 64; i++)
		_floor[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
	std::cout << "Character [" << _name << "] copy constructed" << std::endl;
}

Character & Character::operator=(Character const & other)
{
	if (this == &other)
		return *this;
	_name = other._name;
	
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
	std::cout << "Character [" << _name << "] copy assigned" << std::endl;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	for (int i = 0; i < _floorCount; i++)
		delete _floor[i];
	std::cout << "Character [" << _name << "] destroyed" << std::endl;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << _name << " equipped " << m->getType() << " in slot " << i << std::endl;
			return;
		}
	}
	std::cout << _name << "'s inventory is full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return;
	if (_floorCount < 64)
	{
		_floor[_floorCount++] = _inventory[idx];
		std::cout << _name << " unequipped " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
	}
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return;
	_inventory[idx]->use(target);
}