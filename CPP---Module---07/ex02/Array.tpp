#include "Array.hpp"

//CONSTRUCTORS AND DESTRUCTOR_______________________________§
template <typename T>
Array<T>::Array() : _arrayLen(0), _array(new T[0]()) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arrayLen(n), _array(new T[n]()) {}

template <typename T>
Array<T>::Array (const Array& cpy) {
    this->_arrayLen = cpy._arrayLen;
    this->_array = new T[this->_arrayLen];
    for (unsigned int i = 0; i < this->_arrayLen; i++)
        this->_array[i] = cpy._array[i]; 
}

template<typename T>
Array<T>::~Array() {
    delete[] this->_array;
}


//OPERATORS OVERLOADS ("=" and "[]")________________________§
template <typename T>
Array<T>& Array<T>::operator=(const Array& cpy) {
    if (this != cpy) {
        delete[] this->_array;

        this->_arrayLen = cpy._arrayLen;
        this->_array = new T[this->_arrayLen];

        for (unsigned int i = 0; i < this->_arrayLen; i++)
            this->_array[i] = cpy._array[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const {
    if (index >= this->_arrayLen)
        throw IndexOutOfBoundException();

    return this->_array[index];
}


//MEMBER FUNCTIONS__________________________________________§
template <typename T>
unsigned int Array<T>::size() const {
    return this->_arrayLen;
}


//CUSTOM EXCEPTION CLASS____________________________________§
template<typename T>
const char* Array<T>::IndexOutOfBoundException::what() const throw() {
    return "Index out of bounds!\n";
}