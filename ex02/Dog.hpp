/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:07:34 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/23 22:07:37 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
    Brain* brain;

public:
    Dog(void);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog(void);

    void makeSound(void) const;
    void setIdea(int index, std::string const & idea);
    std::string const & getIdea(int index) const;
};

#endif
