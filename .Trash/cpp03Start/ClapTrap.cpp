/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:17:39 by eperperi          #+#    #+#             */
/*   Updated: 2024/11/19 17:59:30 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap& original)
{
	*this = original;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& original)
{
	if (this != &original)
	{
		this->_name = original._name;
		this->_attackDamage = original._attackDamage;
		this->_energyPoints = original._energyPoints;
		this->_hitPoints = original._hitPoints;
	}
	return *this;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
		this->_energyPoints--;
	else if (this->_hitPoints == 0)
		std::cout << "cannot attack because there are not enough hit points!" << std::endl;
}
