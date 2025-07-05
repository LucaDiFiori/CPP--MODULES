/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-08 07:18:10 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-08 07:18:10 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*
 * The ScavTrap class is derived from ClapTrap, and it inherits all the 
 * attributes such as _name, _hitPoints, _energyPoints, and _attackDamage 
 * from the base class ClapTrap. These attributes are not redefined here 
 * because they are already declared and managed by ClapTrap.
 *
 * The attack() method is overridden in ScavTrap to provide specific behavior
 * for ScavTrap objects, while still making use of the inherited attributes 
 * like _attackDamage. By overriding the function, ScavTrap can have its own 
 * attack logic or output different messages compared to the ClapTrap class.
 *
 * The guardGate() method is unique to ScavTrap and adds an additional 
 * functionality exclusive to this derived class, which is not part of the 
 * ClapTrap functionality. It introduces the concept of "Gate keeper mode" 
 * as a special behavior for ScavTrap.
 *
 * Constructors and destructors are explicitly defined in ScavTrap to ensure 
 * that proper constructor/destructor chaining occurs, starting with ClapTrap 
 * and then ScavTrap during construction, and in reverse order during 
 * destruction. The copy constructor and assignment operator are also 
 * defined to ensure proper copying and assignment of ScavTrap objects.
 */
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		ScavTrap& operator=(const ScavTrap& src);
		~ScavTrap();

		void attack(const std::string& target);
		void guardGate();
};


#endif