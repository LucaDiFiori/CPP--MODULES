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

#include "ClapTrap.hpp"

int main() {
    // Create two ClapTrap objects
    ClapTrap clap1("ClapOne");
    ClapTrap clap2("ClapTwo");

    // Test attack
    std::cout << std::endl << "=== Test Attack ===" << std::endl;
    clap1.attack("ClapTwo");  // ClapOne attacks ClapTwo
    clap2.takeDamage(clap1.getAttackDamage());  // ClapTwo takes damage from ClapOne

    // Test repair
    std::cout << std::endl << "=== Test Repair ===" << std::endl;
    clap2.beRepaired(5);  // ClapTwo repairs itself by 5 hit points

    // Test energy consumption
    std::cout << std::endl << "=== Test Energy Consumption ===" << std::endl;
    for (int i = 0; i < 11; i++) 
	{  // ClapOne attacks until it runs out of energy
        clap1.attack("ClapTwo");
    }

    // Test repair with no energy
    std::cout << std::endl << "=== Test Repair with No Energy ===" << std::endl;
    clap1.beRepaired(3);  // ClapOne tries to repair itself without energy

    // Test destruction
    std::cout << std::endl << "=== Test Destruction ===" << std::endl;
    clap1.takeDamage(20);  // ClapOne takes enough damage to be destroyed
    clap1.attack("ClapTwo");  // ClapOne tries to attack after being destroyed
    clap1.beRepaired(10);  // ClapOne tries to repair itself after being destroyed

    return 0;
}
