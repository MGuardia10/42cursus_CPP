#ifndef CONTACT_HPP
#define CONTACT_HPP

/* INCLUDES */
#include <iostream>
#include <string>

/* CONTACT CLASS */
class	Contact {
	private:
		std::string	name;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkSecret;
		std::string	truncate(std::string str);
	public:
		Contact();
		Contact(std::string	name,
				std::string lastName,
				std::string nickName,
				std::string phoneNumber,
				std::string darkSecret);
		~Contact();

		std::string	getName(bool truncate);
		std::string	getLastName(bool truncate);
		std::string	getNickName(bool truncate);
		std::string	getPhoneNumber(bool truncate);
		std::string	getDarkSecret(bool truncate);
};

#endif