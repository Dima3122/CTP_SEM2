#include <iostream>

namespace lab2
{
    template<class T>
    class UniquePtr
    {
    private:
        T *ptr;
    public:
        UniquePtr(T *ptr);
        ~UniquePtr();

        T& operator *(){ return *ptr;}
        T& operator ->(){ return *ptr;}//???
        T& get(){ return *ptr;}//???
    };

    template<class T>
    UniquePtr<T>::UniquePtr(T *ptr)
    {
        this->ptr = ptr;
    }
    template<class T>
    UniquePtr<T>::~UniquePtr()
    {
        delete ptr;
    }
}