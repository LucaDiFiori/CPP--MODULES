/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-24 07:27:57 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-24 07:27:57 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"


// ************************************************************************** //
//                            Static variables init                           //
// ************************************************************************** //
/* 
* In C++, you initialize a static variable of a class by defining it outside the 
* class after declaring it inside the class. Static variables belong to the class 
* itself, not to any particular instance, so they must be defined in a separate step
*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;




// ************************************************************************** //
//                            Constructor / Destructor                        //
// ************************************************************************** //
/**
 * Constructor: Account
 * ---------------------
 * Initializes a new Account object with a specified initial deposit. The constructor 
 * sets the account amount to the initial deposit, initializes the number of deposits 
 * and withdrawals to zero, and assigns an index to the account based on the current 
 * number of accounts. It also displays the timestamp of the account creation.
 *
 * Parameters:
 *  - initial_deposit: The amount of money to be deposited into the account upon creation.
 *
 * Process:
 *  - Calls the _displayTimestamp() method to output the current timestamp.
 *  - Assigns the current account index to the newly created account based on the static 
 *    variable _nbAccounts, which keeps track of the total number of accounts.
 *  - Outputs a message to the console indicating the account index, the initial amount, 
 *    and that the account has been created.
 *  - Updates the total amount of all accounts by adding the initial deposit to _totalAmount.
 *  - Increments the number of accounts (_nbAccounts) to reflect the creation of a new account.
 *
 * Usage:
 *  - This constructor is called when a new Account object is instantiated with an 
 *    initial deposit. It ensures that each account is properly initialized and tracked.
 *  - Example usage: Account myAccount(100); // Creates an account with an initial deposit of 100.
 */
Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    Account::_displayTimestamp();
    this->_accountIndex = Account::getNbAccounts();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
}

/**
 * Destructor: ~Account
 * --------------------
 * Destroys the Account object and logs the closing of the account by displaying a timestamp
 * and the account's final amount. It also decrements the total number of active accounts.
 *
 * Process:
 *  - Calls the _displayTimestamp() method to output the current timestamp.
 *  - Outputs a message to the console indicating the account index, the final amount 
 *    in the account, and that the account is closed.
 *  - Decrements the static variable _nbAccounts to reflect the closure of the account.
 *
 * Usage:
 *  - This destructor is automatically called when an Account object goes out of scope or 
 *    is explicitly deleted. It ensures that the closing of the account is properly logged 
 *    and that the total account count (_nbAccounts) is updated.
 *  - Example: When the Account object is destroyed (e.g., at the end of the program or 
 *    when manually deleted), the destructor logs the account closure.
 * 
 * Note: this->checkAmount()
 * - The checkAmount() method is called on the current Account object (this) to retrieve
 *   the current amount of money in the account. I need to use this-> to access the
 *   checkAmount() method because it is a non-static. (A non-static method is a member
 *   function that operates on a specific instance of a class, so it requires an object)
 */
Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
	Account::_nbAccounts--;
}




// ************************************************************************** //
//                                  Methods                                   //
// ************************************************************************** //
/**
 * Function: _displayTimestamp
 * ---------------------------
 * Prints the current timestamp in the format [YYYYMMDD_HHMMSS] to the console.
 * The timestamp is generated based on the system's current local time, and is 
 * formatted using the strftime function. This function can be used for logging 
 * events with an accurate timestamp.
 *
 * Process:
 *  1. Retrieves the current system time in seconds since the Unix epoch using time().
 *  2. Converts the current time into a local time structure (struct tm) using localtime().
 *  3. Formats the local time into a string buffer with the pattern [YYYYMMDD_HHMMSS] using strftime().
 *  4. Outputs the formatted timestamp to the console using std::cout.
 * 
 * Time_t and time():
 *  - time_t is a data type  used to represent time as a numerical value,
 *  - time() function returns the current time as a time_t value. When you pass NULL as an argument, 
 *    it indicates that you are not providing a pointer to a time_t variable where 
 *    the time should be stored; instead, you just want the function to return 
 *    the current time.
 * 
 * localtime and struct tm:
 * - The localtime() function converts a time_t value (stored in now) into a local time representation
 * - The & operator is used to pass the address of the now variable (which contains the 
 *   current time as a time_t value) to the function.
 * 
 * - struct tm is a structure defined in the C++ standard library that holds the 
 *   broken-down time representation (year, month, day, hour, minute, second, etc.)
 * - localTime is a pointer to a struct tm object. It will point to a structure that 
 *   contains the local time representation of the time value passed to localtime().
 * 
 * size_t strftime(char *s, size_t maxsize, const char *format, const struct tm *tm):
 * - strftime is a function that formats the date and time stored in a struct tm 
 *   into a string according to a specified format.
 */
