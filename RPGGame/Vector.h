#include <stdio.h>
#ifndef DYNAMIC_ARRAYS
#define DYNAMIC_ARRAYS

#include <assert.h>

template <class TYPE>
class Vector{
private:
	TYPE* vector;
	unsigned int capacity = 1;
	unsigned int num_elements = 0;
public:
	Vector()
	{
		vector = new TYPE[capacity];
	}
	Vector(const Vector &v)
	{
		num_elements = v.num_elements;
		capacity = v.num_elements;
		vector = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; ++i){
			*(vector + i) = *(v.vector + i);
		}
	}
	~Vector()
	{
		delete[]vector;
	}

	void PushBack(const TYPE &element)
	{
		if (capacity == num_elements)
		{
			TYPE *temp = nullptr;
			capacity += 10;
			temp = new TYPE[capacity];
			for (int i = 0; i < num_elements; i++){
				*(temp + i) = *(vector + i);
			}
			delete[] vector;
			vector = temp;
		}
		*(vector + num_elements++) = element;
	}

	void PushFront(const TYPE &element)
	{
		if (capacity == num_elements)
		{
			TYPE *temp = nullptr;
			capacity += 10;
			temp = new TYPE[capacity];

			for (int i = 0; i < num_elements; i++)
			{
				*(temp + i) = *(vector + i);
			}
			delete[] vector;
			vector = temp;
		}
		else{
			for (int i = num_elements - 1; i >= 0; i--)
			{
				*(vector + i) = *(vector + i - 1);
			}
			*(vector + 0) = element;
			num_elements++;
		}
	}

	TYPE &operator[](unsigned int index)
	{
		assert(index >= 0 && index < num_elements);
		return vector[index];
	}

	TYPE operator[](unsigned int index)const
	{
		assert(index >= 0 && index < num_elements);
		return vector[index];
	}
	bool pop_back(TYPE &value)
	{
		if (num_elements > 0)
		{
			value = buffer[num_elements];
			num_elements--;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Empty()
	{
		return num_elements == 0;
	}
	void Clear()
	{
		num_elements = 0;
	}
	unsigned int Size()
	{
		return num_elements;
	}
	unsigned int Capacity()
	{
		return capacity;
	}
};

#endif //DYNAMIC_ARRAYS