#include "Node.cpp"

namespace lab4
{
	template <class T>
	class MyList
	{
	public:
		MyList();
		~MyList();
		void pop_front();
		void push_back(T data);
		void clear();
		int GetSize() { return Size; }
		T &operator[](const int index);
		void push_front(T data);
		void insert(T data, int index);
		void insert(T data, int Myindex, int indexnext);
		void removeAt(int index);
		void pop_back();
		bool check();
	private:
		int Size;
		Node<T> *head;
	};

	template <class T>
	MyList<T>::MyList()
	{	
		Size = 0;
		head = nullptr;
	}

	template <class T>
	MyList<T>::~MyList()
	{
		clear();
	}

	template <class T>
	void MyList<T>::pop_front()
	{
		Node<T> *temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	}

	template <class T>
	void MyList<T>::push_back(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T> *current = this->head;

			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node<T>(data);
		}
		Size++;
	}

	template <class T>
	void MyList<T>::clear()
	{
		while (Size)
		{
			pop_front();
		}
	}

	template <class T>
	T &MyList<T>::operator[](const int index)
	{
		int counter = 0;

		Node<T> *current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}

	template <class T>
	void MyList<T>::push_front(T data)
	{
		head = new Node<T>(data, head);
		Size++;
	}

	template <class T>
	void MyList<T>::insert(T data, int index)
	{
		if (index == 0)
		{
			push_front(data);
		}
		else
		{
			Node<T> *previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}
			Node<T> *newNode = new Node<T>(data, previous->pNext);
			previous->pNext = newNode;
			Size++;
		}
	}

	template <class T>
	inline void MyList<T>::insert(T data, int index, int indexnext)
	{
		if (index == 0)
		{
			push_front(data);
		}
		else
		{
			Node<T> *previous = this->head;
			Node<T> *nodeNext = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}
			for (int i = 0; i < indexnext; i++)
			{
				nodeNext = nodeNext->pNext;
			}
			Node<T> *newNode = new Node<T>(data, previous->pNext);
			newNode->pNext = nodeNext;
			previous->pNext = newNode;
			Size++;
		}
	}

	template <class T>
	void MyList<T>::removeAt(int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else
		{
			Node<T> *previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}
			Node<T> *toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;
			delete toDelete;
			Size--;
		}
	}

	template <class T>
	void MyList<T>::pop_back()
	{
		removeAt(Size - 1);
	}

	template <class T>
	bool MyList<T>::check()
	{
		int count = 0;
		Node<T> *current = this->head;
		while (current != nullptr)
		{
			current = current->pNext;
			count++;
			if (count > 1000)
			{
				return true;
			}
		}
		return false;
	}

}