#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;



class Animal {
public:
    virtual string speak() const = 0;
};


class Cat : public Animal {
public: 
        virtual string speak() const;
};

string Cat::speak() const {
    return "Meow.";
}

class Dog : public Animal {
public: 
        virtual string speak() const;
};

string Dog::speak() const {
    return "Bark.";
}

//Public can be accessed by anything. Private cannot be accessed by anything, anywhere else.

template <class T>

class Array {
public: 
        Array(int size);
        ~Array();
        T & operator[](int i) const;
        int size() const;
        void fill(int k);
        T * begin();
        T * end();

private:
        int len;
        T * data;
};

//Refers to line 9, default constructor. Class, and then function.
// Sets data to new int size.
template <class T>
Array<T>::Array(int size) {
    len = size;
    data = new T[size];
}
//Deconstructor. Deletes pointer "data".
template <class T>
Array<T>::~Array() {
    delete [] data;
}
//"i" is the index that returns the i^th place in data array.
template <class T>
T & Array<T>::operator[](int i) const{
    return data[i];
}
//len is defined by size int the constructor in Line 28-30
template <class T>
int Array<T>::size() const{
    return len;
}
//Goes through indexes to set data = k. If we put k=5, then 0-len will be equal to 5.
template <class T>
void Array<T>::fill(int k) {
    for (int i = 0; i < len ; i++) {
    data[i] = k;
    }
}
//Returns beginning of array. Returns data "point", which is first spot in array, or 0^th spot.
template <class T>
T * Array<T>::begin() {
    return data;
}
//data is the first spot and len is the size of the array. by adding the two, you get to one spot after the array, and you can
//now use all of the values before.
template <class T>
T * Array<T>::end() {
    return data + len;
}
int main(int argc, char * args[]) {
    
        Array<Animal*> b(2);
        
        b[0] = new Dog();
        b[1] = new Cat();
        
        cout << b[0]->speak() << endl;
        cout << b[1]->speak() << endl;
        
        Array<int> a(3);

        a[0] = 10;
        a[1] = 11;
        a[2] = 12;

        assert(a[0] == 10);
        assert(a[1] == 11);
        assert(a[2] == 12);
        assert(a.size() == 3);
        a.fill(5);
        assert(a[0] == 5);
        assert(a[1] == 5);
        assert(a[2] == 5);
        a[0] = 3;
        a[1] = 1;
        a[2] = 2;
        //Sort is a function that returns the sorted value.
        sort(a.begin(), a.end());
        assert(a[0] == 1);
        assert(a[1] == 2);
        assert(a[2] == 3);
        //this points to a.begin, which in returns data. Data points to the beginning spot. 
        //From there, it increments them before the next line checks to see what is in the next spot.
        int * it = a.begin();
        assert(*it == 1);
        ++it;
        assert(*it == 2);
        ++it;
        assert(*it == 3);
        ++it;
        assert(it == a.end());

        cout << "All tests passed." << endl;
}