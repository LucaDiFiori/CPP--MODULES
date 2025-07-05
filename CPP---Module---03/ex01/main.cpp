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

#include "ScavTrap.hpp" // Include your ScavTrap header file

int main() 
{
    // Create a ScavTrap object
    ScavTrap scavtrap("SCAVY");
    scavtrap.attack("Target3");
    scavtrap.takeDamage(5);
    scavtrap.beRepaired(5);
    scavtrap.guardGate();
    scavtrap.attack("Target4");

	std::cout << std::endl;

    // Test copying ScavTrap
    ScavTrap copyScavtrap(scavtrap);

    return 0;
}
