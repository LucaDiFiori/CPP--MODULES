/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-08 08:52:27 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-08 08:52:27 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//Constructors__________________________________________________________________
FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << PURPLE << "-FragTrap- " << this->_name << " created." 
		<< RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << PURPLE << "-FragTrap- " << this->_name << " created." << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) 
{
	std::cout << PURPLE << "-FragTrap- " << this->_name << " created as a copy of " 
		<< src.getName() << RESET << std::endl;
}

//assignment operator___________________________________________________________
FragTrap& FragTrap::operator=(const FragTrap& src)
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();

	return(*this);
}

//destructor____________________________________________________________________
FragTrap::~FragTrap()
{
	std::cout << PURPLE << "-FragTrap- " << this->_name << " destroyed." << RESET << std::endl;	
}


//method________________________________________________________________________
void FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints <= 0)
		std::cout << PURPLE << "-FragTrap- " << this->_name << " is dead, can't high five" << RESET << std::endl;
	else
		std::cout << PURPLE << "-FragTrap- " << this->_name <<  ": ''HIGH FIVE!''" << RESET << std::endl;
}