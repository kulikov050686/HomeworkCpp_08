#pragma once
#include <cassert>

template <typename T>
class MyArray
{
private:

	/// Массив элементов
	T* array;

	/// Количество элементов массива
	int size = 0;

	/// Удалить динамический массив
	void DeleteArray();

public:	

	/// Конструктор
	MyArray(const int size);

	/// Конструктор копирования
	MyArray(const MyArray<T>& other);

	/// Длина массива
	int Lenght();

	/// Добавить элемент в конец массива
	void AddToEnd(T element);

	/// Удалить элемент массива по индексу
	void DeleteItem(int index);

	/// Добавить элемент в начало массива
	void AddToStart(T element);

	/// Диструктор
	~MyArray();

	/// Перегрузка оператора присваивания
	MyArray<T>& operator = (const MyArray<T>& other);

	/// Перегрузка оператора индексации
	T& operator [] (const int index);
};
