/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmcgrane <jmcgrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:26:41 by jmcgrane          #+#    #+#             */
/*   Updated: 2026/03/24 12:26:48 by jmcgrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <thread>
#include <chrono>
#include <iostream>

class Contact {

private:
	int 		index;
	std::string lastName;
	std::string nickName;
	std::string phoneNum;
	std::string firstName;
	std::string darkSecret;

public:
    Contact() : index(0), lastName("EMPTY"), nickName("EMPTY"), phoneNum(""), firstName("EMPTY"), darkSecret("") {}
	
	void setFirstName(std::string f) {
		firstName = f;
	}
	std::string getFirstName() const {
		return firstName;
	}
	void setLastName(std::string l) {
		lastName = l;
	}
	std::string getLastName() const {
		return lastName;
	}
	void setPhoneNum(std::string p) {
		phoneNum = p;
	}
	std::string getPhoneNum() const {
		return phoneNum;
	}
	void setNickName(std::string n) {
		nickName = n;
	}
	std::string getNickName() const {
		return nickName;
	}
	void setDarkSecret(std::string d) {
		darkSecret = d;
	}
	std::string getDarkSecret() const {
		return darkSecret;
	}
	void setIndex(int i){
		index = i;
	}
	int getIndex() const {
		return index;
	}
};

class Phonebook {

private:
	Contact contacts[9];
	int 	index = 1;
	std::string formatColumn(std::string str) const {
		if(str.length() > 10)
			return str.substr(0, 9) + ".";
		else
		{
			int spacesNeeded = 10 - str.length();
			std::string spaces(spacesNeeded, ' ');
			return spaces + str;
		}
	}

public:
	void addContact(Contact c) {
		contacts[index] = c;
		index++;
		if (index > 8)
			index = 1;
	}
	void displayContact() const {
		
		int i = 1;
		std::string spaces(9, ' ');

		while(i < 9)
		{
			Contact c = contacts[i];
			std::cout << "\n" << "|" << spaces << c.getIndex() << "|" << formatColumn(c.getFirstName()) << "|"
			<< formatColumn(c.getLastName()) << "|" << formatColumn(c.getNickName()) << "|" << "\n";
			i++;
		}

		// std::string input;
		// while(!(i >= 1 && i <= 8))
		// {
		// 	std::cout << "Enter contact index 1 - 8: ";
		// 	std::getline(std::cin, input);
		// 	if(input.length() > 1 ||!(input >= "1" && input <= "8"))
		// 	{
		// 		std::cout << "Invalid index!\n";
		// 		continue;
		// 	}
		// 	i = std::stoi(input);
		// }
	}
};

void contact_successfull();
void user_prompt(bool isvalid, std::string &input);
