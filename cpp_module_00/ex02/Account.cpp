#include "Account.hpp"
#include <stdio>

Account::Account(int initial_deposit)
	: _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
}

void Account::_displayTimestamp()
{
	std::cout << Account::timestamp << " "
			  << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
}

int	Account::getNbAccounts() {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount() {
	return Account::_totalAmount;
}

int	Account::getNbDeposits() {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;
}

