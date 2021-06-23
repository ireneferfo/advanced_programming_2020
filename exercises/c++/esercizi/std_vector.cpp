#include<iostream>

template <typename T>

class Vector {
    std::unique_ptr <T[]> elem; // otherwise I should be careful with default copy seman. 
    std::size_t _size;

public:
    Vector(const std::size_t size): elem{new T[size]}, _size{size} {} // constructor 
    ~Vector() {delete[] elem;} // destructor (release acquired memory)

    Vector(Vector const&) = delete; // using unique_ptr, delete copy semantics 
    Vector& operator= (Vector const&) = delete;

    Vector(Vector&& v)noexcept: _size{std::move(v._size)}, elem{std::move(v.elem)};
    Vector& operator=(Vector&& v)noexcept = default; // move semantics
    
    std::size_t size() const {return _size;}

    T* begin() {return elem;} // range for loop 
    const T* begin() const {return elem;}
    T* end() {return elem + size();}
    const T* end() const {return elem + size();}

    Vector operator+ (const Vector& lhs, const Vector& rhs){
        const auto size = lhs.size();
        Vector res(size);
        for (std::size_t i = 0; i < size; i++)
            res[i] = lhs[i] + rhs[i]; 
        return res;
    }
};


/*
v1+v2+v3+v4 lo fa a coppie: (((v1+v2)+v3)+v4). Molto poco efficiente. 
*/