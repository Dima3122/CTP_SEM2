#include <iostream>

namespace lab2
{
    template <class T>
    class SharedPtr
    {
    private:
        inline static size_t count = 0;
        T *ptr;
    public:
        SharedPtr(T *ptr);
        SharedPtr(const SharedPtr &&obj);
        SharedPtr(SharedPtr &obj);
        SharedPtr(const T *obj);
        ~SharedPtr();

        T &operator*() { return *ptr; }
        T &operator->() { return *ptr; } //???
        T &get() { return *ptr; }

        size_t get_count() { return count; }
        void reset(const T *const ptr);
    };
    template<class T>
    void SharedPtr<T>::reset(const T *const ptr)
    {
        this->ptr = (T *)ptr;
    }
    template <class T>
    SharedPtr<T>::SharedPtr(T *ptr)
    {
        this->ptr = ptr;
        count++;
    }
    template <class T>
    SharedPtr<T>::SharedPtr(const SharedPtr &&obj)
    {
        this->ptr = obj->ptr;
        obj->ptr = nullptr;
    }
    template <class T>
    SharedPtr<T>::SharedPtr(SharedPtr &obj)
    {
        this->ptr = obj->ptr;
        obj->ptr = nullptr;
    }
    template <class T>
    SharedPtr<T>::SharedPtr(const T *obj)
    {
        this->ptr = obj;
        this->count++;
    }
    template <class T>
    SharedPtr<T>::~SharedPtr()
    {
        delete ptr;
        count--;
    }
}