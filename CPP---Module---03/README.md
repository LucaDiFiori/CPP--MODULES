# CPP---Module---03
This module is designed to help you understand Inheritance in CPP.

***

# C++ BASICS 03

***

# Table of Contents
- [INHERITANCE](#inheritance)
- [KEY CONCEPTS OF INHERITANCE](#key-concepts-of-inheritance)
- [BASIC SYNTAX OF INHERITANCE](#basic-syntax-of-inheritance)
- [ACCESS SPECIFIER AND ITS EFFECT ON INHERITANCE](#access-specifier-and-its-effect-on-inheritance)
	- [public inheritance](#public-inheritance)
	- [protected inheritance](#protected-inheritance)
	- [private inheritance](#private-inheritance)
- [TYPES OF INHERITANCE](#types-of-inheritance)
	- [Single Inheritance](#single-inheritance)
	- [Multiple Inheritance](#multiple-inheritance)
	- [Multilevel Inheritance](#multilevel-inheritance)
	- [Hierarchical Inheritance](#hierarchical-inheritance)
	- [Hybrid Inheritance](#hybrid-inheritance)
- [CONSTRUCTORS AND DESTRUCTORS IN INHERITANCE](#constructors-and-destructors-in-inheritance)
	- [Example with Parameterized Constructors](#example-with-parameterized-constructors)
- [ACCESSING BASE CLASS MEMBERS](#accessing-base-class-members)
- [VIRTUAL INHERITANCE](#virtual-inheritance)
- [CONSTRUCTORS AND INHERITANCE ORDER](#Constructors-and-Inheritance-Order)

***

# INHERITANCE
Inheritance is a fundamental concept in object-oriented programming (OOP) that **allows a new class** (called the **derived class** or **child class**) **to inherit properties and behaviors (data members and member functions) from an existing class** (called the base class or **parent class**). This promotes code reusability, hierarchical classification, and the creation of more complex data models.

In C++, inheritance enables the creation of a new class based on an existing class, extending or modifying its functionality. Below is a comprehensive explanation of inheritance in C++, including types, syntax, access specifiers, and practical examples.


## KEY CONCEPTS OF INHERITANCE
- **Base Class (Parent Class)**: The class whose properties and methods are inherited.

- **Derived Class (Child Class)**: The class that inherits properties and methods from the base class.

- **Access Specifiers**: Control the accessibility of the base class members in the derived class. The main access specifiers are **public**, **protected**, and **private**.

- **Types of Inheritance**: Different ways to inherit from base classes, such as single, multiple, multilevel, hierarchical, and hybrid inheritance.

- **Overriding and Virtual Functions**: Mechanisms to modify or extend inherited behavior.


## BASIC SYNTAX OF INHERITANCE
```C++
class BaseClass {
public:
    // Members of the base class
};

class DerivedClass : accessSpecifier BaseClass {
    // Members of the derived class
};
```
- **accessSpecifier** can be **public**, **protected**, or **private**, determining how the base class members are accessed in the derived class.

***

## ACCESS SPECIFIER AND ITS EFFECT ON INHERITANCE
In C++, when you inherit from a base class using public, protected, or private, it affects how the members of the base class are inherited and accessed in the derived class.

### Public inheritance
- **Public members** of the base class **remain public** in the derived class.
- **Protected members** of the base class **remain protected** in the derived class.
- **Private members** of the base class **remain private** and are **not accessible directly in the derived class**.

### Protected inheritance
- **Public members** of the base class **become protected** in the derived class
- **Protected members** of the base class **remain protected** in the derived class
- **Private members** of the base class **remain private** and are not accessible directly in the derived class.

### Private inheritance
- **Public members** of the base class **become private** in the derived class.
- **Protected members** of the base class **become private** in the derived class.
- **Private members** of the base class **remain private** and are not accessible directly in the derived class

#### Example
```C++
#include <iostream>
using namespace std;

class Base {
public:
    void publicMethod() { cout << "Public Method\n"; }
protected:
    void protectedMethod() { cout << "Protected Method\n"; }
private:
    void privateMethod() { cout << "Private Method\n"; }
};

class DerivedPublic : public Base {
public:
    void accessMethods() {
        publicMethod();      // Accessible
        protectedMethod();   // Accessible
        // privateMethod();  // Not accessible
    }
};

class DerivedProtected : protected Base {
public:
    void accessMethods() {
        publicMethod();      // Accessible as protected
        protectedMethod();   // Accessible
        // privateMethod();  // Not accessible
    }
};

class DerivedPrivate : private Base {
public:
    void accessMethods() {
        publicMethod();      // Accessible as private
        protectedMethod();   // Accessible as private
        // privateMethod();  // Not accessible
    }
};

int main() {
    DerivedPublic dp;
    dp.publicMethod();          // Accessible

    // DerivedProtected and DerivedPrivate do not expose Base's public methods
    // directly because of inheritance type.
    // DerivedProtected dp2;
    // dp2.publicMethod();      // Error

    return 0;
}
```

***

## TYPES OF INHERITANCE
## Single Inheritance
A derived class inherits from only one base class.
```C++
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food.\n";
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "The dog barks.\n";
    }
};

int main() {
    Dog myDog;
    myDog.eat();  // Inherited from Animal
    myDog.bark();
    return 0;
}
```

**Output**
```BASH
This animal eats food.
The dog barks.
```

## Multiple Inheritance
A derived class inherits from more than one base class.
```C++
#include <iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "Engine starts.\n";
    }
};

class Wheels {
public:
    void roll() {
        cout << "Wheels roll.\n";
    }
};

class Car : public Engine, public Wheels {
public:
    void drive() {
        cout << "Car drives.\n";
    }
};

int main() {
    Car myCar;
    myCar.start();  // From Engine
    myCar.roll();   // From Wheels
    myCar.drive();
    return 0;
}
```

**Output**
```BASH
Engine starts.
Wheels roll.
Car drives.
```

## Multilevel Inheritance
A derived class inherits from another derived class, forming a hierarchy.
```C++
#include <iostream>
using namespace std;

class Vehicle {
public:
    void move() {
        cout << "Vehicle moves.\n";
    }
};

class Car : public Vehicle {
public:
    void honk() {
        cout << "Car honks.\n";
    }
};

class SportsCar : public Car {
public:
    void turboBoost() {
        cout << "SportsCar uses turbo boost.\n";
    }
};

int main() {
    SportsCar mySportsCar;
    mySportsCar.move();       // From Vehicle
    mySportsCar.honk();       // From Car
    mySportsCar.turboBoost();
    return 0;
}
```

**Output**
```BASH
Vehicle moves.
Car honks.
SportsCar uses turbo boost.
```

## Hierarchical Inheritance
Multiple derived classes inherit from a single base class.
```c++
#include <iostream>
using namespace std;

class Shape {
public:
    void display() {
        cout << "Displaying shape.\n";
    }
};

class Circle : public Shape {
public:
    void drawCircle() {
        cout << "Drawing circle.\n";
    }
};

class Square : public Shape {
public:
    void drawSquare() {
        cout << "Drawing square.\n";
    }
};

int main() {
    Circle c;
    Square s;
    c.display();
    c.drawCircle();
    s.display();
    s.drawSquare();
    return 0;
}
```

**Output**
```BASH
Displaying shape.
Drawing circle.
Displaying shape.
Drawing square.
```

## Hybrid Inheritance
Combination of two or more types of inheritance (e.g., multiple and multilevel).

**Note**: Hybrid inheritance can lead to ambiguity problems, especially with multiple inheritance. C++ provides the virtual keyword to resolve such issues (discussed later).

***

## CONSTRUCTORS AND DESTRUCTORS IN INHERITANCE
When a derived class object is created, **the base class constructor is called first**, **followed by the derived class constructor**. Conversely, when the object is destroyed, **the derived class destructor is called first, followed by the base class destructor**.

**Example**
```C++
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    ~Base() { cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor\n"; }
    ~Derived() { cout << "Derived Destructor\n"; }
};

int main() {
    Derived obj;
    return 0;
}
```

**Output**
```BASH
Base Constructor
Derived Constructor
Derived Destructor
Base Destructor
```

### Important Points:
- **Default Constructors**: If no constructor is defined in the derived class, the base class's default constructor is automatically called.
- **Parameterized Constructors**: You can call a specific base class constructor using an initializer list.

## Example with Parameterized Constructors:
```C++
#include <iostream>
using namespace std;

class Base {
public:
    // Parameterized constructor of Base class
    Base(int x) {
        cout << "Base Constructor with x = " << x << "\n";
    }
};

class Derived : public Base {
public:
    // Parameterized constructor of Derived class
    // : Base(x) means we're calling the Base class constructor with the argument x
    Derived(int x, int y) : Base(x) {
        cout << "Derived Constructor with y = " << y << "\n";
    }
};

int main() {
    // Creating an object of the Derived class with values 10 and 20
    Derived obj(10, 20);
    return 0;
}
```

**Output**
```BASH
Base Constructor with x = 10
Derived Constructor with y = 20
```

- The class Base has a parameterized constructor that accepts an integer x. When an object of Base is created, it prints a message with the value of x passed to it.
```C++
Base(int x) {
    cout << "Base Constructor with x = " << x << "\n";
}
```

- The class Derived inherits from Base. Its constructor accepts two integers, x and y.
- The syntax : Base(x) in the constructor of Derived calls the Base class constructor with the argument x. This initializes the Base part of the Derived object before the Derived constructor runs its own code.

```C++
Derived(int x, int y) : Base(x) {
    cout << "Derived Constructor with y = " << y << "\n";
}
```

- When you create an object of the Derived class with Derived obj(10, 20);, the following happens:
	- The Base class constructor is called first with x = 10.
	- After that, the Derived class constructor is called with y = 2

***

## ACCESSING BASE CLASS MEMBERS
A derived class can access base class members based on their access specifiers.
- **Public Members**: Accessible directly using member functions or objects (if accessible).
- **Protected Members**: Accessible within derived classes but not outside.
- **Private Members**: Not accessible directly in derived classes; require public or protected member functions in the base class to access them.
```C++
#include <iostream>
using namespace std;

class Base {
private:
    int privateVar;
protected:
    int protectedVar;
public:
    int publicVar;

    Base() : privateVar(1), protectedVar(2), publicVar(3) {}

    void showPrivate() { cout << "PrivateVar: " << privateVar << "\n"; }
};

class Derived : public Base {
public:
    void display() {
        // cout << privateVar; // Error: privateVar is not accessible
        cout << "ProtectedVar: " << protectedVar << "\n"; // Accessible
        cout << "PublicVar: " << publicVar << "\n";       // Accessible
    }
};

int main() {
    Derived d;
    // d.protectedVar; // Error: protectedVar is not accessible outside
    // d.privateVar;   // Error: privateVar is not accessible
    d.publicVar = 10;
    d.display();
    d.showPrivate(); // Accessible through public member function

    return 0;
}
```
**Output**
```BASH
ProtectedVar: 2
PublicVar: 10
PrivateVar: 1
```

***

## VIRTUAL INHERITANCE
Virtual inheritance is a technique used in C++ to prevent the diamond problem in multiple inheritance. The diamond problem occurs when a class inherits from two classes that both inherit from a common base class, resulting in the base class being duplicated in the derived class.

### The Diamond Problem (Without Virtual Inheritance)
Consider this common multiple inheritance scenario:
```C++
class A {
public:
    void show() { cout << "Class A\n"; }
};

class B : public A {};  // B inherits from A
class C : public A {};  // C also inherits from A

class D : public B, public C {};  // D inherits from both B and C
```
In this case, class D inherits from both B and C, and since both B and C inherit from A, this leads to two copies of A inside D. This duplication causes ambiguity when trying to access members of A through D.

For example:
```C++
int main() {
    D obj;
    obj.show();  // Error: Ambiguity, compiler doesn't know which show() to call
}
```
Here, the compiler cannot determine whether to call the show() function from A through B or through C, leading to an ambiguity.

### Solution: Virtual Inheritance
To solve the diamond problem, you can use virtual inheritance. This ensures that only one instance of the common base class (A in this case) is shared among all the classes in the inheritance chain.
```C++
#include <iostream>
using namespace std;

class A {
public:
    int value;
};

// Use virtual inheritance to prevent multiple copies of A
class B : virtual public A {};  // B virtually inherits from A
class C : virtual public A {};  // C virtually inherits from A

class D : public B, public C {};  // D inherits from both B and C

int main() {
    D obj;
    obj.value = 30; // Unambiguous
    cout << "A::value = " << obj.value << "\n";
    return 0;
}
```
Now, when B and C inherit from A using virtual inheritance, D will have only one instance of A, shared between B and C. This eliminates the ambiguity and avoids the duplication of A.

When D calls show(), there is no ambiguity, and the program knows to call A::show() because only one instance of A exists in D 

### Note:
- **Base Class Constructor using virtual**: When an object of the derived class (e.g. D) is created, the base class constructor (A) is called only once, regardless of how many inheritance paths lead to it. This simplifies the management of the base class state.
- Virtual inheritance must be applied to derived classes (B,C) that directly inherit from the common base class (A) to resolve the "diamond problem." 
It is not necessary to declare virtual inheritance in the class that inherits from these derived classes (D) because the virtual inheritance has already been resolved upstream.

***

## CONSTRUCTORS AND INHERITANCE ORDER
When dealing with inheritance, understanding the order in which constructors and destructors are called is essential, especially in multiple inheritance scenarios.

## Order of Constructor Calls:
- **Virtual Base Classes**: If virtual inheritance is used, virtual base classes are initialized first, regardless of the order in which they appear in the derived class.
- **Non-Virtual Base Classes**: Initialized in the order they are inherited.
- **Derived Class**: Finally, the derived class constructor is executed.

## Order of Constructor Calls:
Destructors are called in the reverse order of constructors.
