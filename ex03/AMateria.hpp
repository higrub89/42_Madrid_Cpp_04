/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:34:01 by rhiguita          #+#    #+#             */
/*   Updated: 2026/03/06 14:34:02 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class ICharacter;

class AMateria {
protected:
    std::string _type;

public:
    AMateria(void);
    AMateria(std::string const & type);
    AMateria(AMateria const & other);
    AMateria& operator=(AMateria const & other);
    virtual ~AMateria(void);

    std::string const & getType() const; 
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
