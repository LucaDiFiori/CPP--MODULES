/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-07 15:05:29 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-07 15:05:29 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"  // Include your FragTrap class header

int main() 
{
    // Create a FragTrap object
    FragTrap fragtrap("FRAGGY");
    fragtrap.attack("Target1");
    fragtrap.takeDamage(10);
    fragtrap.beRepaired(5);
    fragtrap.highFivesGuys(); // Using the special high five function
    fragtrap.attack("Target2");

    std::cout << std::endl;

    // Test copying FragTrap
    FragTrap copyFragtrap(fragtrap);

    return 0;
}
