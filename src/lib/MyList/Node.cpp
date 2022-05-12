#include <iostream>

namespace lab4
{
    template <class T>
    class Node
    {
    public:
        Node *pNext;
        T data;

        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = std::move(data);
            this->pNext = pNext;
        }
    };
} // namespace lab4