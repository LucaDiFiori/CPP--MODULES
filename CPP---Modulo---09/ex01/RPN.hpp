#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>

class RPN
{
	private:
		std::stack<int> numbers;

		bool isSingleDigit(const std::string &str);
		bool isValidOperator(const std::string &str);
		void performOperation(const std::string &op);

	public:
		RPN();
		~RPN();

		void evaluateExpression(const std::string &expression);
};

#endif
