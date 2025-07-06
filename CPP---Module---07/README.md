# CPP---Module---07
This module is designed to help you understand Templates in CPP.

***
# TEMPLATES
***

# Table of contents
- [PARAMETRIC MACROS IN C](#parametric-macros-in-c)
- [TEMPLATES IN C++](#templates-in-c++)
    - [Function Templates](#function-templates)
    - [Class Templates](#class-templates)
    - [Multiple Template Parameters](#multiple-template-parameters)
    - [Template Specialization](#template-specialization)
- [NEW[] OPERATOR](#new[]_operator)
***
***

# PARAMETRIC MACROS IN C
To introduce templates in C++, let's start by considering a type of macro in C.

**Parametric macros** in C are a type of preprocessor macro that accept arguments, allowing them to act like functions but with the simplicity of macro substitution. They are defined using the **#define** directive and can take parameters to be replaced within the macro body when the macro is invoked.

## How Parametric Macros Work
A parametric macro is defined using the #define preprocessor directive, followed by the macro name and parameters in parentheses. When the macro is called, the preprocessor replaces it with the macro body, substituting the provided arguments.

```C
#define MACRO_NAME(param1, param2) (param1 + param2)
```

Example
```C
#define SQUARE(x) ((x) * (x))

int main() {
    int num = 5;
    int result = SQUARE(num);
    printf("The square of %d is %d\n", num, result);
    return 0;
}
```

## Key Characteristics
1. **Text Replacement**: The macro is expanded by simple text substitution. In the example above, SQUARE(num) is replaced by ((num) * (num)) before the code is compiled.

2. **No Type Safety**: Parametric macros do not perform type checking, unlike functions. This can sometimes lead to unexpected results if not used carefully.

3. **Evaluation Pitfalls**: Arguments passed to macros can be evaluated multiple times, which may lead to side effects if those arguments include expressions with side effects (e.g., SQUARE(i++)).

4. **Performance**: Macros can be faster than functions because they avoid the overhead of function calls, as they are expanded inline.

Example of Pitfall:
```C
#define DOUBLE(x) (x + x)

int main() {
    int i = 3;
    printf("Result: %d\n", DOUBLE(i++)); // Expanded to: (i++ + i++)
    return 0;
}
```
This can result in i being incremented twice within the macro expansion.

***
***

# TEMPLATES IN C++
Templates in C++ are powerful features that allow functions and classes to operate 
with generic types. This capability enables you to create flexible and reusable code. 
Here's a breakdown of how templates work and why they are useful:


### What Are Templates
Templates are blueprints or formulae for creating a family of classes or functions. 
They allow you to write a single function or class definition that can work with any data type
without rewriting the code for each type.

For example, a software company may need to sort() for different data types. 
Rather than writing and maintaining multiple codes, we can write one sort() and 
pass the datatype as a parameter. 

C++ adds two new keywords to support templates: **template** and **typename**. 
The second keyword can always be replaced by the keyword **class**.


### How Do Templates Work
Templates are expanded at compiler time. This is like macros. The difference is, 
that the compiler does type-checking before template expansion. The idea is simple, 
source code contains only function/class, but compiled code may contain multiple 
copies of the same function/class. 

***

## Function Templates
A **function template** enables the creation of functions that can work with any data type. 
The template is defined using the **template keyword**, followed by template parameters 
in angle brackets (< >).


### Syntax Example:
```C++
template <typename T>
T add(T a, T b) {
    return a + b;
}
```
- **typename T**: **T** is a placeholder for a data type, can be any identifier. 
- **typename vs class**: In the context of templates,the keywords *typename* and *class* are interchangeable when declaring template parameters.

- This function can now be used for any data type that supports the + operator:
```C++
int main() {
    int x = add(5, 10);         // Works with int
    double y = add(3.5, 2.5);   // Works with double
    return 0;
}
```

***

## Class Templates
A class template allows you to create **classes that work with different data types** 
using a single definition.

### Syntax Example:
```C++
template <typename T>
class Box {
private:
    T _value;
public:
    Box(T value) : _value(value) {}
    T getValue() const { return _value; }
};
```

- When you instantiate a Box object, you specify the type
   ```C++
    int main() {
        Box<int> intBox(123);       // Box with int type
        Box<std::string> strBox("Hello"); // Box with std::string type
    
        std::cout << intBox.getValue() << std::endl;
        std::cout << strBox.getValue() << std::endl;
        return 0;
    }
   ```
    - Box<int>: Creates a Box object where T is int.
    - Box<std::string>: Creates a Box object where T is std::string.


***


## Multiple Template Parameters
Templates can take multiple parameters to make them even more flexible.

### Syntax Example:
```C++
template <typename T, typename U>
class Pair {
private:
    T _first;
    U _second;
public:
    Pair(T first, U second) : _first(first), _second(second) {}
    void display() const {
        std::cout << "First: " << _first << ", Second: " << _second << std::endl;
    }
};

int main() {
    Pair<int, double> mixedPair(10, 3.14);
    mixedPair.display(); // Output: First: 10, Second: 3.14
}
```

***

## Template Specialization
Template specialization is a feature in C++ that allows you to customize the behavior of a template for a specific type or a set of types. This is particularly useful when you need a different implementation for specific types while still leveraging the general template for others.

### How Template Specialization Works:
When you define a template, you create a blueprint that can work with any type. 
However, there are times when the default behavior of the template needs to be 
overridden for a specific type. This is where template specialization comes in. 
You create a specialized version of the template for a particular type, allowing 
you to define custom behavior for that type while retaining the general template 
for all other types.

### Types of Specialization:
1. **Full specialization**: You provide an entirely different implementation of the template for a specific type.
2. **Partial specialization**: You partially specialize the template for a certain category of types or for templates with multiple template parameters.

### Full Specialization Examples:

#### Ex. 1:
Here's an example of a simple funzion template with full specialization for int:
```C++
// A generic sort function 
template <class T>
void sort(T arr[], int size)
{
    // code to implement Quick Sort
}
 
// Template Specialization: A function 
// specialized for char data type
template <>
void sort<char>(char arr[], int size)
{
    // code to implement counting sort
}
```
- The general template sort can handle any type.
- The sort<char> specialization provides a custom implementation that is used 
whenever the Sort template is instantiated with char.
- **template <>**: When you specialize a template, you don't need to put a parameter inside the 
    angle brackets <> because you're specifying the type directly in the specialization 
    declaration. 
    Here,
    ```C++
    sort<char>
    ```
    tells the compiler that this version of sort is specifically for the char type.

#### Ex. 2:
```C++
template <typename T>
class Printer {
public:
    void print(T value) {
        std::cout << "Generic print: " << value << std::endl;
    }
};

// Specialization for `char*`
template <>
class Printer<char*> {
public:
    void print(char* value) {
        std::cout << "Specialized print for char*: " << value << std::endl;
    }
};

int main() {
    // Compiler automatically chooses the generic template
    Printer<int> intPrinter;
    intPrinter.print(42);  // Output: "Generic print: 42"
    
    // Compiler automatically chooses the specialized version
    Printer<char*> charPrinter;
    char str[] = "Hello";
    charPrinter.print(str);  // Output: "Specialized print for char*: Hello"
    
    return 0;
}
```



### Partial Specialization Example:
Partial specialization allows you to provide a specialized version for a subset 
of types or a certain structure of the template parameter.
```C++
// General template with two parameters
template<typename T, typename U>
class Pair {
public:
    void print() {
        std::cout << "General Pair" << std::endl;
    }
};

// Partial specialization when both types are the same
template<typename T>
class Pair<T, T> {
public:
    void print() {
        std::cout << "Partial specialization: Same types" << std::endl;
    }
};

int main() {
    Pair<int, double> pair1;
    pair1.print();  // Uses the general template

    Pair<int, int> pair2;
    pair2.print();  // Uses the partial specialization for same types

    return 0;
}
```
- The general Pair<T, U> template works for any combination of types.
- The partial specialization **Pair<T, T>** is used when both template parameters are 
the same type.
- **Why template<typename T> in the Partial Specialization?**: In the context of template specialization, when you 
partially specialize a class template, you still need to define a **template parameter list**, °
but **only for the parameters that remain generalized**. This is different from 
full specialization, where you do not need a parameter list because every type is 
explicitly specified.

### Key Points:
- Full specialization overrides the general template for a specific type.
- Partial specialization tailors the behavior of the template for certain combinations or forms of template parameters.

***
***
# NEW[] OPERATOR
In C++, the new[] operator is used to dynamically allocate an array of objects on the heap

### Syntax
```C++
T* ptr = new T[n]();
```

**Where:**
- **T** is the type of the elements.
- **n** is the number of elements to allocate.
- **ptr** is a pointer to the first element of the array.

**After this call:**
- Memory for n objects of type T is allocated.
- For each element, the default constructor is called (if T is a class).
- If T is a built-in type (like int), memory is allocated but not initialized (contains garbage values).

### Difference with plain new
new (without brackets) allocates a single object:
```C++
T* ptr = new T;
```
new[] allocates an array of objects.

### Deallocation
To free memory allocated with new[], use:
```C++
delete[] ptr;
```

#### Example
```C++
int* arr = new int[5];  // allocates an array of 5 ints (uninitialized)
for (int i = 0; i < 5; i++) {
    arr[i] = i * 2;
}
// ...
delete[] arr;  // frees the array
```

### "new T[n]" and "new T[n] ()"
The difference is about how the allocated elements are initialized.

**new T[n]**
- Allocates an array of `n` elements of type `T`.
- If T is a **built-in type** (like int, char), the elements are not initialized (contain garbage values).
- If T is a **class type**, the default constructor is called for each element.

**new T[n]()**
- Allocates an array of n elements of type T.
- The elements are value-initialized:
    - For built-in types, this means all elements are zero-initialized (e.g., all ints set to 0).
    - For class types, the default constructor is called (same as above).

#### Example
```C++
int* a = new int[5];    // a[i] are uninitialized (garbage)
int* b = new int[5]();  // b[i] are all 0

class Foo {
public:
    Foo() { std::cout << "Foo constructor\n"; }
};

Foo* f = new Foo[3];    // Foo constructor called 3 times
Foo* g = new Foo[3]();  // Foo constructor called 3 times (same behavior)
```