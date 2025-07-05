/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-28 10:37:20 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-28 10:37:20 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

/**
 * Main function demonstrating the functionality of HumanA and HumanB classes with Weapon objects.
 * 
 * In the first block, a Weapon object named 'club' is created with the type "crude spiked club".
 * A HumanA object named 'bob' is initialized with this Weapon, allowing him to attack with it.
 * The attack method is called to show bob's attack, followed by changing the Weapon's type to
 * "some other type of club" and invoking the attack method again to demonstrate the updated weapon type.
 *
 * In the second block, another Weapon object is created, also named 'club', but within a separate 
 * scope to prevent naming conflicts. A HumanB object named 'jim' is created, and the setWeapon method
 * is called to assign the Weapon to jim. The attack method is called twice, showcasing that jim can 
 * attack with the assigned weapon, and again demonstrating the change in weapon type.
 *
 * This structure allows for clear separation of the two different Human objects and their respective
 * Weapon instances, ensuring no interference between their attacks.
 */
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
return 0;
}