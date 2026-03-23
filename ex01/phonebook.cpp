/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmcgrane <jmcgrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:04:54 by jmcgrane          #+#    #+#             */
/*   Updated: 2026/03/23 12:31:31 by jmcgrane         ###   ########.fr       */
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
		std::cout << "Enter contact index 0 - 7: ";
		std::getline(std::cin, input);
		i = std::stoi(input);
		Contact c = contacts[i];
		std::cout << "FIRST NAME: " << c.getFirstName() << "  LAST NAME: "
		<< c.getLastName() << "   NICKNAME: " << c.getNickName() << "\n";
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
		if(cmd == "ADD")
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
		if(cmd == "SEARCH")
		{
			book.searchContact();
		}
	}
	std::cout << "BYE!\n";
}
