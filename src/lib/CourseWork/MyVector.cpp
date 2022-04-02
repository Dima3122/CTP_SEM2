#include <iostream>

namespace MyVector
{

	template <typename T>
	class MyVector
	{
	public:
		MyVector()
		{
			Arr = new T[1];
			Capacity = 1;
			Size = 0;
		}
		MyVector(MyVector &other)
		{
			if (this != &other)
			{
				delete[] Arr;
				Arr = other.Arr;
				Size = other.Size;
				Capacity = other.Capacity;
				other.Arr = nullptr;
				other.Size = other.Capacity = 0;
			}
		}
		MyVector(MyVector &&other) noexcept
		{
			if (this != &other)
			{
				delete[] Arr;
				Arr = other.Arr;
				Size = other.Size;
				Capacity = other.Capacity;
				other.Arr = nullptr;
				other.Size = other.Capacity = 0;
			}
		}
		MyVector &operator=(MyVector &other)
		{
			if (this != &other)
			{
				delete[] Arr;
				Arr = other.Arr;
				Size = other.Size;
				Capacity = other.Capacity;
				other.Arr = nullptr;
				other.Size = other.Capacity = 0;
			}
			return *this;
		}

		MyVector &operator=(MyVector &&other) noexcept
		{
			if (this != &other)
			{
				delete[] Arr;
				Arr = other.Arr;
				Size = other.Size;
				Capacity = other.Capacity;
				other.Arr = nullptr;
				other.Size = other.Capacity = 0;
			}
			return *this;
		}

		void pushBack(const T &value)
		{
			if (Size >= Capacity)
			{
				addMemory();
			}
			Arr[Size++] = value;
		}

		void pop_back()
		{
			if (Size - 1 != 0)
			{
				Size--;
			}
			if (Capacity > Size * 2)
			{
				removeMemory();
			}
		}

		void remove(size_t index)
		{
			if (index >= 0 && index <= Size)
			{
				if (Capacity > Size * 2)
				{
					removeMemory();
				}
				for (size_t i = index + 1; i < Size; ++i)
				{
					Arr[i - 1] = Arr[i];
				}
				--Size;
			}
		}

		const T *begin() const { return &Arr[0]; }
		const T *end() const { return &Arr[Size]; }

		T *begin() { return &Arr[0]; }
		T *end() { return &Arr[Size]; }

		T &operator[](size_t index) { return Arr[index]; }
		bool isEmpty() const { return Size == 0; }
		size_t size() const { return Size; }
		size_t capacity() const { return Capacity; }

		~MyVector() { delete[] Arr; }

	private:
		void addMemory()
		{
			Capacity *= 2;
			T *tmp = Arr;
			Arr = new T[Capacity];
			for (size_t i = 0; i < Size; ++i)
			{
				Arr[i] = tmp[i];
			}
			delete[] tmp;
		}

		void removeMemory()
		{
			Capacity /= 2;
			T *tmp = Arr;
			Arr = new T[Capacity];
			for (size_t i = 0; i < Size; ++i)
			{
				Arr[i] = tmp[i];
			}
			delete[] tmp;
		}

		T *Arr;
		size_t Size;
		size_t Capacity;
	};

	template <typename T>
	inline std::ostream &operator<<(std::ostream &os, const MyVector<T> &vec)
	{
		for (const T &val : vec)
			os << val << " ";
		{
			return os;
		}
	}
} // namespace MyVector