void Account::_displayTimestamp( void )
{
	char buffer[20]; // Create a buffer to store the formatted timestamp

	time_t now = time(NULL); // 1.
	struct tm* localTime = localtime(&now); // 2.
	strftime(buffer, 20, "[%Y%m%d_%H%M%S]", localTime); // 3.
	std::cout << buffer; // 4.
}

/**
 * Function: checkAmount
 * ---------------------
 * Returns the current amount in the account.
 */
int Account::checkAmount( void ) const
{
	return (this->_amount);
}

/**
 * Function: makeDeposit
 * ----------------------
 * Processes a deposit transaction for the account and updates account statistics.
 * 
 * This method accepts an integer `deposit` representing the amount to be added to the account's 
 * balance. It first calls the static method `_displayTimestamp()` to log the current timestamp, 
 * then outputs the following information to the console:
 * - The index of the account.
 * - The previous account balance (retrieved using the `checkAmount()` method).
 * - The deposit amount being made.
 * 
 * After updating the account's balance by adding the deposit amount, it again logs the new balance 
 * and increments the number of deposits made to this account. Finally, it updates the static variables 
 * that keep track of the total amount across all accounts and the total number of deposits made.
 *
 * Parameters:
 *  - deposit: The amount of money to be deposited into the account.
 *
 * Log Output Format:
 *  - The log entry follows the format:
 *    [timestamp] index:<account_index>;p_amount:<previous_amount>;deposit:<deposit_amount>;amount:<new_amount>;nb_deposit:<number_of_deposits>
 */
void Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->checkAmount() << ";";
	this->_nbDeposits++;
	std::cout << "nb_deposit:" << this->_nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

/**
 * Function: makeWithdrawal
 * -------------------------
 * Processes a withdrawal transaction for the account and updates account statistics.
 * 
 * This method accepts an integer `withdrawal` representing the amount to be deducted 
 * from the account's balance. It first calls the static method `_displayTimestamp()` to 
 * log the current timestamp, then outputs the following information to the console:
 * - The index of the account.
 * - The previous account balance (retrieved using the `checkAmount()` method).
 * - The requested withdrawal amount.
 * 
 * The method checks if the current balance is sufficient to cover the withdrawal. If the 
 * balance is less than the withdrawal amount, it logs a "refused" message and returns `false`.
 * Otherwise, it proceeds to deduct the withdrawal amount from the account balance, updates the 
 * number of withdrawals made, and logs the new balance and the number of withdrawals.
 *
 * Parameters:
 *  - withdrawal: The amount of money to be withdrawn from the account.
 *
 * Log Output Format:
 *  - The log entry follows the format:
 *    [timestamp] index:<account_index>;p_amount:<previous_amount>;withdrawal:<withdrawal_amount_or_refused>;amount:<new_amount>;nb_withdrawals:<number_of_withdrawals>
 */
bool Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";withdrawal:";
	if (this->checkAmount() < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";

	this->_amount -= withdrawal;
	std::cout << "amount:" << this->checkAmount() << ";";

	this->_nbWithdrawals++;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;


	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	return(true);
}


/**
 * Function: displayStatus
 * ------------------------
 * [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
 * 
 * Outputs the current status of the Account object, including the account index, 
 * current amount, number of deposits, and number of withdrawals. This function 
 * is designed to provide a snapshot of the account's state at a given moment. 
 * It also includes a timestamp of when the status was displayed.
 *
 * Process:
 *  - Calls the _displayTimestamp() method to log the current date and time.
 *  - Outputs the account index to identify the specific account.
 *  - Displays the current amount of money in the account, which is obtained 
 *    by calling the checkAmount() method.
 *  - Displays the total number of deposits made into the account.
 *  - Displays the total number of withdrawals made from the account.
 *  - Formats the output according to the specified log line structure for consistency.
 */
void Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}








// ************************************************************************** //
//                                   Getters                                  //
// ************************************************************************** //
/*
* Note:
* - In this implementation, "return(Account::_nbAccounts)" (for example) is used to explicitly refer to the static variable. 
 *  However, since this method is defined within the class itself, it's also possible to use just 
 *  "return(_nbAccounts)" without the class qualifier (Account::). The reason is that the compiler already knows 
 *  that _nbAccounts is a static member of the Account class and can resolve it without the need 
 *  for the explicit Account:: qualifier.
*/
int Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

/*
* Use for this line of the log: [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
*/
void Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << 	Account::getTotalAmount() << ";";
	std::cout << "deposit:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << ";";
	std::cout << std::endl;
}

