#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
    private:
        unsigned int _arrayLen;
        T* _array;

    public:
        //CONSTRUCTORS AND DESTRUCTOR_______________________________§
        Array();
        Array(unsigned int n);
        Array (const Array& cpy);
        ~Array();


        //OPERATORS OVERLOADS ("=" and "[]")________________________§
        Array& operator=(const Array& cpy);
        const T& operator[](unsigned int index) const;


        //MEMBER FUNCTIONS__________________________________________§
        unsigned int size() const


        //CUSTOM EXCEPTION CLASS____________________________________§
        class IndexOutOfBoundException : public std::exception {
            public:
                virtual const char* what() const throw;
        }
};

#endif