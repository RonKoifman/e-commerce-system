#ifndef __ARRAY_H
#define __ARRAY_H

#include "Utils.h"

// This template Array class accepts a pointer type which its class must have an operator<<

template<class T>
class Array
{
private:
	T* arr;
	unsigned int size;

public:
	Array() : arr(nullptr), size(0) {}
	~Array() { delete[] arr; }
	Array(const Array& other) = delete;
	const Array& operator=(const Array& other) = delete;
	void push_back(const T& newItem);
	T& operator[](int index) { return arr[index]; }

	// Getters
	T* getArr() const { return arr; }
	unsigned int getSize() const { return size; }

	// Friends
	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		os << typeid(**arr.arr).name() + 6 << "s: ";
		if (arr.size == 0)
		{
			os << "none." << endl;
		}
		else
		{
			os << endl;
			for (unsigned int i = 0; i < arr.size; i++)
			{
				os << i + 1 << ".";
				os << *arr.arr[i] << endl;
			}
		}
		return os;
	}
};

template<class T>
void Array<T>::push_back(const T& newItem)
{
	T* temp = new T[size + 1]; // Create bigger array to add the new item

	// Move the pointers from the current array to temp
	for (unsigned int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = newItem; // Add the new item
	size++;

	delete[] arr; // Free the current array
	arr = temp; // Update array to temp
}

#endif // __ARRAY_H