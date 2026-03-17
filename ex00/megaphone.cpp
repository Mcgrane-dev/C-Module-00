/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmcgrane <jmcgrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:32:42 by jmcgrane          #+#    #+#             */
/*   Updated: 2026/03/17 15:17:12 by jmcgrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char**av)
{
	int i;
	int j;

	i = 1;
	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			std::cout << (char)toupper(av[i][j]);
			j++;
		}
		if(av[i + 1] != '\0')
			std::cout << " ";
		i++;
	}
	std::cout << "\n";
	return 0;
}