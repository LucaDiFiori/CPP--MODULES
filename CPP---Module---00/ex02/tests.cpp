// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	/*The line typedef std::vector<Account::t> accounts_t; creates a type alias (accounts_t) 
	* for a std::vector of Account::t objects
	*
	* std::vector<Account::t>:
	* - std::vector is a standard C++ container that represents a dynamic array
	* - Account::t refers to the alias t that was defined in the Account class.
	*   (std::vector<Account::t> is the same as std::vector<Account>, 
	* which means a vector (dynamic array) of Account objects.)
	*/
	typedef std::vector<Account::t>							  accounts_t;

	/*create a type alias (ints_t) for a std::vector of int objects.
	*/
	typedef std::vector<int>								  ints_t;

	/* Define a type alias 'acc_int_t' as a pair of iterators: 
	* - The first element is an iterator for the 'accounts_t' container.
    * - The second element is an iterator for the 'ints_t' container.
    * This can be used to represent a relationship or mapping between two different collections.
	* */
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;





	/* Create an array of integers representing the initial amounts for the accounts.
	*/
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };

	/* Calculate the size of the 'amounts' array using the sizeof operator and 
	*  divide it by the size of an integer to get the number of elements in the array.
	*
	*  Note: The syntax amount_size( sizeof(amounts) / sizeof(int) ) is called 
	*        direct initialization
	*        and is used to initialize the variable amount_size with the result 
	*        of the division.
	*		 I've could have used the following syntax (copy initialization): 
	*        size_t const amounts_size = sizeof(amounts) / sizeof(int);
	*/
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );

	/*
	* This line creates a std::vector of Account objects named accounts, 
	* and it's initialized using a range defined by two pointers/iterators: 
	* amounts and amounts + amounts_size.
	*
	* Range constructor:
	* The constructor accounts(amounts, amounts + amounts_size) uses the range 
	* constructor of std::vector. This means that for each value in the range 
	* [amounts, amounts + amounts_size), a new Account object is created, 
	* where:
	*    - The starting point is amounts, which points to the first element of the array (42).
	*    - The end point is amounts + amounts_size, which points just past the last element of the array (16576).
	*
	* What's Happening in Detail:
	* - Vector Creation: The std::vector<Account> is being initialized with the range 
	*                    [amounts, amounts + amounts_size), so each element in amounts[] 
	*                    is passed as an argument to the Account constructor.
	* - Account Object Construction: For each integer value in amounts[], the Account 
	*                                constructor is called. For example, the first call 
	*                                would be: Account(42). 
	*                                This means a new Account object is created with an initial 
	*                                deposit of 42. The constructor:
	* - Since the amounts[] array contains 8 elements, 8 Account objects are created, 
	*   each initialized with the corresponding value from the amounts[] array
	*/
	accounts_t				accounts( amounts, amounts + amounts_size );

	/* Create iterators to the beginning and end of the 'accounts' vector.
	*  - accounts.begin(): This method returns an iterator that points to the 
	*    				   first element in the accounts vector.
	*  - accounts.end(): This method returns an iterator that points one past the 
	*                    last element of the vector. It doesn't point to a valid 
	*                    element but serves as a marker for the end of the vector 
	*                    when iterating through it.
	*
	*  - acc_begin is an iterator pointing to the first element in the accounts vector.
	*  - acc_end is an iterator that points just past the last element in the accounts vector. 
	*    It acts as a sentinel to indicate the end of the vector when iterating.
	*/
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();


	/* Create an array of integers representing the deposit amounts for the accounts.*/
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };

	/* Calculate the size of the 'd' array*/
	size_t const		d_size( sizeof(d) / sizeof(int) );

	/* Create a vector of integers named deposits, initialized with the range [d, d + d_size)*/
	ints_t				deposits( d, d + d_size );
	
	/* Create iterators to the beginning and end of the 'deposits' vector.*/
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();


	/*Do the same for the withdrawals*/
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();


	/*Display the initial status of the accounts*/
	Account::displayAccountsInfos();

	/* Use std::for_each to iterate over a range defined by acc_begin and acc_end,
    *  calling the member function displayStatus() on each Account object in the range.
    *  std::mem_fun_ref wraps the member function pointer to allow it to be used as a 
    *  callable object in the for_each algorithm, resulting in each Account's status being displayed.*/
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// Initialize an iterator 'it' as a pair of iterators: 
	// - 'it.first' points to the current Account in the 'accounts_t' collection (starting at acc_begin).
	// - 'it.second' points to the current withdrawal amount in the second collection (starting at wit_begin).
	for ( acc_int_t it( acc_begin, wit_begin );
    	  // Continue the loop while both iterators have not reached their respective ends:
    	  it.first != acc_end && it.second != wit_end;
    	  // Increment both iterators to process the next Account and withdrawal amount:
    	  ++(it.first), ++(it.second) ) {
      
    	// Call the 'makeWithdrawal' method on the current Account object pointed to by 'it.first',
    	// passing the corresponding withdrawal amount pointed to by 'it.second'.
		// This line dereferences it.first to get the current Account object (iterator is a pointer) and calls the makeWithdrawal method on it.
		// It also dereferences it.second to get the current withdrawal amount.
		// Essentially, for each Account in the first collection, the corresponding withdrawal 
		// amount from the second collection is passed to the makeWithdrawal method.
    	(*(it.first)).makeWithdrawal(*(it.second));
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
