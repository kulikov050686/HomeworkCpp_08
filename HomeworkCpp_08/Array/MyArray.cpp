#include "MyArray.h"

template<typename T>
void MyArray<T>::DeleteArray()
{
	if (this->array != nullptr)
	{
		delete[] this->array;
		this->size = 0;
	}
}

template<typename T>
MyArray<T>::MyArray(const int size)
{
	assert(size > 0);

	this->size = size;
	this->array = new T[size];
}

template<typename T>
MyArray<T>::MyArray(const MyArray<T>& other)
{
	assert(other.size > 0);

	this->size = other.size;

	this->array = new T[this->size];

	for (int i = 0; i < this->size; i++)
	{
		this->array[i] = other.array[i];
	}	
}

template<typename T>
int MyArray<T>::Lenght()
{
	return this->size;
}

template<typename T>
void MyArray<T>::AddToEnd(T element)
{
	T* tempArray = new T[size];
	int tempSize = size + 1;

	for (int i = 0; i < size; i++)
	{
		tempArray[i] = array[i];
	}

	DeleteArray();

	size = tempSize;
	array = new T[size];

	for(int i = 0; i < size - 1; i++)
	{
		array[i] = tempArray[i];
	}

	array[size - 1] = element;

	delete[] tempArray;
}

template<typename T>
void MyArray<T>::DeleteItem(int index)
{
	assert(0 <= index && index < size);

	T* tempArray = new T[size];
	int tempSize = size;

	for (int i = 0; i < size; i++)
	{
		tempArray[i] = array[i];
	}

	DeleteArray();

	size = tempSize - 1;
	array = new T[size];
	int j = 0;

	for (int i = 0; i < tempSize; i++)
	{
		if (i != index)
		{
			array[j] = tempArray[i];
			j++;
		}			
	}	

	delete[] tempArray;
}

template<typename T>
void MyArray<T>::AddToStart(T element)
{
	T* tempArray = new T[size];
	int tempSize = size + 1;

	for (int i = 0; i < size; i++)
	{
		tempArray[i] = array[i];
	}

	DeleteArray();

	size = tempSize;
	array = new T[size];
	int j = 0;

	array[0] = element;

	for (int i = 1; i < size; i++)
	{
		array[i] = tempArray[j];
		j++;
	}

	delete[] tempArray;
}

template<typename T>
MyArray<T>::~MyArray()
{
	DeleteArray();
}

template<typename T>
MyArray<T>& MyArray<T>::operator = (const MyArray<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	DeleteArray();

	assert(other.size > 0);

	this->size = other.size;
	this->array = new T[this->size];

	for (int i = 0; i < this->size; i++)
	{
		this->array[i] = other.array[i];
	}

	return *this;
}

template<typename T>
T& MyArray<T>::operator [] (const int index)
{
	assert(0 <= index && index < size);

	return array[index];
}
