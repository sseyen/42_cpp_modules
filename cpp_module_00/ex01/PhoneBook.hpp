#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
	Contact	_contacts[8];
	int		_contactCount;
	int		_index;
public:
	PhoneBook();
	~PhoneBook();

	Contact		getContact(int index) const;
	int			getContactCount() const;
	void		addContact(Contact& contact);
	void		displayContacts() const;
};

#endif // PHONEBOOK_HPP