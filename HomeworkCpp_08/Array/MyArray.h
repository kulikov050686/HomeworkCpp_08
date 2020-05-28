#pragma once
#include <cassert>

template <typename T>
class MyArray
{
private:

	/// ������ ���������
	T* array;

	/// ���������� ��������� �������
	int size = 0;

	/// ������� ������������ ������
	void DeleteArray();

public:	

	/// �����������
	MyArray(const int size);

	/// ����������� �����������
	MyArray(const MyArray<T>& other);

	/// ����� �������
	int Lenght();

	/// �������� ������� � ����� �������
	void AddToEnd(T element);

	/// ������� ������� ������� �� �������
	void DeleteItem(int index);

	/// �������� ������� � ������ �������
	void AddToStart(T element);

	/// ����������
	~MyArray();

	/// ���������� ��������� ������������
	MyArray<T>& operator = (const MyArray<T>& other);

	/// ���������� ��������� ����������
	T& operator [] (const int index);
};
