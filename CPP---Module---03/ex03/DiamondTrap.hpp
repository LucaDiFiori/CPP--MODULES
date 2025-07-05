/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-08 10:05:33 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-08 10:05:33 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# ifndef COLORS
#  define GREEN "\033[1;32m"
#  define RED "\033[1;31m"
#  define CYAN "\033[1;36m"
#  define PURPLE "\033[1;35m"
#  define RESET "\033[0m"
# endif

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/* 
 * NOTE :Why is there no need to use 'virtual' in DiamondTrap like this: 
 * class DiamondTrap : virtual public ScavTrap, virtual public FragTrap?
 * -----------------------------------------------------------------------
 * Virtual inheritance must be applied to derived classes that directly inherit 
 * from the common base class to resolve the "diamond problem." 
 * It is not necessary to declare virtual inheritance in the class that inherits 
 * from these derived classes because the virtual inheritance has already been resolved upstream.

 * NOTE: 'using'
 * ------------
 * The using keyword in C++ has several important roles, but when used in the 
 * context of inheritance (as in your example using ScavTrap::attack), 
 * it allows the derived class to bring a specific member function from the base 
 * class into its own scope, explicitly stating that you want to use the base class 
 * version of the function.
 * In your specific example with ScavTrap::attack, the using directive brings 
 * the attack function from the ScavTrap class into the derived DiamondTrap 
 * class scope, without overriding it
 */

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	//Constructors, Destructor and assignment operator
	public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& serc);
	DiamondTrap& operator=(const DiamondTrap& src);
	~DiamondTrap();

	//Member functions
	void whoAmI(void);

	using ScavTrap::attack;
};

#endif