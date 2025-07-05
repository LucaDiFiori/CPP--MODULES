/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-08 08:52:09 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-08 08:52:09 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/*
 * The FragTrap class is derived from ClapTrap, and it inherits all the 
 * attributes such as _name, _hitPoints, _energyPoints, and _attackDamage 
 * from the base class ClapTrap. These attributes are not redefined here 
 * because they are already declared and managed by ClapTrap.
 *
 * The highFivesGuys() method is unique to FragTrap and adds an additional 
 * functionality exclusive to this derived class, which is not part of the 
 * ClapTrap functionality. It introduces the concept of "High fives" as a 
 * special behavior for FragTrap.
 *
 * Constructors and destructors are explicitly defined in FragTrap to ensure 
 * that proper constructor/destructor chaining occurs, starting with ClapTrap 
 * and then FragTrap during construction, and in reverse order during 
 * destruction. The copy constructor and assignment operator are also 
 * defined to ensure proper copying and assignment of FragTrap objects.
 */
class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& src);
		FragTrap& operator=(const FragTrap& src);
		~FragTrap();

		void highFivesGuys(void);
};

#endif