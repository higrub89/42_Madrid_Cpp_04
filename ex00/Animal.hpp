/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:44:32 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/21 23:52:18 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal(void);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal(void);

    std::string const & getType(void) const;
    virtual void makeSound(void) const;
};

#endif
