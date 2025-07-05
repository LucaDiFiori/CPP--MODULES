# CPP---Module---04
This module is designed to help you understand Subtype polymorphism, abstract classes and interfaces in CPP.

***

# C++ BASICS 04

***

# Table of Contents
- [SUBTYPE POLYMORPHISM (Overriding member functions): VIRTUAL](#subtype-polymorphism-(overriding-member-functions)-virtual)
	- [Polymorphism Overview](#polymorphism-overview)
	- [Understanding Subtype Polymorphism](#understanding-subtype-polymorphism)
	- [Implementation in C++](#Implementation-in-c++)
	- [Key Concepts and Mechanisms](#key-concepts-and-mechanisms)
		- [1. Virtual Functions](#1-virtual-functions)
		- [2. Dynamic Binding](#1-dynamic-binding)
		- [3. Base and Derived Classes](#3-base-and-derived-classes)
		- [4. Virtual Destructors](#6-virtual-destructors)
	- [Practical Examples](#pratical-examples)
- [ABSTRACT CLASSES AND INTERFACES](#abstract-classes-and-interfaces)
    - [ABSTRACT CLASSES](#abstract-classes)
        - [Key Characteristics](#key-characteristics)
    - [INTERFACES](#interfaces)
        - [Characteristics of an Interface](#characteristics-of-an-interface)
        - [Example of an Interface](#example-of-an-interface)
        - [Implementing Interfaces](#Implementing-nterfaces)
    - [DIFFERENCES BETWEEN ABSTACT CLASSES AND INTERFACES](#Differences-Between-Abstract-Classes-and-Interfaces)
- [SHALLOW COPY vs DEEP COPY](#shallow-copy-vd-deep-copy)
    - [Shallow Copy](#shallow-copy)
    - [Deep Copy](#deep-copy)
    - [Testing for Deep Copies](#testing-for-deep-copies)

***
***

# SUBTYPE POLYMORPHISM (Overriding member functions): VIRTUAL
Subtype polymorphism **allows objects of different types to be treated uniformly based on a shared base type**. In C++, subtype polymorphism is primarily achieved through **inheritance** and **virtual functions**, enabling dynamic (run-time) behavior.

Usefull Video: https://www.youtube.com/watch?v=4NPOIaUxnnk&ab_channel=ProfessorHankStalica



## Polymorphism Overview
**Polymorphism** allows entities like functions or objects to take on multiple forms. In C++, polymorphism is categorized into:

- **Compile-Time (Static) Polymorphism**: Achieved via **function overloading** and templates. Resolved during compilation.
- **Run-Time (Dynamic) Polymorphism**: Achieved via **inheritance** and **virtual functions**. Resolved during program execution.

**Subtype Polymorphism** falls under run-time polymorphism, where a base class pointer or reference can refer to objects of derived classes.


## Understanding Subtype Polymorphism
**Subtype Polymorphism** allows a function to process objects differently based on 
their actual derived type, even when accessed through a base class interface. 
This is crucial for designing systems where behavior can be extended without 
modifying existing code.

**Key Characteristics**:
- **Inheritance**: Establishes an "is-a" relationship between base and derived classes.
- **Virtual Functions**: Enable derived classes to **override** base class methods.
- **Base Class Pointers/References**: Allow generic handling of different derived objects.


## Implementation in C++
To implement subtype polymorphism in C++, follow these steps:
- **Define a Base Class**: **Contains virtual functions** that derived classes can override.
- **Derive Subclasses**: Inherit from the base class and override virtual functions to provide specific behaviors.
- **Use Base Class Pointers/References**: Access derived objects through base class interfaces, enabling dynamic binding.

### Step-by-Step Example
#### 1. 42 example
Let's first see what would happen if I tried to implement this polymorphism 
without using the 'virtual' keyword.

- Base and Subclasse
```C++
// .hpp
#include <string>
#include <iostream> 

class Character
{
    public:
        void sayHello(std::string const& target);
};

class Warrior : public Character
{
    public:
        void sayHello(std::string const& target);
}
```

- methodos implementation
```C++
// .cpp
void Character::sayHello(std::string const& target)
{
    std::cout << "Hello" << target << " !" << std::endl;
}

void Warrior::sayHello(std::string const& target)
{
    std::cout << "F*** off" << target << " , iI don't like you!" << std::endl;
}
```

- main
``` C++
int main()
{
    Warrior* a = new Warrior();
    Character* b = new Warrior();

    a->sayHello("students");
    b->sayHello("studets");
}
```
**Notes**:
- **Character* b = new Warrior()**: This declares a pointer b to an object of type Character. 
It's important to note that b can point to any object that is a Character or derived from 
Character (like Warrior). 
The opposit (Warrior* c = new Character) is not possible

Output
```BASH
F*** off students, I don't like you !
Hello studets
``` 

- In the first case, a->sayHello("students") uses a pointer of type Warrior*. 
Since a is a pointer to a Warrior object, the sayHello method from the Warrior 
class is called without ambiguity, resulting in the output:
```BASH
F*** off students, I don't like you !
```
- In the second case, b->sayHello("studets") uses a pointer of type Character*. 
Even though b is initialized with a Warrior object, the sayHello method from the 
Character class is called because the method in Character is not marked as virtual. 
This results in the base class's method being used instead of the one in Warrior, 
and the output is:
```BASH
Hello studets
```

**Solution**
To solve this problem, I will use the virtual keyword to create dynamic binding between the classes
```C++
// .hpp
#include <string>
#include <iostream> 

class Character
{
    public:
        virtual void sayHello(std::string const& target);
};

class Warrior : public Character
{
    public:
        virtual void sayHello(std::string const& target);
}
// Note: we don't need to use "virtual" in the subclass
```
Output
```BASH
F*** off students, I don't like you !
F*** off students, I don't like you !
``` 

#### 2. Shape example
Consider a graphics application with different shapes (e.g., Circle, Rectangle). 
Each shape can be drawn, but the drawing process differs. 
Using subtype polymorphism, a single interface can handle various shapes seamlessly.

- a. **Define the Base Class**:
```C++
// Shape.h
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
public:
    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Shape() {}

    // Pure virtual function makes Shape an abstract class
    virtual void draw() const = 0;

    // Optional: Other virtual functions
    virtual double area() const = 0;
};

#endif // SHAPE_H
```
- **Virtual Destructor**: Ensures that when a derived object is deleted through a base class pointer, the derived class's destructor is called.
- **Pure Virtual Functions (= 0)**: Make Shape an abstract class, preventing direct instantiation. Derived classes must override these functions.

- b. **Derive Subclasses**:
```C++
// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <cmath>

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Override draw method (No 'override' keyword in C++98)
    virtual void draw() const {
        std::cout << "Drawing a Circle with radius " << radius << std::endl;
    }

    // Override area method
    virtual double area() const {
        return M_PI * radius * radius;
    }
};
#endif // CIRCLE_H
```
```C++
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Override draw method
    virtual void draw() const {
        std::cout << "Drawing a Rectangle with width " << width 
                  << " and height " << height << std::endl;
    }

    // Override area method
    virtual double area() const {
        return width * height;
    }
};

#endif // RECTANGLE_H
```
- **Inheritance**: Circle and Rectangle inherit publicly from Shape.
- **Override Keyword**: Ensures that the function is correctly overriding a base class virtual function.

- c. **Utilize Polymorphism**:
```C++
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

int main() {
    // Create Circle and Rectangle objects
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    // Use BASE CLASS Shape POINTERS for polymorphism  <------
    Shape* shape1 = &circle;
    Shape* shape2 = &rectangle;

    // Invoke the overridden methods
    shape1->draw();
    std::cout << "Area: " << shape1->area() << std::endl;

    shape2->draw();
    std::cout << "Area: " << shape2->area() << std::endl;

    return 0;
}
```
Output
```BASH
Drawing a Circle with radius 5
Area: 78.5398
Drawing a Rectangle with width 4 and height 6
Area: 24
```

***

## Key Concepts and Mechanisms
### 1. Virtual Functions
A **virtual function** is a member function in a base class that you expect to be overridden in derived classes. When a function is declared as virtual in the base class, C++ uses dynamic binding (also called late binding). This means that when you call the function through a pointer or reference to the base class, the derived class's version of the function will be invoked, if it exists.

- The **virtual keyword** is **only needed in the base class**. Even though derived classes override the function, you don't need to specify virtual again in the derived class (but you can for clarity).

```C++
virtual void functionName();
```

**Pure Virtual Functions**: 
- A pure virtual function is a special kind of virtual function that is declared in a base class with the = 0 syntax. This **makes the class an abstract class**, meaning it **cannot be instantiated** on its own, and any class that derives from it must provide an implementation for the pure virtual function. 
- (**Abstract class**: A class that contains at least one pure virtual function is considered an abstract class. This means you cannot create objects directly from that class. It's intended to serve as a base class for other classes to derive from.)
- The **= 0** at the end of the declaration tells the compiler that this function has no body in the base class and must be overridden in derived classes.
- **Mandatory Override**: Any class that inherits from the abstract class must provide a concrete implementation of the pure virtual function, otherwise it will also be considered abstract and cannot be instantiated.
- Pure virtual functions are essential in polymorphism, where base classes define a general **interface** (e.g., a Shape class with a pure virtual draw() method), and derived classes (e.g., Circle or Rectangle) provide specific behavior.


### 2. Dynamic Binding
Dynamic binding refers to the process where **the call to an overridden function is resolved at run-time based on the actual object type, not the pointer/reference type**.


### 3. Base and Derived Classes
- **Base Class**: The general class from which other classes inherit.
- **Derived Class**: A specialized class that inherits from the base class, potentially adding or modifying behaviors.

### 4. Virtual Destructors
Ensuring that destructors are virtual in base classes is critical for proper resource cleanup when deleting derived objects through base class pointers.
```C++
virtual ~Shape() {}
```

## Practical Examples
### Example 1: Animal Hierarchy
In this example, we will create an animal hierarchy to demonstrate subtype polymorphism.

- **a. Base Class**: The Animal class is an abstract class with a pure virtual function speak. The virtual destructor ensures that derived class destructors are called correctly.
```C++
// Animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
public:
    virtual ~Animal() {}  // Virtual destructor

    virtual void speak() const = 0;  // Pure virtual function
};

#endif // ANIMAL_H
```
- **b. Derived Classes**: The Dog and Cat classes inherit from Animal and override the speak method, providing their specific implementations.
```C++
// Dog.h
#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
    void speak() const {
        std::cout << "Woof!" << std::endl;
    }
};

#endif // DOG_H
```
```C++
// Cat.h
#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
    void speak() const {
        std::cout << "Meow!" << std::endl;
    }
};

#endif // CAT_H
```

- **b. Derived Classes**: The program utilizes a vector of raw pointers to Animal. Each animal is instantiated and added to the vector. During iteration, the correct speak method is called for each derived class.
```C++
// main.cpp
#include <iostream>
#include <vector>
#include <memory> // For smart pointers (only available in C++11 and later)

#include "Dog.h"
#include "Cat.h"

int main() {
    std::vector<Animal*> animals; // Using raw pointers instead of smart pointers

    animals.push_back(new Dog()); // Add a Dog
    animals.push_back(new Cat());  // Add a Cat
    animals.push_back(new Dog());  // Add another Dog

    // Iterate through the collection and call speak()
    for (size_t i = 0; i < animals.size(); ++i) {
        animals[i]->speak();
    }

    // Cleanup
    for (size_t i = 0; i < animals.size(); ++i) {
        delete animals[i]; // Manually delete each object
    }

    return 0;
}
```
Output
```BASH
Woof!
Meow!
Woof!
```

***
***

# ABSTRACT CLASSES AND INTERFACES
Abstract classes and interfaces are fundamental concepts in object-oriented 
programming (OOP) that help design flexible and maintainable software. 
In C++, these concepts are primarily represented through abstract classes, 
as C++ does not have a dedicated syntax for interfaces like some other languages 
(e.g., Java). Here’s a detailed exploration of abstract classes and interfaces in C++.

## ABSTRACT CLASSES
An abstract class is a **class that cannot be instantiated** on its own and is designed 
to serve as a base for other classes. It typically **contains one or more pure virtual functions**, 
which must be overridden in derived classes.

## Key Characteristics
- **Contains Pure Virtual Functions**: A pure virtual function is a member function 
    in a base class that has no implementation and is declared to be "pure" by using the = 0 
    in its declaration. This type of function enforces that any derived class must provide 
    an implementation for the function in order to be instantiated. 
    A class that contains at least one pure virtual function is considered an abstract 
    class and cannot be instantiated directly.
    ```BASH
    virtual void myFunction() = 0;
    ```
- **Cannot be Instantiated**: You cannot create objects of an abstract class directly
- **Provides a Common Interface**: Abstract classes allow you to define a common interface for all derived classes.

**Example**
```C++
// Shape.h
#ifndef ASHAPE_H
#define ASHAPE_H

// Note: "A" stands for "Abstract"
class AShape {
public:
    virtual ~AShape() {}  // Virtual destructor

    virtual void draw() const = 0; // Pure virtual function
    virtual double area() const = 0; // Pure virtual function
};

#endif // SHAPE_H
```
- The Shape class is an abstract class because it contains pure virtual functions (draw and area).
- Any class deriving from Shape must provide implementations for these functions.

Derived Classes
```C++
// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

#include "AShape.h"
#include <iostream>
#include <cmath> // For M_PI

class Circle : public AShape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() const {
        std::cout << "Drawing a Circle with radius " << radius << std::endl;
    }

    double area() const {
        return M_PI * radius * radius;
    }
};

#endif // CIRCLE_H
```
```C++
// Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "AShape.h"
#include <iostream>

class Rectangle : public AShape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() const {
        std::cout << "Drawing a Rectangle with width " << width 
                  << " and height " << height << std::endl;
    }

    double area() const {
        return width * height;
    }
};

#endif // RECTANGLE_H
```
- The Circle and Rectangle classes inherit from the Shape class and implement the draw and area methods.

**to better understand**
Consider this example
```C++
//.hpp
Class ACharacter
{
    private:
        std::string name;
        
    public:
        virtual void attack(std::string const& target) = 0;
        void sayHello(std::string const& target);
};

Class Warrior : public ACharacter
{
    public:
        virtual void attack(std::string const& target);
};
```

```C++
//.cpp
void ACharacter::sayHello(std::string const& target)
{
    std::cout << "Hello" << target << " !" << std::endl;
}

void Warrior:attack(std::string const& target)
{
    std::cout << "attacks " << target << "with sword" << std::endl;
}
```

```C++
//main.c
int main()
{
    Acharacter* a = new Warrior();
    
    //This would NOT be ok because ACharacter is abstract
    //Acharacter* a = new ACharacter();

    a->sayHello("sudents");
    a->attack("ranger");
}
```
What an abstract class like this tells us is that all derived subclasses must 
implement the method 'attack.' They may have other methods, or none at all, 
but they will definitely have their own implementation of the 'attack' method


## INTERFACES
In C++, an **interface** can be thought of as an 
**abstract class that only contains pure virtual functions and no data members**. 
It establishes a contract for derived classes, specifying that they must implement certain functionalities.
Since C++ does not have a distinct keyword for interfaces, you typically create 
an interface using an abstract class.

## Characteristics of an Interface
- **Only Pure Virtual Functions**: All member functions must be pure virtual.
- **No attributes**:  An interface does not contain member attributes; it only defines virtual functions
- **No Constructors**: An interface cannot have constructors, but it can have a virtual destructor to ensure proper cleanup in derived classes.
- **No Implementation**: Interfaces do not provide any implementation; they only declare the function signatures.
- **Multiple Inheritance**: C++ allows multiple inheritance, meaning a class can implement multiple interfaces.

### Example of an Interface
```c++
// Drawable.h
#ifndef IDRAWABLE_H
#define IDRAWABLE_H
//"I" stands for "Interface"
class IDrawable {
public:
    virtual ~IDrawable() {}

    virtual void draw() const = 0; // Pure virtual function
};

#endif
```

### Implementing Interfaces
Classes can implement multiple interfaces, as shown below:
```C++
// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

#include "IDrawable.h"
#include <iostream>
#include <cmath>

class Circle : public IDrawable {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() const {
        std::cout << "Drawing a Circle with radius " << radius << std::endl;
    }
};

#endif // CIRCLE_H
```
```C++
// Square.h
#ifndef SQUARE_H
#define SQUARE_H

#include "IDrawable.h"
#include <iostream>

class Square : public IDrawable {
private:
    double side;

public:
    Square(double s) : side(s) {}

    void draw() const {
        std::cout << "Drawing a Square with side " << side << std::endl;
    }
};

#endif // SQUARE_H
```

## DIFFERENCES BETWEEN ABSTACT CLASSES AND INTERFACES
| Feature                | Abstract Class                             | Interface                                 |
|------------------------|--------------------------------------------|-------------------------------------------|
| Instantiation          | Cannot be instantiated                     | Cannot be instantiated                    |
| Member Variables       | Can have member variables                  | Cannot have member variables              |
| Access Modifiers       | Can have access modifiers                  | All members are public by default         |
| Implementation         | Can provide some implementations           | Cannot provide any implementation         |
| Multiple Inheritance   | Can inherit from multiple abstract classes | Can be inherited from multiple interfaces |
| Constructor/Destructor | Can have constructors/destructors          | Cannot have constructors/Can Have Virtual Destructors |

***
***

# SHALLOW COPY vs DEEP COPY
## Shallow Copy
- A shallow copy of an object creates a new object that is a copy of the original object, but it copies the references (or pointers) to the resources rather than the resources themselves.

- As a result, both the original object and the copied object refer to the same resource in memory.

- If either object modifies the resource, it will affect the other object since they share the same resource.

- This can lead to issues like double deletion if both objects try to free the same resource when they are destroyed.

**example**
```C++
class Cat {
public:
    Brain* _brain; // Pointer to a Brain object
};

Cat original;
Cat copy = original; // This creates a shallow copy
```
In this case, both original and copy will point to the same Brain object.

Infact if your Cat class does not explicitly define a copy constructor, then the line:
```C++
Cat copy = original; // This creates a shallow copy

/*Note: Here you are not calling the copy assignment operator. Instead, you are invoking the copy constructor of the Cat class. The copy constructor is called when a new object is being created from an existing object

The copy assignment operator is called when an already initialized object is assigned the value of another existing object:
Cat original;   // Calls the default constructor
Cat copy;      // Calls the default constructor for copy
copy = original;  // Calls the copy assignment operator
```
will invoke the default copy constructor that the C++ compiler automatically generates for you. For pointers, it copies the pointer value itself, not the data it points to. This results in both original and copy pointing to the same Brain object, leading to a shallow copy.


## Deep Copy
- A deep copy, on the other hand, creates a new object that is a copy of the original object and also creates new copies of all the resources that the original object points to.

- Each object has its own copy of the resources, so they do not affect each other.

- This is important when the class manages dynamic memory (like pointers), as it prevents issues related to shared ownership of resources

**example**
```C++
class Cat {
public:
    Brain* _brain; // Pointer to a Brain object
    
    Cat(const Cat& other) {
        // Perform a deep copy
        this->_brain = new Brain(*other._brain);
    }
};

Cat original;
Cat copy = original; // This creates a deep copy
```
In this case, copy will have its own Brain object that is a separate copy of the one pointed to by original.

## Testing for Deep Copies
When you need to test for deep copies, it means you should verify that each copy of an object is independent of the others. Here’s a more general explanation:
- **Independence of Copies**: After creating a copy of an object, you should ensure that changes made to the copy do not affect the original object, and vice versa. This includes modifying attributes or internal states of the objects. For example, if you modify the internal state of an object within a copied instance, the original instance should remain unchanged.

- **Memory Management**: You should verify that when one instance of an object is destroyed, it does not inadvertently affect another instance. This is particularly important when dealing with dynamic memory allocation. If two objects share the same dynamically allocated resource (like a pointer), deleting one object can lead to the other object referencing a memory location that has been freed, resulting in undefined behavior or program crashes.

### Practical Steps for Testing
- **Modify and Compare**: After creating a copy, modify the copy's state and check that the original remains unchanged. For example, if the original object has a specific value and you change that value in the copy, assert that the original value is still intact.
- **Destruction Testing**: Create two objects (the original and its copy), and then destroy one of them. After that, check if the remaining object can still access its resources safely and without error. This helps ensure that the object does not point to invalid memory after another object is deleted.