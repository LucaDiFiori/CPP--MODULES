# CPP---Module---05
This module is designed to help you understand Try/Catch and Exceptions in CPP.

***
# Sources
- https://cplusplus.com/doc/tutorial/exceptions/
- https://cplusplus.com/doc/tutorial/exceptions/

***
# Table of contents
- [NESTED CLASSES](#nested-classes)
    - [Definition of Nested Classes](#definition-of-nested-classes)
    - [Why Use Nested Classes?](#why-use-nested-classes)
    - [Example of a Nested Class](#example-of-a-nested-class)
    - [Key Points to Remember](#key-points-to-remember)
    - [Use Cases of Nested Classes](#use-cases-of-nested-classes)
    - [Accessing Members of the Enclosing Class](#Accessing-Members-of-the-Enclosing-Class)
    - [Friend Declarations](#friend-declarations)
    - [Static Nested Classes](#static-nested-classes)
    - [Protected and Private Nested Classes](#protected-and-private-nested-classes)
    - [Inheritance and Nested Classes](#inheritance-and-nested-classes)
- [EXCEPTIONS AND TRY/CATCH STATEMENTS](#exceptions-and-trycatch-statements)
    - [Basic Structure of Exception Handling in C++](#basic-structure-of-exception-handling-in-c)
    - [Syntax](#syntax)
    - [Examples](#examples)
    - [How Exception Handling Works](#how-exception-handling-works)
    - [Types of Exceptions](#types-of-exceptions)
    - [Throwing Standard Exception](#throwing-standard-exceptions)
    - [Catching All Exceptions](#catching-all-exceptions)
    - [Rethrowing Exceptions](#Rethrowing-Exceptions)
    - [Custom Exception Classes](#custom-exception-classes)
    - [exception specification](#exception-specification)
    - [Stack Unwinding](#stack-unwinding)
    - [Exception Handling Best Practices](#exception-handling-best-practices)

***

# C++ BASICS 05

***

# NESTED CLASSES
## Definition of Nested Classes
- A **nested class** is a **class defined within another class**. 
- The nested class behaves similarly to any other class, but **its scope is limited to the enclosing class**. 
- The enclosing class can access private members of the nested class, but the nested class doesn't have access to the enclosing class's private members by default (unless specific access is granted).

## Why Use Nested Classes?
Nested classes can be useful in **situations where a class is conceptually part of another class but doesn't need to be visible outside** of it. Some common reasons to use nested classes:
- **Encapsulation**: Keep related classes together without exposing internal implementation details.
- **Organizational purposes**: It makes sense to group certain classes together logically.
- **Hierarchical representation**: Sometimes, one class is tightly coupled with another class, and it's only useful within that context.

## Example of a Nested Class
**Outer.hpp**
```C++
#ifndef OUTER_HPP
#define OUTER_HPP

#include <iostream>

class Outer {
private:
    int outerData;

public:
    // Constructor for Outer class
    Outer(int outerValue);

    // A method of Outer class
    void showOuterData();

    // Nested class inside Outer class
    class Inner {
    private:
        int innerData;

    public:
        // Constructor for Inner class
        Inner(int innerValue);

        // A method of Inner class
        void showInnerData();
    };
};

#endif // OUTER_HPP
```

**Outer.cpp**
```C++
#include "Outer.hpp"

// Definition of Outer class constructor
Outer::Outer(int outerValue) : outerData(outerValue) {}

// Definition of Outer class method
void Outer::showOuterData() {
    std::cout << "Outer data: " << outerData << std::endl;
}

/***************************************************************/

// Definition of Inner class constructor
Outer::Inner::Inner(int innerValue) : innerData(innerValue) {}

// Definition of Inner class method
void Outer::Inner::showInnerData() {
    std::cout << "Inner data: " << innerData << std::endl;
}
```

**main.cpp**
```C++
#include "Outer.hpp"

int main() {
    // Creating an object of Outer class
    Outer outerObj(100);
    outerObj.showOuterData();

    // Creating an object of the nested Inner class
    Outer::Inner innerObj(50);
    innerObj.showInnerData();

    return 0;
}
```

### Explanation of the Example
**Outer Class**
- The Outer class has a private member outerData and a public method showOuterData() to print its value.
- The constructor Outer(int value) initializes the outerData.

**Inner Class**
- The Inner class is defined within the scope of the Outer class. It also has a private member innerData and a public method showInnerData() to print its value.
- The constructor Inner(int value) initializes the innerData.
- The Inner class is publicly accessible but only within the context of the Outer class. Outside the Outer class, you can refer to it using Outer::Inner.

**Main**
- An instance of Outer, outerObj, is created with the value 100, and its method showOuterData() is called.
- An instance of the nested Inner class, innerObj, is created using Outer::Inner with the value 50, and its method showInnerData() is called.

## Key Points to Remember
- The nested class is defined inside another class, but you still create objects of the nested class in the usual way, except that you qualify it with the enclosing class's name (e.g., Outer::Inner).
- The nested class doesn't have automatic access to the enclosing class's members. You would need to pass the outer class’s member to the inner class if needed.


## Use Cases of Nested Classes
- **Helper Classes**: When you need a class that is used solely by the enclosing class, like a utility or helpe
- **Encapsulation**: Hiding implementation details within the outer class, keeping internal workings private.

## Accessing Members of the Enclosing Class
By default, a nested class doesn't have access to the members (including private and protected) of its enclosing class. However, the enclosing class can access all members of the nested class, even the private ones. If you want the nested class to access the members of the enclosing class, you need to explicitly pass them or use friend declarations.

**Example of Passing the Enclosing Class Members**
```C++
#include <iostream>

class Outer {
private:
    int outerData;

public:
    Outer(int value) : outerData(value) {}

    // A method to return the outerData for the inner class
    int getOuterData() {
        return outerData;
    }

    class Inner {
    public:
        // Method that uses outer class data by accepting a reference
        void showOuterData(Outer &outer) {
            std::cout << "Accessing outer data from Inner: " << outer.getOuterData() << std::endl;
        }
    };
};

int main() {
    Outer outerObj(100);
    Outer::Inner innerObj;

    // Passing outer object to Inner's method
    innerObj.showOuterData(outerObj);

    return 0;
}
```
In this example, the nested class Inner doesn't have direct access to the private members of the enclosing class Outer, but it can access them by passing an Outer object and using a getter method (getOuterData()).

## Friend Declarations
You can use the friend declaration to allow the nested class to access the private or protected members of the enclosing class.

**Example using Friend Declarations**
```C++
#include <iostream>

class Outer {
private:
    int outerData;

public:
    Outer(int value) : outerData(value) {}

    // Making the Inner class a friend of Outer
    friend class Inner;

    class Inner {
    public:
        // Now Inner has direct access to outerData
        void showOuterData(Outer &outer) {
            std::cout << "Outer data accessed by Inner: " << outer.outerData << std::endl;
        }
    };
};

int main() {
    Outer outerObj(100);
    Outer::Inner innerObj;

    innerObj.showOuterData(outerObj);

    return 0;
}
```
In this case, Inner is declared as a friend of Outer, which means it can directly access Outer's private members, like outerData

## Static Nested Classes
A nested class can also be declared static. This means the nested class doesn't need an instance of the enclosing class to be instantiated, and it cannot access non-static members of the enclosing class.

**Example of a Static Nested Class**
```C++
#include <iostream>

class Outer {
public:
    // Static nested class
    class Inner {
    public:
        void showMessage() {
            std::cout << "This is a static nested class!" << std::endl;
        }
    };
};

int main() {
    // We can create an object of Inner class without an instance of Outer
    Outer::Inner innerObj;
    innerObj.showMessage();

    return 0;
}
```
Here, Inner is a static nested class, meaning it's independent of Outer. You don't need an instance of Outer to create an instance of Inner.

## Protected and Private Nested Classes
Just like regular members of a class, nested classes can be declared private or protected. When declared as such, their access is restricted to the scope of the outer class (or derived classes, in the case of protected).

**Example of Private Nested Class**
```C++
#include <iostream>

class Outer {
private:
    // Private nested class
    class Inner {
    public:
        void showMessage() {
            std::cout << "This is a private nested class!" << std::endl;
        }
    };

public:
    // Outer class method that uses the private nested class
    void accessInner() {
        Inner innerObj;
        innerObj.showMessage();
    }
};



int main() {
    Outer outerObj;
    outerObj.accessInner();

    // The following line will cause an error because Inner is private
    // Outer::Inner innerObj; // Not allowed

    return 0;
}
```
In this example, the Inner class is private, so it can only be accessed within the Outer class. You cannot create an instance of Inner from outside Outer.

## Inheritance and Nested Classes
A nested class can also be involved in inheritance hierarchies. You can inherit nested classes and extend their functionality, just as you would with regular classes.
```C++
#include <iostream>

class Outer 
{
    public:
        class Inner 
        {
            public:
                void showMessage() {
                    std::cout << "Message from Inner class!" << std::endl;
                }
        };
};

// Derived class that inherits the Inner class from Outer
class DerivedInner : public Outer::Inner 
{
    public:
        void showDerivedMessage() {
            std::cout << "Message from DerivedInner class!" << std::endl;
        }
};

int main() {
    DerivedInner derivedObj;
    derivedObj.showMessage();       // Calls Inner class method
    derivedObj.showDerivedMessage(); // Calls DerivedInner class method

    return 0;
}
```
Here, DerivedInner inherits from the nested Inner class of Outer, allowing you 
to extend the functionality of the nested class through inheritance.

***
***

# EXCEPTIONS AND TRY/CATCH STATEMENTS
Exceptions in C++ are a mechanism that allows you to handle errors or unexpected 
conditions that occur during the execution of a program. Instead of relying on error 
codes or return values, exceptions provide a structured way to handle these errors, 
making the code cleaner and easier to maintain.

## Basic Structure of Exception Handling in C++
C++ uses three primary keywords for exception handling:
- **throw**: 
    * When an error occurs, you can "throw" an exception to signal that something went wrong. This is done using the throw keyword.
    * This keyword is used to signal that an exception has occurred.
    * The throw keyword implies that the exception will be **propagated** (typically to a catch block), and the execution of the program may continue if the exception is handled properly.
- **try**: 
    * When an exception is thrown, you can "catch" it and handle it using a try-catch block. The try block contains the code that may throw an exception, and the catch block contains the code that handles the exception.
    * This block contains the code that might throw an exception.
- **catch**: 
    * This block catches and handles the exception.

You can throw exceptions of any type, but it's common to throw objects of standard 
types like std::exception or derived classes, such as std::runtime_error.

## Syntax
1. **Throwing an Exception**: 
    ```C++
    throw exceptionObject;
    ```
2. **Try-Catch Block**:
    ```C++
    try {
        // Code that might throw an exception
    } catch (exceptionType& ex) {
        // Code to handle the exception
    }
    ```
3. **general use case_1**
    ```C++
    #include <stdexcept>

    void test1()
    {
        try
        {
            //Do some stuff here
            if (/*there's an error*/)
            {
                throw std::exception();
            }
            else
            {
                //Do some more stuff
            }
        }
        catch (std::exception e)
        {
            //Handle the error (e.g. deallocation if needed etc.)
        }
    }
    ```

4. **general use case_2**
    ```C++
    #include <stdexcept>

    void test2()
    {
        //Do some stuff here
        if (/*there's an error*/)
        {
            throw std::exception();
        }
        else
        {
            //Do some more stuff
        }
    }

    void test3()
    {
        try
        {
            test2();
        }
        catch (std::exception& e)
        {
            //Handle error
        }
    }
    ```
Note: I use a reference to exception (exception& e). In practice, you can think of the catch block as a function that takes an exception as a parameter, with this parameter being initialized by the exception that is caught. (While it's not actually a function, thinking of it this way can make it easier to understand.)

5. **Defining a new exception**
    ```C++
    void test4()
    {
        class PEBKACException : public std::exception
        {
            public:
                // note*
                virtual const char*     what() const throw()
                {
                    return ("Problem exist between keyboard and chari")
                }
        };

        try
        {
            test3();
        }
        catch (PEBKACException& e)
        {
            //Handle the fact that the user is an idiot
        }
        catch (std::exception& e)
        {
            //Handle other exceptions that are like std::exception
        }
    }
    ```
Note: throw() at the end of "virtual const char*     what() const throw()" is an
[exception specification](#exception-specification).
with empty parentheses, indicating that the function (what() in this case) will not throw any exceptions.

## Examples
1. **Example**
    ```C++
    #include <iostream>

    int main() {
        try {
            // Code that may throw an exception
            throw 20;  // Throwing an integer exception
        }
        catch (int e) {
            // Code to handle the exception
            std::cout << "Caught an exception with value: " << e << std::endl;
        }

        return 0;
    }
    ```
    - **try block**: It contains the code that could potentially cause an error.
    - **throw statement**: This signals that an exception has occurred. The throw keyword can pass any type of data (in this case, an integer 20).
    - **catch block**: It catches the exception. **The parameter inside the catch block must match the type of the thrown object** (in this case, int).

2. **Example: Basic Exception Handling**
    ```C++
    #include <iostream>
    #include <stdexcept>  // For standard exceptions

    int divide(int a, int b) {
        if (b == 0) {
            throw std::runtime_error("Division by zero!");
        }
        return a / b;
    }

    int main() {
        int x = 10, y = 0;
        
        try {
            // This will throw a runtime_error because y is zero
            int result = divide(x, y);
            std::cout << "Result: " << result << std::endl;
        } catch (const std::runtime_error& e) {
            // Handle the exception by printing the error message
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Program continues here after the catch block (unless it's explicitly terminated)
        return 0;  // Normal exit
    }
    ```
    - divide is a function that checks if the denominator (b) is zero. If it is, the function throws a std::runtime_error exception.
    - In main(), the try block contains the code that might throw an exception (divide(x, y)), and the catch block handles any exceptions that occur, printing an error message.
    -  after the catch block is executed, the **program continues executing** normally unless explicitly terminated.
    - **std::runtime_error** is a specific type of exception provided by the C++ Standard Library. 
    It is used to represent runtime errors (like division by zero in your case).
    - The **& e** part means that e is a reference to the std::runtime_error object that was thrown. 
    This allows you to inspect the details of the exception (in this case, the error message).
    - The **what()** function is a member function of the std::runtime_error class (inherited from std::exception), 
    and it returns a C-style string (const char*) that describes the error. In this case, it returns the message "Division by zero!"

3. **Example: additional code after the catch block**
If the program has additional code after the catch block that uses the variable result, and the exception occurs, there are a few important considerations to keep in mind:
- **Scope of result:** The variable result is declared inside the try block. 
  If an exception is thrown before result is assigned a value (as in your case, 
  due to division by zero), the assignment to result never happens. This means 
  that result is not initialized if an exception is thrown, and the variable 
  goes out of scope after the try-catch block.
- Accessing result after the catch: If you try to use result after the catch block, 
the compiler will not allow it because the variable result is local to the try block 
and isn't accessible outside.
- Solution - Declare result before the try block: If you want to use result after 
the catch block, you need to declare result before the try block so it remains in scope. 
However, you also need to ensure that result is initialized safely, because if an 
exception occurs, result won't have a valid value.
```C++
#include <iostream>
#include <stdexcept>  // For standard exceptions

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero!");
    }
    return a / b;
}

int main() {
    int x = 10, y = 0;
    int result = 0;  // Declare result before the try block, initialize it to a safe value
    
    try {
        result = divide(x, y);  // This might throw an exception
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        result = -1;  // Optionally assign a default value when an error occurs
    }

    // After the catch block, result is still accessible
    if (result != -1) {
        std::cout << "The result is: " << result << std::endl;
    } else {
        std::cout << "The division failed." << std::endl;
    }

    return 0;
}
```

## How Exception Handling Works
When an exception is thrown, the normal flow of the program is interrupted, 
and C++ starts looking for a matching catch block to handle that exception. 
If it finds a suitable catch block, the exception is handled, and the program 
continues from that point. If no catch block matches the exception, the program terminates.

## Types of Exceptions
You can throw and catch **any type of object** in C++: built-in types (like int, char, etc.) 
or custom objects (instances of classes). It is common practice to throw exceptions 
as objects of standard library exception classes, or user-defined classes, 
to provide more information about the error.

**Example of Throwing and Catching Different Types**
```C++
#include <iostream>

int main() {
    try {
        throw std::string("An error occurred");
    }
    catch (int e) {
        std::cout << "Caught an integer exception: " << e << std::endl;
    }
    catch (std::string &e) {
        std::cout << "Caught a string exception: " << e << std::endl;
    }

    return 0;
}
```
Here, a std::string exception is thrown, and the appropriate catch block that handles 
std::string catches it.

## Throwing Standard Exceptions
C++ provides a set of standard exceptions in the **<stdexcept>** header file. 
These are predefined classes that can be used for various common error conditions. 
Some common standard exceptions include:

- **std::exception**: The base class for all standard exceptions.
- **std::runtime_error**: Thrown for runtime errors.
- **std::out_of_range**: Thrown when a container is accessed out of bounds.
- **std::invalid_argument**: Thrown when an invalid argument is provided to a function.

## Catching All Exceptions
You can catch all exceptions, regardless of their type, by using an ellipsis **(...)** 
in the catch block. This is useful if you want a generic handler for unexpected exceptions.
```C++
#include <iostream>

int main() {
    try {
        throw 1.5;  // Throwing a double exception
    }
    catch (...) {
        std::cout << "Caught an exception of unknown type." << std::endl;
    }

    return 0;
}
```
This will catch any thrown exception, but it won't provide the details of what exactly was thrown.

## Rethrowing Exceptions
You can rethrow an exception in a catch block if you want to handle it partially 
and pass it on for further handling.
```C++
#include <iostream>

void function() {
    try {
        throw std::runtime_error("Error in function");
    }
    catch (...) {
        std::cout << "Caught in function, rethrowing..." << std::endl;
        throw;  // Rethrow the current exception
    }
}

int main() {
    try {
        function();
    }
    catch (const std::runtime_error& e) {
        std::cout << "Caught in main: " << e.what() << std::endl;
    }

    return 0;
}
```
Here, the exception is caught in the function() and rethrown to be handled by the main() function.

## Custom Exception Classes
1. **inheriting from std::exception**
    You can create your own exception classes by inheriting from std::exception 
    or other standard exception types.
    ```C++
    #include <iostream>
    #include <exception>

    class MyException : public std::exception {
    public:
        const char* what() const throw() 
        {
            return "Custom Exception Occurred!";
        }
    };

    int main() {
        try {
            throw MyException();
        } catch (const MyException& e) {
            std::cerr << e.what() << std::endl;
        }
        
        return 0;
    }
    ```
    - **Inheritance**: MyException inherits from the standard std::exception class, 
      which is the base class for all exceptions in the C++ Standard Library.
    - **what() function**: The what() function is a virtual function inherited 
      from std::exception. It returns a const char*, allowing the exception to 
      provide a description of the error. In this case, it returns a fixed string 
      ("Custom Exception Occurred!").
    - **Standard Conformance**: This class leverages the existing exception-handling 
      mechanism of C++ (std::exception), which makes it more standard-conforming 
      and compatible with other standard exception-handling features. 
      You can catch this exception using catch (std::exception&), making it more versatile.
    - **Performance**: Since it only returns a fixed string, there's no dynamic 
      memory allocation or complex logic involved. It's generally faster and 
      simpler to use for basic exceptions.

2. **Custom**
    You can throw and catch exceptions as objects of custom classes. 
    This allows you to encapsulate detailed error information.
    ```C++
    #include <iostream>

    class MyException {
    private:
        std::string errorMessage;
    public:
        MyException(const std::string& message) : errorMessage(message) {}
        
        std::string getMessage() const {
            return errorMessage;
        }
    };

    int main() {
        try {
            throw MyException("Custom exception occurred");
        }
        catch (const MyException& e) {
            std::cout << "Caught custom exception: " << e.getMessage() << std::endl;
        }

        return 0;
    }
    ```
    - **No Inheritance**: MyException does not inherit from std::exception. 
      This means it doesn't integrate with the standard C++ exception hierarchy, 
      so you can't catch it using catch (std::exception&).
    - **Custom Member Variable**: The class has a std::string member (errorMessage), 
      which allows it to hold a custom error message passed during construction.
    - **Flexibility in Error Message**: The exception message is not hardcoded but passed 
      dynamically when an object of MyException is thrown. This allows for more 
      flexibility compared to the first example where the message is fixed.


## Exception Specification
In C++98, **exception specifications** allow you to **declare which exceptions a function might throw**. This is done using dynamic exception specifications with the throw keyword, followed by a list of exception types.

### Dynamic Exception Specification in C++98
A **dynamic exception specification** in C++98 specifies the types of exceptions a function might throw, helping users understand what to expect from a function’s behavior. The **syntax** for dynamic exception specifications uses throw with a list of exception types in parentheses:
```C++
void myFunction() throw(int, std::runtime_error);
```

In this example:
- myFunction promises that it will only throw exceptions of type **int** or **std::runtime_error**.
- If it throws an exception of a different type, the std::unexpected function is called, which by default will call std::terminate, ending the program.

**Example of Exception Specification in C++98**
```C++
#include <iostream>
#include <stdexcept>

void riskyFunction() throw(std::runtime_error) {
    throw std::runtime_error("Runtime error occurred");
}

int main() {
    try {
        riskyFunction();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
```

### throw() Specification
the **throw() specifier** (with no parameters) is used to indicate that a function does not throw any exceptions (guarantee that the method cannot propagate any further exceptions). If an exception is thrown inside a function marked with throw(), the program will call std::unexpected(), which typically leads to std::terminate(), causing the program to terminate.

- **Declaring Non-Throwing Functions**: When a function is marked with throw(), it informs the compiler and the programmer that the function is not supposed to throw exceptions. This can help optimize the code since the compiler does not need to handle exceptions in these functions.
- **Exception Safety**: Using throw() signals that no exceptions should be thrown from the function. **If an exception is thrown, the program will terminate**, rather than propagate the exception.

```C++
void myFunction() throw() { // Indicates no exceptions will be thrown
    // Function logic
}
```

**Implications**
- **Performance**: Declaring functions with throw() allows the compiler to generate more efficient code because it doesn't need to account for exceptions. However, be cautious, as marking a function with throw() makes it critical that no exceptions are thrown from that function.
- **Termination on Exception**: If a function marked with throw() does throw an exception, the program will invoke std::unexpected(), leading to termination. This differs from functions without the throw() specifier, which would propagate the exception.

### Limitations of Dynamic Exception Specifications
- **Not Type-Safe**: Dynamic exception specifications allow functions to specify certain types, but they don’t enforce strict safety at runtime. If the wrong type is thrown, the program will be terminated.
- **Performance Cost**: Compilers must verify that exceptions conform to the specification, which can lead to additional overhead.
- **Deprecation in Modern Standards**: Due to these limitations, dynamic exception specifications were deprecated in C++11 and fully removed in C++17.




## Stack Unwinding
When an exception is thrown, C++ begins a process called stack unwinding, where 
it destroys all local objects in the reverse order of their creation until it finds 
a matching catch block.
```C++
#include <iostream>

class Test {
public:
    Test() {
        std::cout << "Constructor called" << std::endl;
    }
    ~Test() {
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    try {
        Test obj;
        throw 100;
    }
    catch (int e) {
        std::cout << "Caught exception: " << e << std::endl;
    }

    return 0;
}
```
In this example, when an exception is thrown, the destructor of the Test object 
is called as part of the stack unwinding process.



## Exception Handling Best Practices
- **Throw by value, catch by reference**: Always throw exception objects by value and 
catch them by reference to avoid slicing and performance issues.
    ```C++
    try {
        throw std::runtime_error("Error");
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    ```
- **Use standard exceptions**: Prefer using standard exceptions (std::runtime_error, 
std::invalid_argument, etc.) when possible to keep your code consistent and more readable.
- **Avoid throwing exceptions in destructors**: Throwing exceptions from a destructor 
can cause undefined behavior, especially if an exception is already active.
- **Only use exceptions for exceptional cases**: Exceptions should not be used for regular °
control flow, but rather for handling errors and unexpected events.