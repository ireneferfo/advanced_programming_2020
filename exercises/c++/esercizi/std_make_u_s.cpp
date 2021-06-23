#include<iostream>
#include<memory>
#include<utility>

template<typename T, typename ...Args> // variadic templates; ... before: packi
std::unique_ptr<T> make_unique(Args&&... args){ // ... after: unpack, with distinction between r-value and l-value
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...)); 
}

template<typename T, typename ...Args>
std::shared_ptr<T> make_shared(Args&&... args){
    return std::shared_ptr<T>(new T(std::forward<Args>(args)..))
}