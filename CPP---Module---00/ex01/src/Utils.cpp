/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-21 09:37:28 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-08-21 09:37:28 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.class.hpp"

bool Utils::isDigitsOnly(const std::string &str)
{
	size_t i;

	i = 0;
	while (i < str.size()) 
	{
    	if (!std::isdigit(str[i])) 
		{
        	return false;
    	}
    	++i;
	}
	return (true);
}