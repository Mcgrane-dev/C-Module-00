/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmcgrane <jmcgrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:38:06 by jmcgrane          #+#    #+#             */
/*   Updated: 2026/03/24 15:39:51 by jmcgrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include "Phonebook.hpp"

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

#endif