#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

/* INCLUDES */
#include "Contact.hpp"

/* PHONEBOOK CLASS */
class	PhoneBook {
	private:
		Contact contacts[8];
		size_t	position;
		size_t	getIndex(void);
	public:
		PhoneBook();
		~PhoneBook();

		void	add(void);
		void	search(void);
};

#endif
