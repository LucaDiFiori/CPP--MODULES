# CPP---Module---01
This module is designed to help you understand the memory allocation, reference, pointers to members and the usage of the switch in CPP.

***

# C++ BASICS 01

***

# Table of Contents
- [NEW AND DELETE](#new-and-delete)
- [REFERENCES](#references)
- [FILESTREAMS](#filestreams)
- [POINTERS TO MEMBER FUNCTIONS](#pointers-to-member-functions)
- [SWITCH STATEMENT](#switch-statement)

***

## NEW AND DELETE
In C++, new and delete are operators used for dynamic memory management. They allow you to allocate and deallocate memory for objects at runtime. Here's a detailed explanation of each:

## New Operator
**purpose**: Allocates memory on the heap for an object or an array of objects.
**Syntax**:
- For a single object:
```C++
Type* pointer = new Type; // Allocates memory for one object of Type
```
- For an array of objects:
```C++
Type* pointer = new Type[size]; // Allocates memory for an array of 'size' objects

```
**Returns**: A pointer to the allocated memory. If the allocation fails, it throws a std::bad_alloc exception.

**example**:
```C++
//1
int* intPtr = new int; // Allocates memory for an integer
*intPtr = 42; // Assigning value

//2
int* arrayPtr = new int[10]; // Allocates memory for an array of 10 integers
for (int i = 0; i < 10; ++i) {
    arrayPtr[i] = i; // Initializing array elements
}
```

## Delete Operator
**purpose**: Deallocates memory that was previously allocated with new to prevent memory leaks.
**Syntax**:
- For a single object:
```C++
delete pointer; // Deallocates memory for the object pointed to by pointer
```
- For an array of objects:
```C++
delete[] pointer; // Deallocates memory for the array of objects
```

**example**
```C++
delete intPtr; // Deallocates memory for a single integer
delete[] arrayPtr; // Deallocates memory for the array of integers
```

### Example with class
```C++
#include <string>

class Student
{
	private:
		std::string _login;

	public:
		Student(std::string login) : _login(login)
		{
			std::cout << "Student " << this->_login << " is born" << std::endl;
		}
		~Student()
		{
			std::cout << "Student " << this->_login << " died" << std::endl;
		}
};

int main()
{
    // Allocate a student variable on the stack
    // "bob" is a Student type variable (created on the stack)
    Student bob = Student("bfubar");

    // Allocate a student variable on the heap
    // "jim" is a pointer to a Student object
    // "new Student("jfubar");" allocates memory for a Student object on the heap and returns a pointer to it
    Student* jim = new Student("jfubar");

    // Do some stuff

    // Free the memory allocated for "jim" on the heap
    // The Student destructor will be called before memory is freed
    delete jim; 

    // bob is automatically destroyed when it goes out of scope at the end of the function
    return (0); 
}
```

## Allocate multiple objects
To allocate multiple objects dynamically in C++, you can use the new operator with an array. Here’s how you can allocate and deallocate multiple objects:
```C++
class Student
{
	private:
		std::string _login;

	public:
		Student() : _login("default")
		{
			std::cout << "Student " << this->_login << " is born" << std::endl;
		}
		~Student()
		{
			std::cout << "Student " << this->_login << " died" << std::endl;
		}
};

int main()
{
    // Allocate an array of 3 contiguos Student objects on the heap
    // "students" is a pointer to the first element of the array of Student objects
    Student* students = new Student[3];

    // You can now access and initialize each Student in the array
    students[0] = Student("Alice");
    students[1] = Student("Bob");
    students[2] = Student("Charlie");

    // Do some stuff with the students

    // Free the memory allocated for the array of Student objects
    delete[] students;  // Note the use of delete[] for arrays

    return 0;
}
```
Note: In this example, we use a default constructor when allocating memory, and then we assign individual Student objects to each array element. If you want to directly initialize the objects at allocation time, you will need a more advanced solution.

***

##  REFERENCES
In C++, a reference is an alias for an existing variable. It allows you to create another name for a variable, enabling you to access and modify the original variable through this new name. References are particularly useful for function parameters, where they can help avoid copying large objects, improving performance.

*From "lear.microsoft.com"*:
A reference, like a pointer, stores the address of an object that is located elsewhere in memory. Unlike a pointer, a reference after it's initialized can't be made to refer to a different object or set to null. There are two kinds of references: lvalue references, which refer to a named variable and rvalue references, which refer to a temporary object. The & operator signifies an lvalue reference and the && operator signifies either an rvalue reference, or a universal reference (either rvalue or lvalue) depending on the context.

## Key Characteristics of References:
### 1. Syntax
A reference is declared using the & symbol.
```C++
int& ref = originalVariable //creates a reference to originalVariable
```

### 2. Initialization
A reference must be **initialized when it is created** (on the same line), and it cannot be changed to refer to another variable after initialization.

### 3. Behavior
A reference acts like the variable it refers to. Any operation performed on the reference will directly affect the original variable.

### 4. Cannot be Null:
Unlike pointers, references cannot be null. They must always refer to a valid object.


**Example: 0. reference vs pointer**
```C++
#include <iostream>

int main()
{
    int numberOfiBalls = 42;

    int* ballsPtr = &numberOfBalls;
    int& ballsRef = numberOfBalls; //Assigning "numberOfBalls" by reference, not its address

    std::cout << " " << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl; //output= 42 42 42

    *ballsPtr = 21;
    std::cout << numbetOfBalls << std::endl // output: 21
    ballsRef = 84;
    std::cout << numbetOfBalls << std::endl // output: 84
    // Note: References don't need to be dereferenced (* operator); they automatically refer to the original variable!
}
```

**Example: 1. Passing parameters by reference**
```C++
#include <iostream>
using namespace std;

void increment(int& value) { // 'value' is a reference to an integer
    value++; // Increment the original variable
}

int main() {
    int num = 5;
    cout << "Original num: " << num << endl; // Output: 5

    increment(num); // Pass num by reference
    cout << "After incrementing: " << num << endl; // Output: 6

    return 0;
}
```

**Example: 2. Passing parameters by reference**
```C++
#include <string>
#include <iostream>

// Takes a pointer to std::string, modifies the original string via pointer
void byPtr(std::string* str) 
{
    *str += " and ponies"; // Dereferences the pointer and appends " and ponies" to the original string
}

// Takes a pointer to const std::string, can only read, not modify the original string
void byConstPtr(std::string const * str)
{
    std::cout << *str << std::endl; // Dereferences the pointer and prints the string (read-only)
}

// Takes a reference to std::string, modifies the original string via reference
void byRef(std::string& str) 
{
    str += " and ponies"; // Directly appends " and ponies" to the original string
}

// Takes a const reference to std::string, can only read, not modify the original string
void byConstRef(std::string const & str) 
{
    std::cout << str << std::endl; // Prints the string (read-only)
}

int main() 
{
    std::string str = "I like butterflies"; // Initialize the string

    std::cout << str << std::endl; // Prints: I like butterflies
    byPtr(&str); // Calls byPtr, modifies the string through the pointer
    byConstPtr(&str); // Calls byConstPtr, prints the modified string

    str = "I like otters"; // Resets the string to a new value

    std::cout << str << std::endl; // Prints: I like otters
    byRef(str); // Calls byRef, modifies the string via reference
    byConstRef(str); // Calls byConstRef, prints the modified string

    return (0);
}
```

**Example: 3. Return by reference**
```C++
#include <iostream>
#include <string>

class Student
{
    private:
        std::string _login; // Private member variable to store the student's login

    public:
        // Constructor that initializes _login with the parameter 'login' 
        Student(std::string const & login) : _login(login) 
        {
        }

        // Returns a non-const reference to _login, allowing modification of the login
        std::string& getLoginRef() 
        {
            return (this->_login); // Return reference to _login, allows modification
        }

        // Returns a const reference to _login, preventing modification
        std::string const & getLoginRefConst() const 
        {
            return (this->_login); // Return const reference to _login, read-only
        }

        // Returns a non-const pointer to _login, allowing modification of the login through the pointer
        std::string* getLoginPtr() 
        {
            return &(this->_login); // Return pointer to _login, allows modification
        }

        // Returns a const pointer to _login, preventing modification
        std::string const * getLoginPtrConst() const 
        {
            return &(this->_login); // Return const pointer to _login, read-only
        }
};

int main()
{
    // Create two Student objects: one mutable and one const
    Student bob = Student("bfubar");           // bob is a regular (non-const) Student object
    Student const jim = Student("jfubar");     // jim is a const Student object, can't be modified

    // Output the login for both bob and jim using const reference and pointer getters
    // Note: Using a const function in a non-cost variable is ok here
    std::cout << bob.getLoginRefConst() << " = " << jim.getLoginRefConst() << std::endl; 
    // getLoginPtrConst returns a pointer, so I need to dereference it to access the value
    std::cout << *(bob.getLoginPtrConst()) << " = " << *(jim.getLoginPtrConst()) << std::endl;

    // Modify bob's login using the non-const reference getter
    // getLoginRef returns a reference (an alias for the actual login variable), so I can modify it
    bob.getLoginRef() = "bobfubar";
    std::cout << bob.getLoginRefConst() << std::endl;  // Output the modified login for bob

    // Modify bob's login again using the non-const pointer getter
    *(bob.getLoginPtr()) = "bobbyfubar";
    std::cout << bob.getLoginRefConst() << std::endl;  // Output the modified login for bob

    return 0;
}
```

### Advantages of Using References:
- Efficiency: Passing large objects by reference avoids the overhead of copying.
- Simplicity: The syntax for references is cleaner and easier to read compared to pointers.
- Safety: References must be initialized and cannot be reassigned, reducing the risk of null pointer dereferencing.

### References vs Pointers
While both references and pointers allow you to refer to other variables, they have key differences:
- **References:**
    - Must be initialized when declared.
    - Cannot be null (no null references).
    - Cannot be reassigned to refer to a different variable.
    - Syntax is cleaner and easier to use.
- **Pointers**
    - Can be initialized at any time, or left uninitialized.
    - Can be null.
    - Can be reassigned to point to different variables.
    - Allow pointer arithmetic.
In general, references are preferred when you don't need the flexibility that pointers provide, as they are safer and less  error-prone.

***

## FILESTREAMS
In C++, file streams are used to perform input and output operations on files. They provide a way to read data from files and write data to files using the same principles as standard input/output operations. The C++ standard library includes several classes in the <fstream> header for handling file streams.

## Types of File Streams
### 1. ifstream (Input File Stream):
Used for reading data from files.

**Example**
```C++
// The code opens a text file named "example.txt", reads its contents line by line, and prints each line to the console
std::ifstream inputFile("example.txt");
if (inputFile.is_open()) {
    std::string line;
    while (getline(inputFile, line)) {
        std::cout << line << std::endl; // Output each line from the file
    }
    inputFile.close(); // Always close the file after use
}
```

### 2. ofstream (Output File Stream):
Used for writing data to files.

**Example**
```C++
std::ofstream outputFile("output.txt");
if (outputFile.is_open()) {
    outputFile << "Hello, World!" << std::endl; // Write to the file
    outputFile.close(); // Always close the file after use
}
```

### 3. fstream (File Stream):
A combination of both input and output file streams. It can read from and write to files.

**Example**
```C++
std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::app);
if (file.is_open()) {
    file << "Appending this line to the file." << std::endl; // Write to the file
    file.seekg(0); // Move cursor to the beginning for reading
    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl; // Output each line from the file
    }
    file.close(); // Always close the file after use
}
```
std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::app) 
create an std::fstream object that can read from and write to a file. Let's break down the components:
- **std::fstream**: This is a class in the C++ Standard Library that provides facilities for file input and output. It allows you to read from and write to files simultaneously.
- **file**: This is the name of the fstream object being created.
- **example.txt**: This is the name of the file you are opening. If the file does not exist, it will be created when you write to it.
- **std::ios::in**: This flag indicates that the file will be opened for reading.
- **std::ios::out**: This flag indicates that the file will be opened for writing
- **std::ios::app**: This flag indicates that all write operations will be appended to the end of the file. It means new data will be added after the existing content instead of overwriting it.

The use of the bitwise OR operator (|) combines the three flags. This means that the file can be read from and written to, and any data written will be added at the end of the file.

### Key Operations
- **Opening a File**: 
    - You can open a file by creating an instance of **ifstream**, **ofstream**, or **fstream** and passing the file name as a parameter.
    - You can also specify file modes (e.g., read, write, append) using **std::ios::** flags.
- **Checking if a File is Open:**:
    - Use the **is_open()** method to check if the file has been successfully opened.
- **Reading from a File:**:
    - Use methods like **getline()**, **>>** operator, or the **read()** method to read data from a file.
- **Writing to a File:**:
    - Use the **<<** operator or the **write()** method to write data to a file.
- **Closing a File**:
    - Always close a file using the **close()** method after you are done with file operations to release system resources.

### Error Handling
You can check for errors while opening, reading, or writing to files using the **fail()** method or checking the stream state.

#### Example
```C++
#include <iostream>
#include <fstream>

int main()
{
    // Open an input file stream to read from the file named "numbers"
    std::ifstream ifs("numbers");
    
    // Declare two unsigned integer variables to hold the values read from the file
    unsigned int dst;  
    unsigned int dst2;

    // Read two unsigned integers from the file and store them in dst and dst2
    // chaining >>: The extraction operator allows for chaining, meaning you can 
    //              use it multiple times in one statement. Each call to >> reads 
    //              the next piece of data from the input stream.
    //              First, ifs >> dst reads the first number from the file and stores it in dst
    //              Next, >> dst2 takes the next number from the stream 
    //              (the one immediately following the first number) and stores it in dst2.
    ifs >> dst >> dst2;

    // Output the values read from the file to the console
    std::cout << dst << " " << dst2 << std::endl;

    // Close the input file stream to release system resources
    ifs.close();

    //-----------------------

    // Open an output file stream to write to the file named "test.out"
    std::ofstream ofs("test.out");

    // Write the string "i like ponies" to the file, followed by a newline character
    ofs << "i like ponies" << std::endl;

    // Close the output file stream to release system resources and ensure all data is flushed to the file
    ofs.close();
    }
```

***

## POINTERS TO MEMBER FUNCTIONS
In C++, "pointers to member functions" are a special type of pointer that points to member functions of a class. Unlike regular function pointers, which point to regular functions, pointers to member functions take into account the class instance (object) they belong to.

## Pointer to Member Function Syntax
The syntax for declaring a pointer to a member function is quite specific and is different from regular function pointers. It includes the class name, and uses ::* to denote that it points to a member function of that class.
```C++
returnType (ClassName::*pointerName)(parameterTypes);
```

**Example**
```C++
class MyClass {
public:
    void memberFunction();
};

// Pointer to a member function of MyClass
void (MyClass::*ptrToMemberFunc)();
```

## Initializing a Pointer to Member Function
To assign a member function to a pointer, you use the address-of operator **&** with the scope resolution operator **ClassName::**.

**Example**
```C++
ptrToMyFunction = &MyClass::myFunction;
```

## Invoking a Member Function through a Pointer
To invoke a member function using a pointer to that function, you need to specify the object through which you want to call the function. This is done using either the .* operator for a direct object or the ->* operator for a pointer to an object.

**Example**
```C++
MyClass obj;
(obj.*ptrToMyFunction)(); // Calls myFunction on obj
```
**If you have a pointer to an object:**
```C++
MyClass* objPtr = &obj;
(objPtr->*ptrToMyFunction)(); // Also calls myFunction on obj
```

### Full Example
```C++
#include <iostream>

class MyClass {
public:
    void display() {
        std::cout << "Display function called" << std::endl;
    }
    
    void greet(std::string name) {
        std::cout << "Hello, " << name << "!" << std::endl;
    }
};

int main() {
    MyClass obj;

    // Pointer to member function that takes no parameters
    void (MyClass::*ptrDisplay)() = &MyClass::display;

    // Pointer to member function that takes a string parameter
    void (MyClass::*ptrGreet)(std::string) = &MyClass::greet;

    // Call member function using object
    (obj.*ptrDisplay)(); // Calls display function

    // Call member function with a parameter
    (obj.*ptrGreet)("Alice"); // Calls greet function with "Alice"

    // Using a pointer to an object
    MyClass* objPtr = &obj;
    (objPtr->*ptrDisplay)(); // Calls display function
    (objPtr->*ptrGreet)("Bob"); // Calls greet function with "Bob"

    return 0;
}
```

***

## SWITCH STATEMENT
The switch statement in C++ is a control structure used for executing one block of code among many, based on the value of a single variable or expression. It's an alternative to multiple if-else statements, making the code more readable when there are multiple conditions to check against the same variable.

## Basic Structure of a switch Statement:
```C++
switch (expression) {
    case constant1:
        // Code to execute if expression equals constant1
        break;
    case constant2:
        // Code to execute if expression equals constant2
        break;
    case constant3:
        // Code to execute if expression equals constant3
        break;
    default:
        // Code to execute if none of the cases match
        break;
}
```

## Key Points:
- **Expression**: The expression inside the **switch** is evaluated once and compared with each **case**. The expression must result in an integral value (like int, char, enum), meaning you can't use non-integral types like float or string.
- **Case Labels**: Each case represents a possible value of the **expression**. When the value of the expression matches a case, the code following that case label is executed.
- **Break Statement**: The break statement exits the switch block. If break is omitted, execution will "fall through" to the next case, meaning the code for subsequent cases will also be executed until a break or the end of the switch is reached. In most cases, you'll want to use break to prevent this.
- **Default Case**: The default case is optional. If none of the case values match the expression, the default block is executed. It works like the else block in if-else statements.

### Examples:
```C++
#include <iostream>

int main() {
    int day = 4;

    switch(day) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        case 4:
            std::cout << "Thursday" << std::endl;
            break;
        case 5:
            std::cout << "Friday" << std::endl;
            break;
        case 6:
            std::cout << "Saturday" << std::endl;
            break;
        case 7:
            std::cout << "Sunday" << std::endl;
            break;
        default:
            std::cout << "Invalid day" << std::endl;
    }

    return 0;
}
```

## Key Behaviors:

- **Fallthrough**: If the break statement is omitted in a case, execution continues into the next case.
```C++
int num = 2;
switch (num) {
    case 1:
        std::cout << "One";
    case 2:
        std::cout << "Two";  // Falls through and executes next case.
    case 3:
        std::cout << "Three";
}

// Output: "TwoThree"
```

- **Default**: The default case is executed if no case matches.
```C++
int num = 10;
switch (num) {
    case 1:
        std::cout << "One";
        break;
    default:
        std::cout << "Not One";
}

// Output: "Not One"
```

- **Multiple Cases with the Same Action**: You can stack case labels to execute the same code for different values.
```C++
switch (num) {
    case 1:
    case 2:
    case 3:
        std::cout << "One, Two, or Three";
        break;
}
```