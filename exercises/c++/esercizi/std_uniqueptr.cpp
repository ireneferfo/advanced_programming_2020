#include<iostream>

template <typename T>
class UP{
    T* ptr;

public:
    UP() noexcept: ptr(nullptr){}; //constructor
    explicit UP(T* ptr) noexcept: ptr(ptr) {};
    ~UP(){delete ptr};

    UP(UP const&) = delete; // delete copy semantics
    UP& operator=(UP const&) = delete;

    UP(UP&& x) noexcept {x.swap(*this)};
    UP& operator=(UP&& x) noexcept {x.swap(*this); return *this;}

    T* operator->() const noexcept {return ptr;};
    T& operator*() const noexcept {return *ptr;}

    void swap(UP& src) noexcept {std::swap(ptr, src.ptr);};

    T* get() const {return ptr;};

    T* release() noexcept {
        T* result = nullptr;
        std::swap(result, ptr);
        return result;
    }

    void* reset(){
        T* tmp = release();
        delete tmp;
    }
};