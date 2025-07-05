/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-08 10:05:47 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-08 10:05:47 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//Constructors, Destructor and assignment operator

/* NOTE: ScavTrap::_hitPoints
* --------------------------
* Since both ScavTrap and FragTrap inherit from ClapTrap, 
* both classes could have access to the same members like _hitPoints, _energyPoints, and _attackDamage.
* To resolve this ambiguity, you can explicitly specify from which derived class (ScavTrap or FragTrap) 
* you want to access the attributes.
* In this case, using ScavTrap::_hitPoints tells the compiler that you want to access the version of _hitPoints 
* that was set by ScavTrap, which inherits from ClapTrap.
*/
DiamondTrap::DiamondTrap() : ClapTrap("Default _clap_name"), ScavTrap(), FragTrap()
{
	this->_name = "Default";
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;

	std::cout << RED << "-DiamondTrap- " << this->_name << " created" 
		<< RESET << std::endl;
}


DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), 
	ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;

	std::cout << RED << "-DiamondTrap- " << this->_name << " created" 
		<< RESET << std::endl;
}

/* DiamondTrap Copy Constructor
* ----------------------------
* This constructor creates a new DiamondTrap object as a copy of an existing DiamondTrap object (src).
* It calls the copy constructors of its base classes (ClapTrap, ScavTrap, and FragTrap)
* to initialize the new object with the same state as the source object (src).
*
* Inside the constructor:
* - The base class constructors are called with the source object (src), which is of type DiamondTrap.
*   Each base class constructor will copy its own attributes from the DiamondTrap object.
*   This ensures that the base class portions of the new object are properly initialized with the values 
*   from the source object.
* 
* After the base classes are initialized, a message is printed to the console
* indicating that the DiamondTrap object has been created as a copy of the source object.
* The message includes the name of the original object using the getName() method,
* formatted with a color for clarity.
*
* NOTE: Explicit Initialization of _name (DiamondTrap::DiamondTrap(const DiamondTrap& src) : ...  _name(src.getName()))
* --------------------------------
* The _name attribute is specific to the DiamondTrap class and is not managed by the copy constructors 
* of the base classes (ClapTrap, ScavTrap, and FragTrap). Therefore, it must be explicitly initialized 
* in the DiamondTrap copy constructor to ensure that the new DiamondTrap object has the correct name 
* copied from the source object (src).
*/
DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), 
	ScavTrap(src), FragTrap(src), _name(src._name)
{
	std::cout << RED << "-DiamondTrap- " << this->_name << " created as a copy of " 
		<< RESET << src.getName() << std::endl;
	
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();

	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "-DiamondTrap- " << this->_name << " destroyed." 
		<< RESET << std::endl;
}


//Member functions
void DiamondTrap::whoAmI(void)
{
	std::cout << RED << "I am " << this->_name << " and my ClapTrap name is " 
		<< ClapTrap::getName() << RESET << std::endl;
}