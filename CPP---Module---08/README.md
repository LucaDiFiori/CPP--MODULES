# CPP---Module---08:
# KEY CONCEPTS FOR TEMPLATED CONTAINERS, ITERATORS, AND ALGORITHMS IN C++98
This module is designed to help you understand templated containers, iterators, and algorithms in C++.


# Table of contents
- [CONTAINERS AND TEMPLATE CONTAINERS](#containers-and-template-containers)
    - [What is a Container in C++?](#what-is-a-container-in-c)
    - [Template Containers in C++98](#template-containers-in-c98)
    - [Main STL Containers in C++98](#main-stl-containers-in-c98)
    - [std::vector<T>](#stdvectort)
    - [std::list<T>](#stdlistt)
    - [std::deque<T>](#stddequet)
    - [std::map<K, V>](#stdmapk-v)
    - [std::set<T>](#stdsett)
- [ITERATORS](#iterators)
    - [Iterator vs Pointer](#iterator-vs-pointer)
    - [Const Iterators](#const-iterators)
    - [Types of Iterators](#types-of-iterators)
    - [Input Iterator](#input-iterator)
    - [Output Iterator](#output-iterator)
    - [Forward Iterator](#forward-iterator)
    - [Bidirectional Iterator](#bidirectional-iterator)
    - [Random Access Iterator](#random-access-iterator)
    - [Iterators and STL algorithms](#iterators-and-stl-algorithms)
    - [Common Operations with Iterators](#common-operations-with-iterators)
- [STL ALGORITHMS IN C++98](#stl-algorithms-in-c98)
    - [Key Characteristics of STL Algorithms in C++98](#key-characteristics-of-stl-algorithms-in-c98)
    - [How STL Algorithms Work](#how-stl-algorithms-work)
    - [Common STL Algorithms in C++98](#common-stl-algorithms-in-c98)


***
***

# CONTAINERS AND TEMPLATE CONTAINERS
## What is a Container in C++?
In C++, a container is a data structure object that stores and organizes multiple elements (objects) of a certain type. Containers provide a way to group multiple values together and access them efficiently.

The C++ Standard Library (STL) defines several types of containers to store collections of data. Examples include arrays, lists, vectors, maps, and sets.

**Key Features of Containers:**
- Store elements of a specific type.
- Provide ways to insert, delete, and access elements.
- Manage the memory allocation and deallocation internally.
- Follow certain rules and guarantees about element ordering, uniqueness, and performance.

## Template Containers in C++98
A template container is a container class that is written as a template, allowing it to store elements of **any data type**.

The STL containers are **class templates**. For example, `std::vector<T>` is a template container class where T is a placeholder for the type of elements the vector stores.
For example yo can have a `std::vector<MyClass>` to store objects of a user-defined class.

The container class is instantiated with the specific type when you declare an object.

Using templates allows the containers to be type-independent and flexible. For example, instead of writing different container classes for int, double, string, or any user-defined type, templates let you write one generic container class.

## Main STL Containers in C++98
Here are some standard template containers defined in C++98 STL:

| Container   | Description                                       | Iterator Type | Key Notes                                         |
| ----------- | ------------------------------------------------- | ------------- | ------------------------------------------------- |
| `vector<T>` | Dynamic array (contiguous memory)                 | Random access | Fast access, slow insert/remove except at end     |
| `list<T>`   | Doubly linked list                                | Bidirectional | Fast insert/remove anywhere, slower random access |
| `deque<T>`  | Double-ended queue (dynamic array at both ends)   | Random access | Efficient insert/remove at both ends              |
| `map<K,V>`  | Associative container with sorted key-value pairs | Bidirectional | Key-value pairs, sorted by keys                   |
| `set<T>`    | Sorted unique keys                                | Bidirectional | No duplicates, sorted keys                        |



## std::vector<T>
`std::vector<T>` is a sequence container from the C++ Standard Library that stores elements of type T in a dynamic array.
- **Dynamic size**: You can add (push_back) or remove (pop_back) elements at the end.
- **Contiguous storage**: Elements are stored in contiguous memory, meaning it behaves similarly to a raw array internally.
- **Random access**: You can access any element in constant time using the subscript operator [] or the at() method.
- **Automatic memory management**: The vector resizes automatically when it runs out of capacity.

**Example**
```C++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers; // vector of ints

    numbers.push_back(10);  // add element 10
    numbers.push_back(20);  // add element 20
    numbers.push_back(30);  // add element 30

    // Access elements
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << std::endl;
    }

    return 0;
}
```
Output
```bash
10
20
30
```

## std::list<T>
std::list<T> is a sequence container from the C++ Standard Library that stores elements of type T in a doubly linked list.
- **Doubly linked list**: Each element points to both its previous and next neighbor.
- **Efficient insertion/removal**: Very fast at adding or removing elements at beginning, end, or even in the middle.
- **No random access**: Unlike std::vector, you cannot do myList[3]. You must use iterators to reach a specific element.
- **Stable iterators**: Adding/removing elements does not invalidate iterators to other elements.

**When to Use std::list<T>?**
Use std::list when:
- You frequently insert or delete elements in the middle or at the front.
- You don’t need random access.
- You want stable iterators, even after insertions/removals.

Don’t use it when:
- You need to access elements by index.
- Performance and memory usage are critical — std::vector is usually more cache-friendly and faster in practice.

**Example**
```C++
#include <iostream>
#include <list>

int main() {
    std::list<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Use iterator to access elements
    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
```

## std::deque<T>
std::deque<T> stands for double-ended queue. It's a sequence container that allows fast insertion and removal at both the front and the back.
Unlike std::vector, which allows fast operations only at the back, std::deque supports fast push_front and push_back.
Internally, it is implemented as a series of chunks or blocks — not a single contiguous array.
- **Double-ended**: You can insert and remove elements from both the front and the back in constant time.
- **Random access**: You can access elements using [] just like a vector (in constant time).
- **Automatic resizing**: Like vector, it grows as needed.
- **No invalidation of front insertions**: Unlike vector, inserting at the front won’t cause all elements to shift.

**When to Use std::deque<T>?**
Use std::deque when:
- You need to push or pop from both ends.
- You want random access like in a vector.
- You don’t mind slightly more overhead than vector.

Avoid it when:
- You only ever add to the back → use vector (faster).
- You need to insert or delete frequently in the middle → use list.

**Example**
```C++
#include <iostream>
#include <deque>

int main() {
    std::deque<int> numbers;

    numbers.push_back(20);   // Add to back
    numbers.push_front(10);  // Add to front
    numbers.push_back(30);   // Add to back

    // Access using index
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << std::endl;
    }

    return 0;
}
```

Output
```bash
10
20
30
```

## std::map<K, V>
std::map<K, V> is a sorted associative container in the C++ Standard Library that stores key-value pairs.
- **Unique keys**: Each key `K` is unique, and is mapped to a value `V`. This means You can't insert two elements with the same key.
- **Internally**, it’s implemented as a balanced binary search tree (usually a red-black tree).
- **Sorted**: Keys are automatically sorted. When you insert items into a std::map, the keys are automatically kept in order, typically ascending by default (operator<).
    ```C++
    std::map<int, std::string> names;

    names[10] = "Alice";
    names[5] = "Bob";
    names[20] = "Charlie";

    for (std::map<int, std::string>::iterator it = names.begin(); it != names.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // Output:
    // 5: Bob
    // 10: Alice
    // 20: Charlie

    // Even though we inserted keys out of order, the map automatically sorted them by key.
    ```
- **Logarithmic time**: Insertion, deletion, and lookup are all done in O(log n) time.
- **Custom sorting**: You can use your own comparison function if needed. By default, std::map uses `operator<` to sort keys, but you can change that by passing a custom comparator.
    ```C++
    #include <iostream>
    #include <map>

    struct Descending {
        bool operator()(int a, int b) const {
            return a > b; // reverse comparison
        }
    };

    int main() {
        std::map<int, std::string, Descending> names;

        names[10] = "Alice";
        names[5] = "Bob";
        names[20] = "Charlie";

        for (std::map<int, std::string, Descending>::iterator it = names.begin(); it != names.end(); ++it) {
            std::cout << it->first << ": " << it->second << std::endl;
        }
        return 0;
    }

    // Output:
    // 20: Charlie
    // 10: Alice
    // 5: Bob

    // You can sort by any logic you define — even custom objects, as long as you provide a comparison function.
    ```
- **Safe iterators**: When you add or remove items from a std::map, the existing iterators (pointers to elements in the map) remain valid — except if you remove the element that the iterator was pointing to.
    ```C++
    std::map<int, std::string> m;
    m[1] = "A";
    m[2] = "B";
    m[3] = "C";

    std::map<int, std::string>::iterator it = m.find(2); // points to "B"
    m[4] = "D"; // insert new key

    std::cout << it->first << ": " << it->second << std::endl; // still works

    // This works — the iterator is still valid, even after inserting.
    ```
    But if you erase the elements:
    ```C++
    m.erase(2); // removes key 2
    std::cout << it->first << ": " << it->second << std::endl; // ❌ INVALID — undefined behavior!

    //❌ Now it is invalid, because we erased the element it was pointing to.
    ```

**Common Methods**
- `insert(std::pair<K, V>)` – insert a new key-value pair.
- `operator[]` – access or insert value by key.
- `find(key)` – returns an iterator to the key if found, else end().
- `erase(key)` – removes an element by key.
- `begin() / end()` – for iterating.

**When to Use std::map<K, V>?**
Use std::map when:
- You need elements to be sorted by key.
- You need logarithmic performance.
- You want safe iterators.

Avoid it when:
- You don’t need sorted keys and want faster access → use std::unordered_map.
- You need multiple values for the same key → use std::multimap.

**Basic Example**
```C++
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ages;

    ages["Alice"] = 30;     // insert Alice with age 30
    ages["Bob"] = 25;
    ages["Charlie"] = 35;

    // Print all key-value pairs (automatically sorted by key)
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
```

Output
```bash
Alice: 30
Bob: 25
Charlie: 35
```

## std::set<T>
std::set<T> is an **associative container** that stores **unique values of type T** in **sorted** order.
- **Sorted**: It automatically keeps the elements sorted (by default using <).
- **Unique values only**:It does not allow duplicates — inserting a value that already exists does nothing.
- **Efficient lookup, insertion, and removal**: All in O(log n) time.
- **Safe iterators**: Inserting/removing elements does not invalidate other iterators (except the erased one).
- **No random access**: You can't do mySet[2] like in a vector.

**When to Use std::set<T>**
Use std::set when:
- You want to store unique elements only.
- You need elements to be automatically sorted.
- You need logarithmic time insertion/search/removal.

Avoid it when:
- You need duplicate values → use std::multiset.
- You need faster access without sorting → use std::unordered_set.
- You need index-based access → use std::vector.

**Operations**
| Operation          | Time Complexity | Description                                      |
| ------------------ | --------------- | ------------------------------------------------ |
| `insert(value)`    | O(log n)        | Adds a value (only if it's not already present). |
| `find(value)`      | O(log n)        | Returns an iterator to the value (or `end()`).   |
| `erase(value)`     | O(log n)        | Removes a value if it exists.                    |
| `size()`           | O(1)            | Returns the number of elements.                  |
| `begin()`, `end()` | O(1)            | Iterators for range-based traversal.             |


**Basic Example**
```C++
#include <iostream>
#include <set>

int main() {
    std::set<int> numbers;

    numbers.insert(10);
    numbers.insert(5);
    numbers.insert(20);
    numbers.insert(10); // duplicate — will be ignored

    for (std::set<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
```

Output
```bash
5
10
20
```


***


# ITERATORS
An iterator is an object that acts like a pointer:
- It **points to an element** inside a container.
- It allows you to **traverse** the container.
- It gives **access** to the elements (read or write).
- It provides a **common interface** for working with different containers (vector, list, map, etc.).

You can think of an iterator as a "cursor" that moves from one element to the next in a container.

## Iterator vs Pointer
In many containers (like vector), iterators behave almost exactly like pointers. In fact, a vector<int>::iterator is implemented as an int* internally.

But for other containers like list, map, etc., iterators are complex classes that behave like pointers using operator overloading.

# Const Iterators
You can make an iterator const so it can read values but not modify them.
```C++
std::vector<int>::const_iterator it;
```

**Basic Usage Example**
```C++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;  // Dereference the iterator to access the value
    }

    return 0;
}
```
- `v.begin()` → iterator to the first element
- `v.end()` → iterator past the last element
- `++it` → move to the next element
- `*it` → get the value at the current position

## Types of Iterators
Iterators in C++ are grouped into five categories, based on how powerful they are — meaning how you can use them to move through containers and access data.

Think of iterators like people walking along a line of boxes. Some people can only move forward. Others can also move backward. Some can jump around and compare positions.

| Iterator Type              | Can Move             | Can Go Back | Can Jump | Can Compare          | Typical Container           |
| -------------------------- | -------------------- | ----------- | -------- | -------------------- | --------------------------- |
| Input Iterator             | Forward              | No          | No       | Only `==`            | `std::istream_iterator`     |
| Output Iterator            | Forward (write-only) | No          | No       | No                   | `std::ostream_iterator`     |
| **Forward Iterator**       | Forward              | No          | No       | `==`, `!=`           | `forward_list` (C++11)      |
| **Bidirectional Iterator** | Forward + Back       | Yes         | No       | `==`, `!=`           | `std::list`, `std::map`     |
| **Random Access Iterator** | Forward + Back       | Yes         | Yes      | `==`, `<`, `>`, `[]` | `std::vector`, `std::deque` |

### Input Iterator
🔹 What can it do?
- Can move forward (++)
- Can read the element (*it)
- Used mostly for input streams (like reading from cin)

🔸 Can't:
- Move backward (--)
- Jump forward (it + 2)
- Write to elements

```C++
#include <iterator>
#include <iostream>

int main() {
    std::istream_iterator<int> it(std::cin);  // Reads from standard input
    std::istream_iterator<int> end;

    if (it != end) {
        int value = *it;  // Reads an integer from input
        std::cout << "Value: " << value << std::endl;
    }
    return 0;
}
```

### Output Iterator
🔹 What can it do?
- Can move forward
- Can write to the pointed element
- Used to output elements (e.g. to cout or containers)

🔸 Can't:
- Read
- Move backward
- Jump

```C++
#include <iterator>
#include <iostream>

int main() {
    std::ostream_iterator<int> out_it(std::cout, ", ");
    *out_it = 10; // Prints "10, "
    return 0;
}
```

### Forward Iterator
🔹 What can it do?
- Move forward (++)
- Read and write
- Can be used in loops multiple times

🔸 Can't:
- Move backward
- Jump by index


### Bidirectional Iterator
🔹 What can it do?
- Move forward and backward (++ and --)
- Read and write

🔸 Can't:
- Jump multiple positions
- Compare distances

**Used in**: std::list, std::map, std::set

```C++
#include <list>
#include <iostream>

int main() {
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    std::list<int>::iterator it = l.begin();
    ++it;      // Go forward
    --it;      // Go backward
    std::cout << *it << std::endl;

    return 0;
}
```

### Random Access Iterator
🔹 What can it do?
- Move forward and backward
- Jump ahead or back (it + 3, it - 2)
- Compare with <, >, ==
- Access by index: it[2]

**Used in**: std::vector, std::deque, C-style arrays

```C++
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::vector<int>::iterator it = v.begin();

    std::cout << it[1] << std::endl;     // Access second element (20)
    std::cout << *(it + 2) << std::endl; // Access third element (30)

    return 0;
}
```

### Quick Comparison Chart
| Feature             | Input | Output | Forward | Bidirectional | Random Access |
| ------------------- | ----- | ------ | ------- | ------------- | ------------- |
| Can read            | ✅     | ❌      | ✅       | ✅             | ✅             |
| Can write           | ❌     | ✅      | ✅       | ✅             | ✅             |
| Can move forward    | ✅     | ✅      | ✅       | ✅             | ✅             |
| Can move backward   | ❌     | ❌      | ❌       | ✅             | ✅             |
| Can jump (`+`, `-`) | ❌     | ❌      | ❌       | ❌             | ✅             |
| Supports `[]`       | ❌     | ❌      | ❌       | ❌             | ✅             |

## Iterators and STL algorithms
Different STL algorithms require specific types of iterators:
| Algorithm      | Requires                 |
| -------------- | ------------------------ |
| `std::find`    | Input iterator           |
| `std::reverse` | Bidirectional iterator   |
| `std::sort`    | Random access iterator   |
| `std::copy`    | Input → Output iterators |

So, if you're using std::sort, you can only use containers with random access iterators, like vector or deque — not list!





## Common Operations with Iterators
| Operation          | Syntax                      | Description                                   |
| ------------------ | --------------------------- | --------------------------------------------- |
| Declare iterator   | `vector<int>::iterator it;` | Iterator for vector of int                    |
| Begin of container | `v.begin()`                 | Iterator to first element                     |
| End of container   | `v.end()`                   | Iterator to one past the last element         |
| Move forward       | `++it`                      | Go to next element                            |
| Move backward      | `--it`                      | Go to previous element (if allowed)           |
| Dereference        | `*it`                       | Get (or set) the element at iterator position |
| Compare            | `it == v.end()`             | Check if at end of container                  |
| Index access       | `it[n]`                     | Access nth element ahead (random access only) |


***
***

# STL ALGORITHMS IN C++98
The STL algorithms in C++98 are a set of pre-defined, generic functions designed to perform common operations on sequences of elements, such as searching, sorting, transforming, and accumulating data. These algorithms operate on ranges defined by pairs of iterators, not directly on containers, which makes them highly flexible and reusable with any container or sequence that supports iterators

## Key Characteristics of STL Algorithms in C++98
- **Operate on iterator ranges**: Algorithms take two iterators (begin and end) specifying the sequence to work on.
- **Do not modify container structure**: They modify elements but do not change container size or reallocate memory.
- **Generic and reusable**: Work with any data type and container supporting iterators.

## How STL Algorithms Work
- Algorithms rely on iterators to abstract the traversal of elements, so the same algorithm can work with arrays, vectors, lists, or even custom data structures.
- They separate what operation is done (algorithm) from where the data is stored (container) and how to traverse it (iterator).
- For example, std::sort requires random-access iterators (like those from vectors or arrays), while std::for_each works with any input iterator.

**Example: Sorting and Searching**
```C++
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {5, 3, 6, 4, 8, 1, 7, 2};

    // Sort the vector
    std::sort(v.begin(), v.end());

    // Print sorted vector
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;

    // Binary search for element 4
    if (std::binary_search(v.begin(), v.end(), 4))
        std::cout << "4 found\n";
    else
        std::cout << "4 not found\n";

    return 0;
}
```

## Common STL Algorithms in C++98
| Algorithm           | Purpose                                                    | Example Usage                          |
|---------------------|------------------------------------------------------------|--------------------------------------|
| `std::for_each`     | Applies a function to each element in a range              | `std::for_each(v.begin(), v.end(), func);` |
| `std::sort`         | Sorts elements in a range (usually uses quicksort internally) | `std::sort(arr, arr + n);` or `std::sort(v.begin(), v.end());` |
| `std::binary_search`| Searches for an element in a sorted range using binary search | `std::binary_search(v.begin(), v.end(), key);` |
| `std::accumulate`   | Computes the sum (or other accumulation) of elements in a range | `std::accumulate(v.begin(), v.end(), 0);` |
| `std::copy`         | Copies elements from one range to another                   | `std::copy(src.begin(), src.end(), dest.begin());` |
| `std::find`         | Finds the first occurrence of a value in a range            | `std::find(v.begin(), v.end(), value);` |
