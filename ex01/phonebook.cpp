/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmcgrane <jmcgrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:04:54 by jmcgrane          #+#    #+#             */
/*   Updated: 2026/03/23 13:41:56 by jmcgrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class Contact {

private:
	int 		index;
	std::string lastName;
	std::string nickName;
	std::string phoneNum;
	std::string firstName;
	std::string darkSecret;

public:
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
	Contact contacts[8];
	int 	index = 0;
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
		if (index > 7)
			index = 0;
	}
	void searchContact() const {
		int i;
		std::string input;
		std::cout << "Enter contact index 1 - 8: ";
		std::getline(std::cin, input);
		i = std::stoi(input);
		Contact c = contacts[i - 1];
		std::cout << "\n" << "|" << c.getIndex() + 1 << "|" << formatColumn(c.getFirstName()) << "|"
		<< formatColumn(c.getLastName()) << "|" << formatColumn(c.getNickName()) << "|" << "\n\n";
	}
};

int main()
{
	int			i = 0;
	bool		isvalid;
	Phonebook	book;
	std::string	cmd;
	std::string	input;

	while(cmd != "EXIT")
	{
		std::cout << "***********************\n";
		std::cout << "* ADD | SEARCH | EXIT *\n";
		std::cout << "***********************\n";
		std::getline(std::cin, cmd);
		if(cmd == "ADD" || cmd == "A")
		{
			Contact c;
			isvalid = true;
			user_prompt(isvalid, input);
			c.setFirstName(input);
			isvalid = true;
			user_prompt(isvalid, input);
			c.setLastName(input);
			isvalid = true;
			user_prompt(isvalid, input);
			c.setNickName(input);
			isvalid = true;
			user_prompt(isvalid, input);
			c.setPhoneNum(input);
			isvalid = true;
			user_prompt(isvalid, input);
			c.setDarkSecret(input);
			c.setIndex(i);
			book.addContact(c);
			// contact_successfull();
			i++;
			if(i > 7)
				i = 0;
		}
		if(cmd == "SEARCH" || cmd == "S")
		{
			book.searchContact();
		}
	}
	std::cout << "BYE!\n";
}
