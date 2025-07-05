/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-07 15:06:01 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-07 15:06:01 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


//Canonical form________________________________________________________________
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), 
	_energyPoints(10), _attackDamage(0)
{
	std::cout << GREEN << "-ClapTrap- " << this->_name << " created" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), 
	_energyPoints(10), _attackDamage(0)
{
	std::cout << GREEN << "-ClapTrap- " << this->_name << " created" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	*this = src;
	std::cout << GREEN << "-ClapTrap- " << this->_name << " created as a copy of " 
		<< src.getName() << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << GREEN << "-ClapTrap- " << this->_name << " destroyed" << RESET << std::endl;
}


//Getters_______________________________________________________________________
std::string	ClapTrap::getName() const
{
	return (this->_name);
}

int ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}


//Member functions______________________________________________________________
void ClapTrap::attack(const std::string& target) 
{
    if (this->_hitPoints < 1) 
	{
        std::cout << GREEN << "-ClapTrap- " << this->_name << " is dead and can't attack!" << RESET << std::endl;
        return;
    }
    if (this->_energyPoints < 1) 
	{
        std::cout << GREEN << "-ClapTrap- " << this->_name << " is out of energy and can't attack!" << RESET << std::endl;
        return;
    }

    this->_energyPoints -= 1;
    std::cout << GREEN << "-ClapTrap- " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < 1)
	{
		std::cout << GREEN << "-ClapTrap- " << this->_name << " is already dead!" << RESET << std::endl;
		return;
	}
	if (amount >= static_cast<unsigned int>(this->_hitPoints))
	{
		this->_hitPoints = 0;
		std::cout << GREEN << "-ClapTrap- " << this->_name << " took " << amount 
			<< " points of damage and died!" << RESET << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << GREEN << "-ClapTrap- " << this->_name << " took " << amount 
			<< " points of damage!" << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints < 1)
	{
		std::cout << GREEN << "-ClapTrap- " << this->_name << " is dead and can't be repaired!" 
			<< RESET << std::endl;
		return;
	}
	if (this->_energyPoints < 1) 
	{
        std::cout << GREEN << "-ClapTrap- " << this->_name << " is out of energy and can't auto repair!" 
			<< RESET << std::endl;
        return;
    }
	if (this->_hitPoints >= 10)
	{
		std::cout << GREEN << "-ClapTrap- " << this->_name << " is already at full health!" 
			<< RESET << std::endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << GREEN << "-ClapTrap- " << this->_name << " repairs itself by " 
              << amount << " hit points! Current hit points: " 
              << this->_hitPoints << RESET << std::endl;
}