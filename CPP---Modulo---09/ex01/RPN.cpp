#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::isSingleDigit(const std::string &str)
{

    if ((str[0] >= '0' && str[0] <= '9') && !str.empty() && !(str.length() > 1))
        return true;
    return false;
}

bool RPN::isValidOperator(const std::string &str)
{
    if (str == "+" || str == "-" || str == "*" || str == "/")
        return true;
    return false;
}

void RPN::performOperation(const std::string &op) {
    if (numbers.size() < 2) {
        throw std::runtime_error("Error: insufficient operands");
    }

    int b = numbers.top();
    numbers.pop();
    int a = numbers.top();
    numbers.pop();

    if (op == "+")
        numbers.push(a + b);
    else if (op == "-")
        numbers.push(a - b);
    else if (op == "*")
        numbers.push(a * b);
    else if (op == "/") {
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        numbers.push(a / b);
    }
}

void RPN::evaluateExpression(const std::string &expression) {
    std::istringstream iss(expression);
    std::string str;

    while (iss >> str)
    {
        if (isSingleDigit(str))
            numbers.push(str[0] - '0');
        else if (isValidOperator(str))
            performOperation(str);
        else
            throw std::runtime_error("Error: invalid str");
    }

    if (numbers.size() != 1)
        throw std::runtime_error("Error: invalid expression");

    std::cout << numbers.top() << std::endl;
}
