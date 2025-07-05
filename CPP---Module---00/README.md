# CPP---MODULE---00
This first module of C++ is designed to help you understand the specifities of the language when compared to C. Time to dive into Object Oriented Programming!

## Description
In this initial series of exercises, we'll cover the basic syntax of C++: explore namespaces, dive into classes, and get familiar with member functions along with a few other key concepts.

# EX00 - MEGAPHONE
The provided C++ program processes command-line arguments by converting each argument to uppercase and printing them separated by spaces. If no arguments are provided, it outputs a default message: * LOUD AND UNBEARABLE FEEDBACK NOISE *.

***

# C++ BASICS 00

# Table of Contents
- [NAMESPACE](#namespace)
- [SCOPE RESOLUTION OPERATOR ::](#scope-resolution-operator-"::")
- [STD IOSTREAMS](#std-iostreams)
- [CLASS AND INSTANCE](#class-and-instance)
- [DIRECT INITIALIZATION](#direct-initialization)
- [THIS](#this)
- [INITIALIZATION LIST](#initialization-list)
- [CONST](#const)
- [VISIBILITY](#visibility)
- [ACCESSORS](#accessors)
- [COMPARISONS OF OBJECTS](#common-of-objects)
- [STATIC - NON MEMBER ATTRIBUTES AND NON MEMBER FUNCTIONS](#static---non-member-attributes-and-non-member-functions)
- [REFERENCE (&)](#reference-(&))
- [POINTERS TO MEMBERS](#pointers-to-members)
- [STD::VECTOR](#stdvector)
- [STD::FOR_EACH](#stdfor_each)
- [STD::MEM_FUN_REF](#stdmem_fun_ref)
- [STD::PAIR](#stdpair)

***

## NAMESPACE
In C++, a namespace is a declarative region that provides a scope to identifiers such as variables, functions, classes, etc., to avoid name conflicts. Namespaces help organize code and prevent naming collisions, especially when using large libraries or multiple codebases with common names.

To create your own namespace in C++, use the namespace keyword followed by the name of the namespace, and enclose the declarations (variables, functions, classes, etc.) inside curly braces {}.

```C++
#include <stdo.h>

//declaring a global variable and a function
int gl_var = 1;
int f(void) {return 2;}

// Creating a custom namespace named "Foo"
namespace Foo {
  int gl_var = 3;
  int f(void) {return 4;}
}

// Creating a custom namespace named "Bar"
namespace Foo {
  int gl_var = 5;
  int f(void) {return 6;}
}
```
*Note: In C++, having three variables with the same name is not an issue because they belong to different scopes. The global gl_var is in the global scope, while the others are in the Foo namespace. C++ resolves variable names based on their scope, so there won't be any compilation conflicts.
You can then access, for example, the gl_var in the Foo namespace like so: Foo::gl_var.

### Namespace aliasing
Namespace aliasing in C++ allows you to create a shorter or more convenient name (alias) for an existing namespace. This is useful when you're dealing with long or nested namespaces, as it makes the code more readable and easier to manage.

You can create a namespace alias using the namespace keyword followed by the alias name, an equals sign =, and the existing namespace.
```C++
namespace VeryLongNamespaceName {
    void display() {
        std::cout << "Inside VeryLongNamespaceName!" << std::endl;
    }
}

// Create a shorter alias for the namespace
namespace VLN = VeryLongNamespaceName;

int main() {
    // Using the alias to access the display function
    VLN::display();  // Equivalent to VeryLongNamespaceName::display()
}
```

***

## SCOPE RESOLUTION OPERATOR "::"
The scope resolution operator in C++ is :: and is used to specify which scope an identifier (such as a variable, function, or class) belongs to. It helps disambiguate identifiers with the same name that exist in different scopes or namespaces.
### Key Uses of the Scope Resolution Operator
#### 1 Accessing Global Variables or Functions:
- When a local variable or function hides a global variable or function, you can use the scope resolution operator to access the global version.
```C++
int value = 10; // Global variable

void function() {
    int value = 20; // Local variable
    std::cout << "Local value: " << value << std::endl; // Prints 20
    std::cout << "Global value: " << ::value << std::endl; // Prints 10
}
```
#### 2 Defining Member Functions Outside a Class:
- The scope resolution operator is used to define member functions of a class outside the class definition.
```C++
class MyClass {
public:
    void display();
};

void MyClass::display() {
    std::cout << "Display function" << std::endl;
}
```
#### 3 Accessing Namespace Members:
- When dealing with namespaces, the scope resolution operator helps access elements within a specific namespace.
```C++
namespace MyNamespace {
    int value = 30;
}

int main() {
    std::cout << MyNamespace::value << std::endl; // Accesses MyNamespace::value
    return 0;
}
```
#### 4 Accessing Nested Namespaces:
```C++
namespace Outer {
    namespace Inner {
        int value = 40;
    }
}

int main() {
    std::cout << Outer::Inner::value << std::endl; // Accesses Outer::Inner::value
    return 0;
}
```

***

## STD IOSTREAMS
The C++ Standard Library provides a set of standard input and output facilities through a set of classes and functions commonly referred to as "streams." These are part of the <iostream> header. Streams are used to handle input and output operations, and they abstract away the details of how data is read from or written to different types of devices (e.g., keyboards, files, etc.).
Here's a brief overview of the key components:

### 1 Stream Classes
- **std::istream:** This class is used for input operations. It represents the standard input stream (std::cin), but can also be used with other input sources, like files.
- **std::ostream:** This class is used for output operations. It represents the standard output stream (std::cout), but can also be used with other output destinations, like files.
- **std::iostream:** This is a combination of std::istream and std::ostream. It supports both input and output operations. It is typically used for streams that handle both input and output, like file streams.
- **std::ifstream:** This class is derived from std::istream and is used specifically for reading from files.
- **std::ofstream:** This class is derived from std::ostream and is used specifically for writing to files.
- **std::fstream:** This class is derived from std::iostream and can be used for both reading from and writing to files.

### 2 Stream Objects
- **std::cin:** The standard input stream, typically connected to the keyboard.
- **std::cout:** The standard output stream, typically connected to the console.
- **std::cerr:** The standard error stream, used for error messages. It is unbuffered by default.
- **std::clog:** The standard logging stream, used for logging messages. It is buffered by default.

### 3 Basic Usage
- **Input:** To read data from a stream, you use the extraction operator **>>** for formatted input or the getline function for reading whole lines.
```C++
int x;
std::cin >> x; // Read an integer from standard input

std::string line;
std::getline(std::cin, line); // Read a line from standard input
```
- **Output:** To write data to a stream, you use the insertion operator **<<** for formatted output.
```C++
int x = 42;
std::cout << "The value is: " << x << std::endl; // Output to standard output
```

### 4 File Operations
- **Reading from a file**
```C++
std::ifstream infile("example.txt");
if (infile.is_open()) {
    std::string line;
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }
    infile.close();
}
```
- **Writing to a file:**
```C++
std::ofstream outfile("example.txt");
if (outfile.is_open()) {
    outfile << "Hello, file!" << std::endl;
    outfile.close();
}
```

### 5 Error Handling
Streams provide several methods to check their state:
- **good():** Returns true if the stream is in a good state.
- **bad():** Returns true if a serious error occurred.
- **fail():** Returns true if an input or output operation failed.
- **eof():** Returns true if the end of the file has been reached

Ex:
```C++
if (infile.fail()) {
    std::cerr << "Error reading from file" << std::endl;
}
```

### 6 Manipulators
Stream manipulators are special functions that modify the formatting of the output. Some common manipulators include:
- **std::endl:** Inserts a newline character and flushes the stream
- **std::setw(int):** Sets the width of the next input/output field.
- **std::fixed:** Used to set the floating-point format to fixed-point notation
- **std::setprecision(int):** Sets the number of digits after the decimal point for floating-point numbers.

***

## CLASS AND INSTANCE
## Note on Organizing Class Definitions and Implementations
In C++, it's common practice to separate the class declaration from its implementation:
- Header File (.hpp or .h): Contains the class definition, the declaration of data members and member functions.
```C++
// MyClass.hpp
#ifndef MYCLASS_HPP
#define MYCLASS_HPP

class MyClass {
public:
    MyClass();
    ~MyClass();
    void display() const;
private:
    int myNumber;
};

#endif // MYCLASS_HPP
```
- Source File (.cpp): Contains the implementation of the member functions defined in the class.
```C++
// MyClass.cpp
#include "MyClass.hpp"
#include <iostream>

MyClass::MyClass() : myNumber(0) {}

MyClass::~MyClass() {}

void MyClass::display() const {
    std::cout << "Number: " << myNumber << std::endl;
}
```

## Class
In C++, a class is a fundamental concept in object-oriented programming (OOP) that allows you to define your own custom data types. A class combines data and functions into a single unit, encapsulating the properties (data members) and behaviors (member functions) that operate on the data.

## Key Components of a Class
### 1 Class Definition:
- A **class** is defined using the class keyword, followed by the class name and a block of code that contains its members.
```C++
class MyClass {
public:
    int myNumber; // Data member (public)
    void display(); // Member function (public)
private:
    int secret; // Data member (private)
};
```

### 2 Data Members:
- These are variables that hold the state of the object. They can be public, private, or protected.
  - **Public:** Accessible from outside the class.
  - **Private:** Accessible only within the class.
  - **Protected:** Accessible within the class and by derived classes.

### 3 Member Functions:
- These are functions defined inside the class that operate on the data members. They can also be public, private, or protected.

### 4 Constructors and Destructors:
Constructors and destructors are fundamental components of classes in C++. They manage the initialization and cleanup of objects, respectively. 

#### Constructor 
  - ##### Purpose:
    A constructor initializes an object when it's created. It sets up the object’s initial state and allocates resources if necessary.
    
  - ##### Key Characteristics:
    - **Name:** The constructor has the same name as the class.
    - **No Return Type:** Constructors do not return a value, not even void.
    - **Automatic Invocation:** Constructors are called automatically when an object is instantiated.

  - ##### Types of Constructors:
    - **Default Constructor:** A constructor that takes no arguments. If no other constructor is provided, the compiler provides a default constructor.
      - **Parameterized Constructor:** A constructor that takes one or more arguments to initialize the object with specific values.
      - **Copy Constructor:** A constructor that initializes a new object as a copy of an existing object. It is called when an object is passed by value or explicitly copied.


```C++
// Default constructore
class MyClass {
public:
    MyClass() {
        // Constructor code
    }
};

// Parameterized Constructor
class MyClass {
public:
    MyClass(int a, double b) {
        // Constructor code using a and b
    }
};

//Copy Constructor
class MyClass {
public:
    MyClass(const MyClass& other) {
        // Copy constructor code
    }
};
```

#### Destructor
- ##### Purpose: 
A destructor cleans up resources when an object is destroyed. It deallocates memory and performs other cleanup tasks.

- ##### Key Characteristics:
  - **Name:** The destructor has the same name as the class, preceded by a tilde (~).
  - **No Parameters:** Destructors do not take any arguments.
  - **No Return Type:** Destructors do not return a value.
  - **Automatic Invocation:** Destructors are called automatically when an object goes **out of scope or is explicitly deleted.

```C++
class MyClass {
public:
    // Constructor
    MyClass() {
        // Initialization code
    }
    // Destructor
    ~MyClass() {
        // Cleanup code
    }
};
```
- ##### Key Points:
  - **Destructor Call:** When an object is destroyed, the destructor is called automatically to perform any necessary cleanup.
  - **Order of Destruction:** If a class contains other objects, their destructors are called before the destructor of the containing class.
  - **Resource Management:** Destructors are crucial for managing resources like dynamically allocated memory, file handles, or network connections.

**Example with Dynamic Memory:**
```C++
class MyClass {
private:
    int* data;

public:
    // Constructor
    MyClass(int size) {
        data = new int[size]; // Allocate memory
    }

    // Destructor
    ~MyClass() {
        delete[] data; // Deallocate memory
    }
};
```

## Istance Of a Class
an instance of a class is a specific realization of the class with its own set of data and behaviors. When you create an instance of a class, you are essentially creating an object that uses the blueprint defined by the class.

### 1 Definition of an Instance:
- An instance is an object created from a class. Each instance has its own unique state (data) and can use the class's methods to interact with that state.
```C++
class MyClass {
public:
    int value;
    void showValue() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    MyClass obj1; // Creating an instance (object) of MyClass
    MyClass obj2; // Creating another instance of MyClass

    obj1.value = 10; // Set value for obj1
    obj2.value = 20; // Set value for obj2

    obj1.showValue(); // Output: Value: 10
    obj2.showValue(); // Output: Value: 20

    return 0;
}
```
### 2 Initialization:
- **Default Constructor:** If no constructor is explicitly defined, C++ provides a default constructor that initializes members with default values. This constructor is automatically called when an object is declared.
```C++
class MyClass {
public:
    MyClass() : value(0) {} // Default constructor initializes value to 0
    void showValue() const {
        std::cout << "Value: " << value << std::endl;
    }
private:
    int value;
};

int main() {
    MyClass obj1; // Default constructor is automatically called
    obj1.showValue(); // Output: Value: 0

    return 0;
}
```
- **Parameterized Constructor:** You can define constructors that accept parameters to initialize objects with specific values.
```C++
class MyClass {
public:
    MyClass(int initialValue) : value(initialValue) {} // Parameterized constructor
    void showValue() const {
        std::cout << "Value: " << value << std::endl;
    }
private:
    int value;
};

int main() {
    MyClass obj1(10); // Calls parameterized constructor
    MyClass obj2(20); // Calls parameterized constructor

    obj1.showValue(); // Output: Value: 10
    obj2.showValue(); // Output: Value: 20

    return 0;
}
```

### 3 Instance Data and Methods:
- Each instance maintains its own copy of the data members (attributes) and can call the member functions defined in the class to interact with its data.
```C++
class Counter {
public:
    Counter() : count(0) {} // Constructor initializes count to 0

    void increment() {
        count++;
    }

    void showCount() const {
        std::cout << "Count: " << count << std::endl;
    }

private:
    int count; // Data member unique to each instance
};

int main() {
    Counter counter1; // Instance 1
    Counter counter2; // Instance 2

    counter1.increment();
    counter1.showCount(); // Output: Count: 1

    counter2.increment();
    counter2.increment();
    counter2.showCount(); // Output: Count: 2

    return 0;
}
```
### 4 Dynamic Allocation:
- Instances can also be created dynamically using pointers and the new keyword. This is useful for cases where the number of instances is not known at compile time.
```C++
int main() {
    Counter* pCounter = new Counter(); // Create an instance dynamically
    pCounter->increment();
    pCounter->showCount(); // Output: Count: 1

    delete pCounter; // Clean up the dynamically allocated instance
    return 0;
}
```

### 5 End Of The Program:
When a C++ program ends, several things happen to the objects created during the execution of the program. Here’s what happens to objects and their destructors when the program terminates:
#### Automatic Cleanup
- **1 Automatic (Stack) Variables:**
  - Objects that are created as local variables (i.e., objects with automatic storage duration) are automatically destroyed when they go out of scope. This typically happens at the end of the block in which they were declared, such as at the end of a function.
  - If a class has a destructor defined, this destructor is automatically called when the object goes out of scope. This ensures that any cleanup code within the destructor is executed.
```C++
  class MyClass {
public:
    MyClass() { std::cout << "Constructor called\n"; }
    ~MyClass() { std::cout << "Destructor called\n"; }
};

void myFunction() {
    MyClass obj; // Constructor is called here
    // Destructor will be called when obj goes out of scope
}

int main() {
    myFunction();
    // Destructor is called at the end of myFunction()
    return 0;
}
```

- **2 Dynamic (Heap) Variables:**
  - Objects created dynamically with new (i.e., objects with dynamic storage duration) are not automatically destroyed when the program ends. They must be explicitly deleted using the delete keyword to ensure their destructors are called and resources are properly released.
  If you forget to delete dynamically allocated objects, it can lead to memory leaks because the destructors are not called, and the allocated memory is not freed.
```C++
class MyClass {
public:
    MyClass() { std::cout << "Constructor called\n"; }
    ~MyClass() { std::cout << "Destructor called\n"; }
};

int main() {
    MyClass* pObj = new MyClass(); // Constructor is called here
    delete pObj; // Destructor is called here
    return 0;
}
```

#### Behavior Without a Destructor
- **No Destructor Defined:**
  - If a class does not have an explicitly defined destructor, the compiler provides a default destructor. This default destructor performs basic cleanup, such as calling destructors of member objects (if they have destructors).
  - If there are no resources that require explicit cleanup (e.g., no dynamic memory allocation, file handles, etc.), the default destructor is typically sufficient.
```C++
class MyClass {
public:
    MyClass() { std::cout << "Constructor called\n"; }
    // No explicit destructor
};

int main() {
    MyClass obj; // Default destructor will be called
    return 0;
}
//In the above example, even though MyClass does not define a destructor, the default destructor will be called when obj goes out of scope
```
#### Summary
- **Automatic (Stack) Variables:** When a local object goes out of scope, its destructor is called automatically if one is defined. If no destructor is defined, the compiler generates a default one.
- **Dynamic (Heap) Variables:** Objects created with new need to be explicitly deleted using delete to ensure that their destructors are called and resources are properly released.
- **No Destructor Defined:** If no destructor is explicitly defined, the compiler provides a default destructor that performs basic cleanup.

***

## DIRECT INITIALIZATION
Direct initialization in C++ is a method of creating an object or variable using parentheses, rather than an assignment with an equal sign. This approach can be used for various types of objects, including built-in types (like integers and floats) and user-defined types (like classes and structs).

### Syntax
The syntax for direct initialization is as follows:
```C++
TypeName variableName(arguments);
```

### Example of Direct Initialization
- Here’s a basic example using an integer:
```C++
int x(5); // Directly initializes x to 5
```

- Direct initialization is especially useful for user-defined types, such as classes. Here’s an example with a simple class:
```C++
class Point {
public:
    Point(int x, int y) : x(x), y(y) {} // Constructor
    int x, y;
};

int main() {
    Point p(1, 2); // Directly initializes an object of Point with x=1 and y=2
}
```


***

## THIS
In C++, this is a keyword that refers to the **current instance** of a class or struct. It is a pointer to the object on which a member function is being called. The this pointer is available inside all non-static member functions and can be used to refer to the object itself.
### Key Points about this:
- #### 1 Pointer to the Current Object:
    - Inside a member function of a class, this points to the object that invoked the function. It allows you to refer to the calling object’s members.
- #### 2 Accessing Members:
    - this->member allows you to access the data members or member functions of the object that invoked the current function.
- #### 3 Implicit Use:
    - You don't always need to explicitly use this to refer to members because the compiler automatically understands that you are referring to the current object’s members. However, you can explicitly use this when needed (e.g., if there’s a name conflict with a local variable).
- #### 4 Const Member Functions:
    - In **const** member functions, this is a pointer to const (i.e., this is of type const ClassName*), so the function cannot modify the object.
- #### 5 Returning from Functions:
    - **this** can be returned from member functions when you want to return the object itself or for **method chaining**.
    **Method chaining** allows you to call multiple member functions in a single line. The key idea behind method chaining is that each function returns a reference to the current object (i.e., *this), so further member functions can be called on that object.
- #### 6 Available in Non-Static Member Functions Only:
    - this is available only in non-static member functions because static member functions do not belong to any particular instance of a class.

#### Example
```C++
#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;

public:
    // Constructor
    Rectangle(int width, int height) {
        // Using 'this' to resolve member and parameter name conflicts
        //Note: i use the "->" symbol because "this" is a pointer
        this->width = width;
        this->height = height;
    }

    // A function to calculate the area
    int area() {
        return (this->width * this->height); // using 'this' explicitly
    }

    // A function that returns a reference to the current object
    Rectangle &setWidth(int width) {
        this->width = width;
        return *this; // returning the current object for method chaining
    }

    Rectangle& setHeight(int height) {
        this->height = height;
        return *this;
    }

    void display() {
        cout << "Width: " << this->width << ", Height: " << this->height << endl;
    }
};

int main() {
    Rectangle rect(10, 20);

    rect.display(); // Width: 10, Height: 20

    // Using method chaining, since the member functions return *this
    rect.setWidth(15).setHeight(25);

    rect.display(); // Width: 15, Height: 25
    cout << "Area: " << rect.area() << endl; // Area: 375

    return 0;
}
```
Here’s another example where we use this to call a method from within the constructor:
```C++
class Rectangle {
private:
    int width;
    int height;

public:
    // Constructor using "this" to call methods
    Rectangle(int w, int h) {
        this->setWidth(w);   // Using "this" to call the setWidth() method
        this->setHeight(h);  // Using "this" to call the setHeight() method
    }
    // Method to set width
    void setWidth(int w) {
        this->width = w;
    }
    // Method to set height
    void setHeight(int h) {
        this->height = h;
    }
};
```

***

## INITIALIZATION LIST
We've learned how to initialize the attributes of our class using a parameterized constructor. Now, let's explore another way to initialize our constants within the class.

In C++, an initialization list is **a special syntax used in constructors to initialize member variables of a class directly, before the constructor body is executed**. It provides a more efficient and direct way to initialize members, especially for constant (const) members, reference members, and when you're working with classes that don't have default constructors.

### Syntax of an Initialization List
The initialization list comes after the constructor's parameter list and is prefixed by a colon :. It consists of member variables followed by parentheses () (or curly braces {} in some cases) that contain the values or expressions used to initialize them.
```C++
ClassName(parameters) : member1(value1), member2(value2), ... {
    // Constructor body (optional)
}
```
- **member1(value1):** This means "initialize member1 with value1".
- The initialization happens before the constructor body is executed.

#### Example
```C++
class Rectangle {
private:
    int width;
    int height;

public:
    // Constructor with an initialization list
    Rectangle(int w, int h) : width(w), height(h) {
        cout << "Constructor called!" << endl;
    }

    void display() {
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

int main() {
    Rectangle rect(10, 20);
    rect.display();  // Output: Width: 10, Height: 20
    return 0;
}
```
The actual initialization happens before the constructor body is executed. So by the time you reach the constructor body, the member variables are already initialized.

#### Why Use an Initialization List?
- **1 Efficiency:**
    - When you use an initialization list, the member variables are initialized directly. In contrast, if you initialize members inside the constructor body, the members are first default-initialized (or left uninitialized), and then assigned a value. This involves extra steps and can be less efficient.
- **2 Required for const or reference Members:**
    - const members and references must be initialized when they are created, and cannot be assigned a value later. Thus, an initialization list is the only way to initialize them.
    ```C++
    class Example {
    private:
        const int x;   // A const member
        int& y;        // A reference member

    public:
        // Constructor using initialization list
        Example(int a, int& b) : x(a), y(b) {
            // x and y must be initialized using the initialization list
        }
    };
    ```
- **3 Initializing Complex Members:**
    - When a class contains objects of other classes as members (i.e., composition), and those classes don't have default constructors, you must use the initialization list to initialize them.
    ```C++
    class Point {
    public:
        int x, y;
        Point(int x, int y) : x(x), y(y) {}  // Constructor
    };

    class Line {
    private:
        Point start;
        Point end;

    public:
        // Using initialization list to initialize Point members
        Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {}
    };
    // In this example, the Line class contains two Point objects (start and end). Since Point doesn’t have a default constructor, you must use an initialization list in the Line constructor to initialize the Point objects.
    ```
#### When Should You Use an Initialization List?
- For **const** and **reference** members: These members must be initialized via an initialization list because they cannot be assigned later.
- For **members of types without default constructors**: If your member variables are objects of classes that don’t have default constructors, you have to initialize them using an initialization list.
- To **improve performance:** Initializing a member directly in the initialization list is more efficient than assigning a value in the constructor body, especially for complex objects.

***

## CONST
In C++, the const keyword is used to define constants, making variables and functions immutable in various contexts. It helps ensure that certain values do not change after initialization, which can lead to safer, more efficient, and optimized code.

The const keyword can be applied in different ways:

### 1 const with Variables
When a variable is declared as const, its value cannot be changed after initialization. This applies to both local variables and member variables of a class.
#### 1.1 classic initialization
```C++
const int x = 5;
x = 10; // ERROR: x is const and cannot be modified
```
#### 1.2 initialization list
When you have a const variable in a class, you must initialize it using an initialization list in the constructor because const members must be initialized at the time of object construction and cannot be modified afterward.
```C++
    class Circle {
    private:
        const double radius;  // Constant member variable

    public:
        // Constructor with an initialization list
        Circle(double r) : radius(r) {
            // Initialization list initializes the const member `radius`
            cout << "Circle created with radius: " << radius << endl;
        }
        //some code
    };

    int main() {
        Circle myCircle(5.0);  // Create an instance of Circle with radius 5.0
        //some code
    }
```

### 2 const with Function Parameters
When a function parameter is declared const, it means that the parameter is read-only inside the function and cannot be modified.
```C++
void printValue(const int x) {
    // x is a constant, you can't modify it inside this function
    // x = 10; // ERROR: cannot modify a const parameter
    std::cout << x << std::endl;
}
```
#### 2.1 Const Reference Parameters: 
This is a common usage for function parameters when passing large objects, such as class instances, to avoid unnecessary copying while also ensuring that the function doesn’t modify the original object.
```C++
void display(const std::string& str) {
    // str cannot be modified in this function
    std::cout << str << std::endl;
}
```

### 3 const with Member Functions
In C++, you can declare a member function as const to indicate that the function **will not modify any member variables of the object**.
```C++
class Rectangle {
private:
    int width, height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    // A const member function
    int getArea() const {
        return width * height;  // This function does not modify the object
    }

    // Non-const function that modifies members
    void setWidth(int w) {
        width = w;
    }
};
//NOTE: You cannot call non-const functions inside a const member function.
        // const Rectangle r1(10, 20);
        // r1.getArea();    // OK: getArea() is a const function
        // r1.setWidth(15); // ERROR: Cannot call non-const function on a const object
```

### 4 const with Pointers
const can be used with pointers in different ways to control mutability. There are four common cases:
#### 4.1 const with Pointers
You cannot change the value the pointer points to, but you can change the pointer itself to point to something else.
```C++
const int* ptr = &x; // ptr points to a constant int
*ptr = 10;  // ERROR: Cannot modify the value pointed to by ptr
ptr = &y;   // OK: Can change the pointer itself
```
#### 4.2 Constant pointer to a value (T* const):
You can change the value the pointer points to, but the pointer itself cannot change.
```C++
int* const ptr = &x;  // Constant pointer to an int
*ptr = 10;   // OK: Can modify the value pointed to by ptr
ptr = &y;    // ERROR: Cannot change the pointer itself
```
#### 4.3 Constant pointer to a constant value (const T* const):
You cannot change the value the pointer points to, nor can you change the pointer itself.
```C++
const int* const ptr = &x;
*ptr = 10;  // ERROR: Cannot modify the value
ptr = &y;   // ERROR: Cannot change the pointer itself
```

### 5 const with Return Types
A function can also return a const value or const reference to ensure that the caller cannot modify the returned value.
```C++
const int& getConstValue(const int& x) {
    return x;  // Return a const reference to x
}

int main() {
    int a = 10;
    const int& ref = getConstValue(a);
    ref = 20; // ERROR: Cannot modify a const reference
}
```

### Benefits of Using const:
- **Code Safety:** By using const, you prevent unintended modifications to variables and objects, leading to more robust and bug-free code.
- **Self-documenting Code:** const clearly indicates the intent that a value should not be modified, making the code easier to understand.
- **Optimizations:** The compiler can sometimes make optimizations knowing that certain data won’t change during execution.

### Summary of Key const Usages:
- **const Variables:** Values that cannot be modified after initialization.
- **const Parameters:** Ensures parameters are not modified inside the function.
- **const Member Functions:** Member functions that don’t modify the object’s state.
- **const Pointers:** Control whether the value or the pointer itself can be changed.
- **const Return Types:** Ensures returned values/references are immutable.

***

## VISIBILITY
In C++, visibility (also known as access control) refers to the rules that govern how different parts of a program can access class members (attributes and methods). This is crucial for encapsulation, a key principle of object-oriented programming that helps manage complexity and protect the integrity of data.

**Naming convention** 
Use the "-" symbol like so: _privateName

## Visibility Levels in C++
C++ provides three primary access specifiers to control visibility:

### 1 public:
- Members declared as public are accessible from anywhere in the program. They can be accessed by any code that has visibility to the class.
- Use public to expose methods and variables that need to be accessible from outside the class.

### 2 protected:
- Members declared as protected are accessible only within the class itself and by derived (sub)classes. They are not accessible from outside the class, except through derived classes.
- Use protected for members that should be accessible to subclasses but not to other parts of the program.

### 3 private:
- Members declared as private are accessible only within the class itself. They are not accessible from outside the class or from derived classes.
- Use private to hide implementation details and protect the internal state of the class from external interference.

### Example of Access Specifiers
```C++
class Base {
public:
    int publicVar;       // Accessible from anywhere

    void publicMethod() {
        cout << "Public method called" << endl;
    }

protected:
    int protectedVar;    // Accessible only within this class and derived classes

    void protectedMethod() {
        cout << "Protected method called" << endl;
    }

private:
    int _privateVar;      // Accessible only within this class

    void _privateMethod() {
        cout << "Private method called" << endl;
    }

public:
    // Function to access private members from within the class
    void accessPrivateMembers() {
        _privateVar = 10;
        _privateMethod();
    }
};

class Derived : public Base {
public:
    void accessBaseMembers() {
        publicVar = 5;              // OK: public member is accessible
        publicMethod();            // OK: public method is accessible

        protectedVar = 10;         // OK: protected member is accessible in derived class
        protectedMethod();        // OK: protected method is accessible in derived class

        // _privateVar = 20;       // ERROR: private member of Base is not accessible
        // _privateMethod();      // ERROR: private method of Base is not accessible
    }
};

int main() {
    Base b;
    b.publicVar = 1;             // OK: public member is accessible
    b.publicMethod();           // OK: public method is accessible

    // b.protectedVar = 2;      // ERROR: protected member is not accessible
    // b.protectedMethod();    // ERROR: protected method is not accessible

    // b._privateVar = 3;       // ERROR: private member is not accessible
    // b._privateMethod();     // ERROR: private method is not accessible

    b.accessPrivateMembers();   // OK: This method is public and can access private members

    Derived d;
    d.accessBaseMembers();      // OK: Accesses members from the Base class

    return 0;
}
```

### Additional Points:
- **Default Access Specifiers:**
    - **For classes:** Members are private by default.
    - **For structs:** Members are public by default.
      ```C++
        struct MyStruct {
             int x;  // x is public by default
        };

        class MyClass {
             int x;  // x is private by default
        };
      ```
- **Friend Classes and Functions:**
    - Classes or functions can be declared as friend to allow them access to private and protected members. This is useful for operator overloading and other special cases.
    ``` C++
    class FriendClass;  // Forward declaration

    class MyClass {
        private:
            int _privateVar;
        public:
            friend class FriendClass;  // Friend class declaration
    };

    class FriendClass {
        public:
            void accessMyClass(MyClass& obj) {
            obj._privateVar = 100;  // OK: Friend class can access private members
        }
    };
    ```

***

## ACCESSORS
Accessors in C++ are member functions that provide controlled access to the private or protected data members of a class. They are part of the principle of encapsulation in object-oriented programming, which ensures that the internal state of an object is not directly accessible from outside the class. Instead, access to these members is provided through public methods.

### Purpose of Accessors
- **Encapsulation:** Accessors help protect the internal state of an object by restricting direct access and modifications to its data members.
- **Controlled Access:** They allow controlled access to private data members, potentially adding validation or logic when retrieving or modifying data.
- **Read-Only Access:** Accessors can be used to provide read-only access to private data members, ensuring that external code cannot modify the data.

### Types of Accessors
- **Getter Methods:** These methods are used to retrieve the value of private or protected data members. They are often called "getters" or "accessors."
- **Setter Methods:** These methods are used to modify the value of private or protected data members. They are often called "setters" or "mutators."

### Example
```C++
class Rectangle {
private:
    int width;
    int height;

public:
    // Constructor
    Rectangle(int w, int h) : width(w), height(h) {}

    // Getter for width
    int getWidth() const {
        return width;
    }

    // Setter for width
    void setWidth(int w) {
        if (w >= 0) {  // Example validation
            width = w;
        }
    }

    // Getter for height
    int getHeight() const {
        return height;
    }

    // Setter for height
    void setHeight(int h) {
        if (h >= 0) {  // Example validation
            height = h;
        }
    }

    // Method to calculate area
    int getArea() const {
        return width * height;
    }
};

int main() {
    Rectangle rect(10, 20);

    // Accessing private members via accessors
    cout << "Width: " << rect.getWidth() << endl;
    cout << "Height: " << rect.getHeight() << endl;
    cout << "Area: " << rect.getArea() << endl;

    // Modifying private members via setters
    rect.setWidth(15);
    rect.setHeight(25);

    cout << "Updated Width: " << rect.getWidth() << endl;
    cout << "Updated Height: " << rect.getHeight() << endl;
    cout << "Updated Area: " << rect.getArea() << endl;
}
```
- width and height are private data members and cannot be accessed directly from 
  outside the class.
- Getter methods allow read-only access to width and height. 
  They are **marked const** to indicate that they do not modify the object’s state.
- Setter methods allow modification of the private members width and height. 

***

## COMPARISONS OF OBJECTS
To compare objects of custom classes, you need to define how objects should be compared. 
This is done in 2 ways:

### 1 Overloading Comparison Operators
Suppose you have a Point class and you want to compare Point objects based on their x and y coordinates.
```C++
class Point {
private:
    int x, y;

public:
    Point(int x, int y) : x(x), y(y) {}

    // Overload equality operator
    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }

    // Overload inequality operator
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    // Overload less than operator
    bool operator<(const Point& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }

    // Overload greater than operator
    bool operator>(const Point& other) const {
        return (x > other.x) || (x == other.x && y > other.y);
    }

    // Display the point
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1(3, 4);
    Point p2(5, 6);
    Point p3(3, 4);

    cout << "p1 == p2: " << (p1 == p2) << endl; // false
    cout << "p1 == p3: " << (p1 == p3) << endl; // true
    cout << "p1 != p2: " << (p1 != p2) << endl; // true
    cout << "p1 < p2: " << (p1 < p2) << endl;   // true
    cout << "p1 > p2: " << (p1 > p2) << endl;   // false
}
```

### 2 Comparison methods
you can alternatively create methods within a class to compare objects, rather than overloading comparison operators. While operator overloading is a common and idiomatic approach in C++, providing methods for comparison can be useful for clarity or when operator overloading is not desired.
```C++
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person(const string& name, int age) : name(name), age(age) {}

    // Method to check if the current person is older than another person
    bool isOlderThan(const Person* other) const {
        if (other == nullptr) {
            cerr << "Error: Comparison with a null pointer." << endl;
            return false;
        }
        return (age > other->age);
    }

    // Method to check if the current person is younger than another person
    bool isYoungerThan(const Person* other) const {
        if (other == nullptr) {
            cerr << "Error: Comparison with a null pointer." << endl;
            return false;
        }
        return age < other->age;
    }

    // Method to check if the current person is the same age as another person
    bool isSameAgeAs(const Person* other) const {
        if (other == nullptr) {
            cerr << "Error: Comparison with a null pointer." << endl;
            return false;
        }
        return age == other->age;
    }

    // Display the person's information
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person alice("Alice", 30);
    Person bob("Bob", 25);
    Person charlie("Charlie", 30);

    // Display information
    alice.display();
    bob.display();
    charlie.display();

    // Compare ages using pointers
    cout << "Alice is older than Bob: " << (alice.isOlderThan(&bob) ? "Yes" : "No") << endl;
    cout << "Bob is younger than Charlie: " << (bob.isYoungerThan(&charlie) ? "Yes" : "No") << endl;
    cout << "Alice is the same age as Charlie: " << (alice.isSameAgeAs(&charlie) ? "Yes" : "No") << endl;

    // Comparing with a null pointer (error case)
    Person* nullPerson = nullptr;
    cout << "Alice is older than a null person: " << (alice.isOlderThan(nullPerson) ? "Yes" : "No") << endl;
}

//NOTE:if the elements you need to compare are private within a class, you typically need to use getter methods
```

***

## STATIC - NON MEMBER ATTRIBUTES AND NON MEMBER FUNCTIONS
In C++, non-member attributes and non-member functions are elements that exist outside the scope of a class but can interact with class objects or work with class data in specific ways. Understanding these concepts can be useful for designing flexible and modular code.

Let's delve into non-member attributes and non-member functions with a focus on how the static keyword plays a role in their behavior and organization in C++.

We saw that a member function or attribute is something present in the instance of a class. This means that the class needs to be instantiated in order to use these attributes or functions. Another property of member attributes is that each attribute is unique to every instance

## Static Keyword Overview
In C++, the static keyword can be used in different contexts:

- **Static Member Variables:** Belong to the class rather than any particular instance.
- **Static Member Functions:** Can be called without an object of the class and can only access static members.
- **Static Local Variables:** Persist between function calls and retain their value.
- **Static Global Variables and Functions:** Have internal linkage, meaning they are limited to the file in which they are defined.

## Non-Member Attributes with Static Keyword
C++ does not have "non-member attributes" in the sense of class-level attributes outside of classes. However, you can use the static keyword for global variables and functions to achieve a similar effect.

## Static Member Variables and Functions
Static member variables and functions are part of a class but are shared among all instances of the class. They can be accessed without creating an instance of the class.

### 1 Static Member Variables
Static member variables are declared inside the class with the static keyword and must be defined outside the class.

**'static' means that there is only one copy of the variable shared across all instances of the class, regardless of how many objects are created. It belongs to the class itself, not to any specific object of the class**.

So a static variable in a class means that all instances (objects) of that class share the same copy of the variable.
If you change the value of a static variable in one instance of the class, the change will be reflected in all other instances of the class.

- **Scope:** Shared across all instances of a class.
- **Lifetime:** Exists for the duration of the program, similar to static local variables.

**Initialization:**
To initialize a static member variable in C++, you need to follow a specific process. Here's a step-by-step guide on how to do it:
- Declare the Static Member Variable in the Class Definition: This is done in the class definition in the header file (.h or .hpp).
- Define the Static Member Variable in a .cpp File: This is done outside the class definition in a .cpp file where the static member is actually given a value.
```C++
//MyClass.h: In the header file, you declare the static member variable within the class.
#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
public:
    // Static member variable declaration
    static int staticValue;

    // other members
};
#endif // MYCLASS_H


/*************************************************/


//MyClass.cpp: In the source file, you define the static member variable and implement the static member functions.
#include <iostream>
#include "MyClass.h"

using namespace std;

// Definition and initialization of the static member variable
int MyClass::staticValue = 0;

//...
```

**Static Member Variables example**
```C++
#include <iostream>
using namespace std;

class MyClass {
public:
    // Static member variable
    static int staticValue;

    void showValue() const {
        cout << "Static Value: " << staticValue << endl;
    }
};

// Definition of the static member variable (*note: I need to specified the type)
int MyClass::staticValue = 0;

int main() {
    MyClass obj1, obj2;
    
    // Modify static member variable through one object
    obj1.staticValue = 10;
    
    // Access static member variable through another object
    obj2.showValue(); // Outputs: Static Value: 10

    return 0;
}
```
#### *Note: Why do you need to write the type in the definition?
- Inside the class, static int myStaticVar; is a declaration. It tells the compiler that the class has a static variable, but it doesn't allocate memory or provide an initial value.
- Outside the class, when you write int MyClass::myStaticVar = 42;, this is the definition. In C++, definitions must specify the type to allocate memory for the static variable and optionally provide an initial value.

### 2 Static Member Functions
Note: In a non member function i can't use the "this" ketword
```C++
#include <iostream>
using namespace std;

class MyClass {
private:
    static int staticValue;

public:
    static void setStaticValue(int value) {
        staticValue = value;
    }

    static void showStaticValue() {
        cout << "Static Value: " << staticValue << endl;
    }
};

// Definition of the static member variable
int MyClass::staticValue = 0;

int main() {
    // Set and show static value using static member functions
    MyClass::setStaticValue(100);
    MyClass::showStaticValue(); // Outputs: Static Value: 100

    return 0;
}
```
In this example, setStaticValue and showStaticValue are static member functions. They can be called using the class name without creating an instance.

### Summary
- **Static Global Variables and Functions:** static global variables and functions are limited to the file where they are defined. They provide encapsulation and prevent naming conflicts.

- **Static Member Variables:** Belong to the class rather than any particular instance. They are shared among all instances of the class and must be defined outside the class declaration.

- **Static Member Functions:** Can be called without creating an instance of the class. They can only access static member variables and functions.

***

## REFERENCE (&)
A **reference** is an alternative name, or alias, for an already existing variable. It allows you to work with that variable using a different identifier, without making a copy of it. References are very useful for modifying function parameters, avoiding unnecessary copying of large objects, and making code more efficient.

## Basic Syntax
To create a reference in C++, you use the **&** symbol. Here’s the basic syntax:
```C++
int original = 10;
int &ref = original;  // 'ref' is now a reference to 'original'
```
In this example, ref is a reference to the variable 'original'. Any operation on ref will affect original directly because ref is just another name for 'original'.

## Key Characteristics of References
- 1. **Must be initialized:** A reference must be initialized when it is created.
  You cannot declare a reference without assigning it to an existing variable.
  ```C++
  int &ref; // Error: reference must be initialized
  ```
- 2. **Cannot be reassigned:** Once a reference is initialized to a variable, it
  cannot be changed to refer to another variable.
  ```C++
  int a = 5;
  int b = 10;
  int &ref = a;  // 'ref' refers to 'a'
  ref = b;       // This does not change 'ref' to refer to 'b', it simply assigns the value of 'b' to 'a'
  ```
  - 3. **Aliasing:** References allow you to alias a variable, making your code
    cleaner, especially in function parameters and return values.

## References in Functions
One of the most common uses of references in C++ is in function parameters. They allow you to modify the arguments passed to a function or avoid copying large objects.

#### Example 1: Modifying Function Parameters
```C++
void increment(int &value) {
    value++;
}

int main() {
    int num = 10;
    increment(num);  // 'num' will be 11 after this call
    return 0;
}
```
Here, the increment function takes a reference to an integer. The function increments the value of num directly because value is a reference to num.

#### Example 2: Avoiding Copies
```C++
void printVector(const std::vector<int> &vec) {
    for (int i : vec) {
        std::cout << i << " ";
    }
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    printVector(numbers);  // No copy of 'numbers' is made
    return 0;
}
```
Here, printVector takes a const reference to a vector. The const keyword ensures that the function cannot modify the vector, and using a reference avoids copying the entire vector.

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
In general, references are preferred when you don't need the flexibility that pointers provide, as they are safer and less error-prone.

### Summary
- A reference is an alias for another variable.
- It must be initialized when created and cannot be changed to refer to another variable.
- References are commonly used in function parameters to modify arguments or avoid copying large objects.
- They provide a simpler and safer alternative to pointers in many cases.

***

## POINTERS TO MEMBERS
In C++, pointers to members are a special type of pointer that point to non-static members of a class (both member functions and member variables). Unlike regular pointers that point to an address in memory, pointers to members refer to a specific member within the context of an instance of a class.

## 1.Pointers to Member Variables
A *pointer to a member variable* refers to a data member of a class. It's not a regular pointer to memory but **requires an instance of the class** to be used.

### Syntax
```C++
class MyClass {
public:
    int value;
};

// Declare a pointer to the member 'value' of MyClass
int MyClass::* ptrToMember = &MyClass::value;

// Using the pointer with an instance
MyClass obj;
obj.value = 10;

std::cout << obj.*ptrToMember << std::endl;  // Outputs 10
```
- MyClass::* means "pointer to a member of MyClass."
- The **&MyClass::value** initializes the pointer to the specific member variable.
- To access the member via the pointer, you use obj.*ptrToMember or ptr->*ptrToMember if using a pointer to the object.

## 2.Pointers to Member Functions
Pointers to member functions point to a function inside a class, but they also **require an instance of the class** to call the function.

### Syntax
```C++
class MyClass {
public:
    void display() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

// Declare a pointer to the member function 'display' of MyClass
void (MyClass::*ptrToFunction)() = &MyClass::display;

// Using the pointer with an instance
MyClass obj;
(obj.*ptrToFunction)();  // Outputs: Hello from MyClass!
```
- **void (MyClass::*)()** is a pointer to a member function of MyClass that takes no parameters and returns void.
- The syntax to invoke the function through the pointer is **obj.*ptrToFunction()**.

## 3.Pointers to an Object
```C++
MyClass* objPtr = &obj;
(objPtr->*ptrToFunction)();  // Outputs: Hello from MyClass!
```

### Why Pointers to Members are Different
- **Pointer to data members:**A pointer to a data member doesn't directly refer to a specific memory location. Instead, it's an offset from the start of a class instance. You can't directly dereference it like a normal pointer.
- **Pointer to member functions:**Since member functions can depend on the object instance (due to this), a pointer to a member function can't be called directly like a normal function pointer. It always requires an instance of the class to bind the function to.

### Use Cases
-**Callbacks in classes:**Pointers to member functions are often used to define callbacks inside classes where different objects might behave differently.
-**Dynamic behavior:**You can dynamically decide which member variable or function to access at runtime, which is useful for creating flexible and extensible designs.

#### Example with both types of pointers:
```C++
class MyClass {
public:
    int value;
    
    void printValue() {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    // Pointer to member variable
    int MyClass::*ptrToVar = &MyClass::value;
    
    // Pointer to member function
    void (MyClass::*ptrToFunc)() = &MyClass::printValue;
    
    // Create an instance
    MyClass obj;
    obj.value = 42;
    
    // Access member variable via pointer
    std::cout << "Member variable value: " << obj.*ptrToVar << std::endl;
    
    // Call member function via pointer
    (obj.*ptrToFunc)();
    
    return 0;
}
```

***

## STD::VECTOR 
https://cplusplus.com/reference/vector/vector/

**std::vector** is a dynamic array provided by the C++ Standard Library, part of the container classes in the std namespace. It allows you to store and manipulate a sequence of elements in a contiguous memory block. Unlike regular arrays, std::vector automatically resizes itself as needed when elements are added or removed, making it much more flexible and easier to use.

## Key Features of std::vector:
### 1. Dynamic Size:
- Unlike arrays, which have a fixed size, vectors can grow or shrink dynamically as elements are added or removed.
```C++
numbers.push_back(10);  // Adds 10 to the end of the vector without specify the size of the vector upfront
```
### 2. Contiguous Memory:
- Elements are stored in contiguous memory locations, making random access (via the [] operator or at() method) very efficient, similar to an array.
```C++
int firstNumber = numbers[0];  // Access the first element
```
### 3. Automatic Memory Management - Capacity and Size:
- When more elements are added, the vector automatically reallocates its memory and copies over the existing elements to the new larger memory block.
### 4. STL Compatibility:
- std::vector works seamlessly with other parts of the C++ Standard Template Library (STL), such as algorithms (e.g., std::sort, std::find), iterators, and range-based loops.
### 5. Efficient Insertion/Removal at the End:
- Adding or removing elements at the end (push_back and pop_back) is very efficient (amortized constant time, O(1)), but inserting or removing elements in the middle or front takes linear time (O(n)).

## Declaration
To declare a vector, you use the std::vector template class and specify the type of elements it will store. For example:
```C++
#include <vector>

std::vector<int> numbers;  // Vector of integers
std::vector<std::string> names;  // Vector of strings
```

## Constructor
### 1. Default Constructor
```C++
std::vector<T> v;
```
Creates an empty vector.
**example**
```C++
std::vector<int> v; // An empty vector of integers
```

### 2. Fill Constructor
```C++
std::vector<T> v(size_type count);
std::vector<T> v(size_type count, const T& value);
```
- The first form creates a vector with count default-initialized elements (for integers, it will be 0; for custom types, the default constructor is called).
- The second form creates a vector with count copies of value.
**example**
```C++
std::vector<int> v(5); // A vector with 5 integers, all initialized to 0
std::vector<int> v2(5, 10); // A vector with 5 integers, all initialized to 10
```

### 3. Range Constructor
```C++
template <class InputIt>
std::vector<T> v(InputIt first, InputIt last);
```
- **InputIt first**: An iterator pointing to the first element in the range to copy/move
- **InputIt last**: An iterator pointing just past the last element in the range to copy/move (exclusive).
Creates a vector and initializes it with elements from the range [first, last). The range is typically defined by two iterators.
**example**
```C++
int arr[] = {1, 2, 3, 4, 5};
std::vector<int> v(arr, arr + 5); // A vector with elements from the array arr
```

### 4. Copy Constructor
```C++
std::vector<T> v(const std::vector<T>& other);
```
Creates a new vector as a copy of the existing vector other.
**example**
```C++
std::vector<int> v1 = {1, 2, 3};
std::vector<int> v2(v1); // A vector that is a copy of v1
```

### 5. Move Constructor
```C++
td::vector<T> v(std::vector<T>&& other);
```
Moves the contents of other into the new vector. After the move, other is left in a valid but unspecified state (typically, other will be empty).
**example**
```C++
std::vector<int> v1 = {1, 2, 3};
std::vector<int> v2(std::move(v1)); // v1 is now empty, and v2 has the contents of v1
```

## Common Methods:
- **push_back()**: Add an element at the end.
- **pop_back()**: Remove the last element.
- **Capacity and Size**:std::vector has both size and capacity. Size is the number of elements in the vector, while capacity is the amount of memory allocated, which may be larger than the current size to allow for future growth.
```C++
std::cout << numbers.size();     // Number of elements in the vector
std::cout << numbers.capacity(); // Memory allocated for the vector
```
- **Resize**: You can resize the vector explicitly using the resize() method. 
```C++
numbers.resize(5);  // Resizes the vector to contain 5 elements
```
- **clear()**: Remove all elements from the vector.
- **empty()**: Check if the vector is empty.
- **at(index)**: Access element at a specific position with bounds checking.

## Iterators
In C++, std::vector provides several types of iterators, which allow you to traverse or modify elements within the vector. These iterators are similar to pointers in their syntax, but they have special behaviors designed for working with containers like std::vector.

A normal iterator starts at the beginning of the vector and moves forward through the elements.
- **begin()**: Returns an iterator to the first element.
- **end()**: Returns an iterator to the position after the last element.

#### example
```C++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Using a normal iterator
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
```

***

## STD::FOR_EACH
 is a standard algorithm in the C++ Standard Library that applies a specified function or operation to each element in a range of elements (typically from a container like a vector, array, list, etc.).

 ```C++
std::for_each(first, last, function);
```

### parameters
- first: An iterator to the first element of the range.
- last: An iterator to one-past the last element of the range.
- function: A function (or function object, or lambda expression) to apply to each element in the range.

***

## STD::MEM_FUN_REF
### Explanation of a Function Adapter
A function adapter is a utility in the C++ Standard Library that transforms functions or member functions into function objects (also known as functors). This allows functions (or member functions) to be passed as arguments to algorithms like std::for_each, which expect a function object.

## Understanding std::mem_fun_ref
std::mem_fun_ref is a function adapter that wraps a member function of a class so that it can be used as a function object. This was useful in C++98/03, where algorithms like std::for_each required function objects (like functors or pointers to functions), but couldn't directly accept member function pointers.

Was used to call a member function of a class on each object in a collection as if it were a normal function.Example Without std::mem_fun_ref

The std::mem_fun_ref function template takes a member function pointer as its parameter. Here’s the signature focusing on the parameters:
```C++
template <class T>
std::mem_fun_ref<T> mem_fun_ref(T (X::*f)());
```
- T: The return type of the member function.
- X: The class type to which the member function belongs.
- f: A pointer to a member function of type T (X::*)(), which means it points to a member function that takes no parameters and returns T.

The return type of std::mem_fun_ref is a functor (a callable object) that allows you to call the specified member function on an instance of the class.

#### Example Without std::mem_fun_ref
Imagine you have a class Person with a member function greet() that prints a message:
```C++
#include <iostream>

class Person {
public:
    void greet() const {
        std::cout << "Hello!" << std::endl;
    }
};

int main() {
    Person p;
    p.greet();  // Direct call to greet()
    return 0;
}
```
In this case, you are directly calling the greet() method on the object p.

#### Using a Vector of Objects
If you have a vector of Person objects and you want to call the greet() method on each element, you cannot simply pass the function as if it were a global function:
```C++
#include <iostream>
#include <vector>

class Person {
public:
    void greet() const {
        std::cout << "Hello!" << std::endl;
    }
};

int main() {
    std::vector<Person> people(3);  // A vector of 3 Person objects
    
    // You cannot do this:
    // std::for_each(people.begin(), people.end(), greet);
    
    return 0;
}
```

#### Example using std::mem_fun_ref
With std::mem_fun_ref, you can create a functor that automatically calls the member function greet() for each object in the vector:
```C++
#include <iostream>
#include <vector>
#include <algorithm>  // For std::for_each
#include <functional> // For std::mem_fun_ref

class Person {
public:
    void greet() const {
        std::cout << "Hello!" << std::endl;
    }
};

int main() {
    std::vector<Person> people(3);  // A vector of 3 Person objects
    
    // Call greet() on each person in the vector
    std::for_each(people.begin(), people.end(), std::mem_fun_ref(&Person::greet));
    
    return 0;
}
```
- std::mem_fun_ref(&Person::greet) creates a functor (a callable function object) that calls greet() on each Person object in the vector.
- std::for_each applies this functor to all the objects in the people vector.

#### Summary:
Think of std::mem_fun_ref as "converting" the member function greet into a function that can be applied to all the objects in a collection as if it were a regular function.
##### 1.Member Function Context:
In C++, member functions are associated with a specific class and require an instance of that class (an object) to be invoked. For example, calling obj.displayStatus() requires obj to be an instance of a class that has the displayStatus member function.

##### 2. Using Standard Algorithms:
Standard algorithms like std::for_each expect a callable object (e.g., a function pointer, lambda, or functor) that can be invoked without needing to know about the specific class or instance. However, a member function cannot be used directly as a standalone function pointer.

##### 3. Wrapping:
When you use std::mem_fun_ref, it "wraps" the member function pointer (&Account::displayStatus) in a functor that can be called without directly needing an instance of Account. Instead, the functor can be applied to each Account object in a collection during the iteration.
("wraps the member function" refers to the process of creating a callable object (like a functor))

***

## STD::PAIR
std::pair is a utility from the Standard Library that allows you to store and work with **two values as a single unit**. These values can be of different types, and std::pair is useful when you want to **group two related pieces of data together**.

### How std::pair Works:
A std::pair holds **two values** (referred to as first and second), which can be **of any type**. It’s often used in situations where you need to **return two values from a function, or when working with key-value pairs** (e.g., in std::map).

### Declaring a std::pair
To declare a std::pair, you specify the types of the two values it holds. For example:
```C++
#include <utility>  // Required for std::pair
#include <iostream>

int main() {
    // Declare a pair holding an int and a string
    std::pair<int, std::string> myPair;

    // Assign values to the pair
    myPair.first = 1;
    myPair.second = "Hello";

    // Accessing the values
    std::cout << "First: " << myPair.first << ", Second: " << myPair.second << std::endl;

    return 0;
}
```

### Creating and Initializing a std::pair
There are different ways to create and initialize a std::pair:
- **Default Constructor**:Creates a pair with default-initialized values.
```C++
std::pair<int, std::string> myPair;  // Default constructor
```
- **Constructor with Values**:You can initialize both values in the constructor.
```C++
std::pair<int, std::string> myPair(1, "Hello");
```
- **Using std::make_pair()**:This function creates a pair without having to specify the types explicitly. The types are inferred from the arguments.
```C++
auto myPair = std::make_pair(1, "Hello");
```

### Accessing Elements in a std::pair
- **first**:Refers to the first element in the pair.
- **second**:Refers to the second element in the pair.
```C++
std::pair<int, std::string> myPair(1, "Hello");

std::cout << myPair.first;   // Outputs: 1
std::cout << myPair.second;  // Outputs: Hello
```

### Example Use Cases of std::pair
#### Returning Multiple Values from a Function
You can return two related values (e.g., a result code and a value) from a function using std::pair.
```C++
std::pair<int, std::string> getResult() {
    return std::make_pair(200, "OK");
}

int main() {
    auto result = getResult();
    std::cout << "Code: " << result.first << ", Message: " << result.second;
    return 0;
}
```

#### Key-Value Pairs (Common in Maps)
In std::map, keys and values are stored as std::pair. The first value in the pair is the key, and the second is the value.
```C++
std::map<int, std::string> myMap;
myMap.insert(std::make_pair(1, "Apple"));
```














***

# C++ PROJECT GUIDELINES

## 1. Compilation
- Compile your code with `c++` and the flags `-Wall`, `-Wextra`, `-Werror`:
- Your code must still compile if you add the flag `-std=c++98`:

## 2. Formatting and Naming Conventions
- The exercise directories must be named as follows: `ex00`, `ex01`, ..., `exn`:

- Name your files, classes, functions, member functions, and attributes according to the guidelines

- Write class names in **UpperCamelCase** format

- Files containing class code must be named according to the class name:
  - If you have a class named `BrickWall`, the corresponding files should be `BrickWall.hpp` (or `.h` for the header) and `BrickWall.cpp` for the implementation.

- Unless otherwise specified, all output messages must end with a newline character and be displayed to the standard output

- No specific coding style is enforced (unlike **Norminette** in C)

## 3. Allowed/Forbidden
- **You are not coding in C anymore; it’s time for C++**:
  - You must use C++ features instead of sticking to what you already know from C.

- You can use almost everything from the **C++ Standard Library**:
  - It’s allowed to use the C++ Standard Library (e.g., strings, streams, etc.).

- **External libraries are not allowed**:
  - You cannot use external libraries outside of the C++ Standard Library. Specifically, **C++11** (and later versions) and **Boost libraries** are forbidden.

- The following functions are forbidden: `*printf()`, `*alloc()`, and `free()`

## 4. C++ Concepts
- **Namespaces, classes, member functions, input/output streams (stdio), initialization lists, static, const, and other basic C++ concepts**:

- The keywords `using namespace <namespace_name>` and `friend` are forbidden:
  - You cannot use `using namespace` to avoid naming conflicts, nor can you use `friend` to gain direct access to private members of a class.

- You can only use the **STL** (Standard Template Library) in **modules 08 and 09**:
  - Until modules 08 and 09, you are **not allowed** to use containers like `vector`, `list`, `map`, or algorithms included in the `<algorithm>` header. If you use them before these modules, you will receive a grade of **-42**.

## 5. Design Requirements
- **Memory leaks occur in C++ too**:
  - When you allocate memory using `new`, you must properly deallocate it (using `delete`) to avoid memory leaks.

- From **module 02 to module 09**, your classes must follow the **Orthodox Canonical Form**:
  - This means your classes must implement the following "big four" methods: a default constructor, copy constructor, assignment operator, and destructor.

- **Placing function implementations in a header file** (except for templates) will result in a score of 0 for the exercise:
  - Functions must be implemented in `.cpp` files, not in header (`.hpp`) files unless they're template functions.

- Each header must be usable independently of others:
  - Your `.hpp` files must include all necessary dependencies and use include guards (or `#pragma once`) to avoid double inclusions. If an include guard is missing, the exercise will receive a grade of 0.

