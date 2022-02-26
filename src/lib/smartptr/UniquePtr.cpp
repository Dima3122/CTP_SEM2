#include <iostream>

namespace lab2
{
    template <typename T>
    class UniquePtr
    {
    private:
        T *Ptr = nullptr;

    public:
        UniquePtr() = default;
        UniquePtr(const T *const ptr)
        {
            Ptr = (T *)ptr;
        }
        UniquePtr(const UniquePtr &obj) = delete;
        UniquePtr(UniquePtr &&obj)
        {
            Ptr = obj.Ptr;
            obj.Ptr = nullptr;
        }

        ~UniquePtr()
        {
            if (Ptr != nullptr)
            {
                delete Ptr;
            }
        }

        UniquePtr operator=(const UniquePtr &obj) = delete;

        UniquePtr operator=(UniquePtr &&obj)
        {
            if (this == &obj)
            {
                return *this;
            }
            if (Ptr != nullptr)
            {
                delete Ptr;
            }
            Ptr = obj.Ptr;
            obj.Ptr = nullptr;
            return *this;
        }

        T &operator*() { return *Ptr; }

        T *operator->() { return Ptr; }

        T *get() { return Ptr; }

        void reset(const T *const ptr = nullptr)
        {
            if (Ptr != nullptr)
            {
                delete Ptr;
            }
            Ptr = (T *)ptr;
        }
    };
}