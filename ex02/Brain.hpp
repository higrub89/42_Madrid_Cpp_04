/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:11:24 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/23 22:11:25 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    std::string ideas[100];

public:
    Brain(void);
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain(void);

    // --- NUEVA INTERFAZ EXIGIDA ---
    void setIdea(int index, std::string const & idea);
    std::string const & getIdea(int index) const;
};

#endif
