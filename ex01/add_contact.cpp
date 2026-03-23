/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmcgrane <jmcgrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:00:42 by jmcgrane          #+#    #+#             */
/*   Updated: 2026/03/23 16:07:33 by jmcgrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void contact_successfull()
{
	int	i = 0;
	std::string msg = "\n--- CONTACT SUCCESSFULLY ADDED! ---\n\n";

	while(msg[i])
	{
		std::cout << msg[i] << std::flush;
		i++;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void user_prompt(bool isvalid, std::string &input)
{
	size_t i = 0;
	static size_t j = 0;
	std::string prompts[] = {
		"Enter First Name ------: ",
		"Enter Last Name -------: ",
		"Enter Nickname --------: ",
		"Enter Phone number ----: ",
		"Enter Darkest Secret --: "
	};
	while(isvalid == true)
	{
		std::cout << prompts[j];
		std::getline(std::cin, input);
		if(input.length() == 0)
		{
			std::cout << "No empty fields!\n";
			continue;
		}
		for(i = 0; input[i]; i++)
		{
			if(j == 3)
			{
				if(!isdigit(input[i]) || input.length() > 15)
				{
					std::cout << "Invalid!\n";
					break;
				}
			}
			else if(j == 4)
			{
				if(!isalpha(input[i]) && !' ')
				{
					std::cout << "Invalid Character Found!\n";
					break;	
				}
			}
			else if(!isalpha(input[i]))
			{
				std::cout << "Invalid Character Found!\n";
				break;
			}
		}
		if(i == input.length())
		{
			isvalid = false;
			j++;
		}
	}
	if (j == 5)
		j = 0;
}