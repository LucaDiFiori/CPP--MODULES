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


#include "DiamondTrap.hpp"

int main() {
    // Create a DiamondTrap object named "Diamond"
    std::cout << std::endl << "=== Creation ===" << std::endl;
    DiamondTrap diamond("Diamond");

    std::cout << std::endl;

    // Display the initial state of the DiamondTrap
    std::cout << std::endl << "=== test WhoAmI ===" << std::endl;
    diamond.whoAmI();  // Should print both its name and its ClapTrap name

    // Test the inherited functions from FragTrap and ScavTrap
    std::cout << std::endl << "=== Test Attack ===" << std::endl;
    diamond.attack("target");  // Test attack function from ScavTrap

    // Display hit points, energy points, and attack damage
    std::cout << std::endl << "=== DiamondTrap parameters ===" << std::endl;
    std::cout << "Hit Points: " << diamond.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << diamond.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << diamond.getAttackDamage() << std::endl;

    std::cout << std::endl << "=== Special abilities ===" << std::endl;
    diamond.highFivesGuys();  // Call FragTrap's special ability
    diamond.guardGate();       // Call ScavTrap's special ability

    std::cout << std::endl << "=== Copy constructor call ===" << std::endl;
    DiamondTrap diamondCopy(diamond);  // Create a copy of the DiamondTrap
    diamondCopy.whoAmI();  // Ensure the copy has the correct names

    // Display hit points, energy points, and attack damage of the copy
    std::cout << std::endl << "===Copied DiamondTrap parameters:===" << std::endl;
    std::cout << "Hit Points: " << diamondCopy.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << diamondCopy.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << diamondCopy.getAttackDamage() << std::endl;

    std::cout << std::endl << "=== Destruction ===" << std::endl;

    return 0;
}