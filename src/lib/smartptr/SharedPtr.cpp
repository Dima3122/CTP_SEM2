#include <iostream>

namespace lab2
{
    template <typename T>
    class SharedPtr
    {
    private:
        T *Ptr;
        size_t *RefCount;

        void clean()
        {
            *RefCount = *RefCount - 1;
            if (*RefCount <= 0)
            {
                if (Ptr != nullptr)
                {
                    delete Ptr;
                }
                delete RefCount;
            }
        }

    public:
        SharedPtr() 
        {
            Ptr = nullptr;
            RefCount = new size_t(0);
        }

        SharedPtr(const T *const ptr)
        {
            Ptr = (T *)ptr;
            RefCount = new size_t(0);
            if (Ptr != nullptr)
            {
                *RefCount = 1;
            }
        }

        SharedPtr(const SharedPtr &obj)
        {
            Ptr = obj.Ptr;
            RefCount = obj.RefCount;
            if (Ptr != nullptr)
            {
                *RefCount = *RefCount + 1;
            }
        }

        SharedPtr(const SharedPtr &&obj)
        {
            Ptr = obj.Ptr;
            RefCount = obj.RefCount;
            obj.Ptr = nullptr;
            obj.RefCount = nullptr;
        }

        ~SharedPtr() { clean(); }

        SharedPtr &operator=(const SharedPtr &obj)
        {
            clean();
            Ptr = obj.Ptr;
            RefCount = obj.RefCount;
            if (Ptr != nullptr)
            {
                *RefCount++;
            }
        }

        SharedPtr &operator=(SharedPtr &&obj)
        {
            clean();
            Ptr = obj.Ptr;
            RefCount = obj.RefCount;
            obj.Ptr = nullptr;
            obj.RefCount = nullptr;
        }

        T &operator*() { return *Ptr; }
        T *operator->() { return Ptr; }
        T *get() { return Ptr; }

        size_t use_count() { return *RefCount; }

        bool unique()
        {
            if (*RefCount == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void reset(const T *const ptr = nullptr)
        {
            clean();
            size_t *NewRefCount = new size_t(0);
            Ptr = (T *)ptr;
            if (Ptr != nullptr)
            {
                *NewRefCount = *NewRefCount + 1;
            }
            RefCount = NewRefCount;
        }
    };
}