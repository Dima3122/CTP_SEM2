#include <iostream>

namespace lab2
{

    template<class T>
    class SharedPtr
    {
    private:
        inline static size_t count = 0;
        T *ptr;
    public:
        SharedPtr(T *ptr);
        ~SharedPtr();

        T& operator *(){ return *ptr;}
        T& operator ->(){ return *ptr;}//???
        T& get(){ return *ptr;}//???
        
        size_t get_count() { return count;}
    };
    template<class T>
    SharedPtr<T>::SharedPtr(T *ptr)
    {
        this->ptr = ptr;
        count++;
    }
    template<class T>
    SharedPtr<T>::~SharedPtr()
    {
        delete ptr;
        count--;
    }
}
