#include<iostream>

template <typename T>

class SP{
    T* ptr;
    int counter{0}; //puntatore o static

public:
    SP(): ptr(nullptr), counter(1) {};
    explicit SP(T* ptr): ptr(ptr), counter(1) {};
    ~SP(){
        counter--;
        if (counter == 0)
            delete ptr;
        };

    SP(SP const& sp){ // copy constructor
        ptr = sp.ptr;
        counter = sp.counter;
        counter++;
    }

    T* operator->(){return ptr;}
    T& operator*(){return *ptr;}

};