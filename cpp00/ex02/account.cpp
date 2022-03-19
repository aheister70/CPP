/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 19:36:30 by annaheister   #+#    #+#                 */
/*   Updated: 2022/01/24 19:36:30 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// TODO uitzoeken hoe ik timestamp kan krijgen

#include "account.hpp"
#include <string>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts += 1;
	this->_amount = initial_deposit;
	this->_totalAmount = this->_totalAmount + initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
	this->_nbAccounts -= 1;
	return;
}

void Account::_displayTimestamp( void ) {
	std::time_t timer = std::time(0);
	std::tm* local_time = std::localtime(&timer);

	std::cout << "[" << local_time->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << local_time->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << local_time->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << local_time->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << local_time->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << local_time->tm_sec << "] ";
}

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

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount = this->_amount + deposit;
	std::cout << ";amount:" << this->_amount;
	this->_nbDeposits += 1;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_totalNbDeposits++;
	this->_totalAmount = this->_totalAmount + deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (this->_amount - withdrawal > 0) {
		std::cout << ";withdrawal:" << withdrawal;
		this->_amount = this->_amount - withdrawal;
		std::cout << ";amount:" << this->_amount;
		this->_nbWithdrawals += 1;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		this->_totalNbWithdrawals++;
		this->_totalAmount = this->_totalAmount - withdrawal;
		return true;
	}
	else {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
