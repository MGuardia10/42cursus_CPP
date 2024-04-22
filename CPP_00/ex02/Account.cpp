#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

std::string	format(int num) {

	std::string str;
	
	str = std::to_string(num);
	if (str.length() == 1)
		str.insert(0, 1, '0');
	return str;
}

/* Constructors */
Account::Account(int initial_deposit) {

	_displayTimestamp();

	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;

	_nbAccounts += 1;
	_totalAmount += this->_amount;
}

/* Destructor */
Account::~Account() {

	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

/* Private */
void	Account::_displayTimestamp( void ) {
    time_t now = time(NULL);
	struct tm *localTime = localtime(&now);

	int year = localTime->tm_year + 1900;
	int month = localTime->tm_mon + 1;
	int day = localTime->tm_mday;
	int hour = localTime->tm_hour;
	int minutes = localTime->tm_min;
	int seconds = localTime->tm_sec;

	std::cout << "[" << year << format(month) << format(day);
	std::cout << "_";
	std::cout <<  format(hour) << format(minutes) << format(seconds) << "] ";
}

/* Public */
int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
	
	_displayTimestamp();

	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;;
	
}

void	Account::makeDeposit( int deposit ) {

	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;

	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	this->_amount += deposit;
	_totalAmount += deposit;

	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal ) {

	bool successTransaction = this->checkAmount() >= withdrawal;

	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (!successTransaction) {
		std::cout << ";withdrawal:refused" << std::endl;
		return (successTransaction);
	}

	Account::_totalNbWithdrawals += 1;
	this->_nbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	this->_amount -= withdrawal;

	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	return (successTransaction);
}

int	Account::checkAmount() const {
	return this->_amount;
}

void Account::displayStatus( void ) const {
	
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;

}
