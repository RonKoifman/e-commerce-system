#ifndef __ARRAY_H
#define __ARRAY

#include "OutResources.h"

// This template Array class accepts a pointer type which its class must has an operator<<

template<class T>
class Array
{
private:
	T* arr;
	int size;

public:
	Array() : arr(nullptr), size(0) {} // C'tor
	~Array() { delete[] arr; } // D'tor
	Array(const Array& other) = delete; // Disable copy c'tor
	const Array& operator=(const Array& other) = delete; // Disable operator=
	T& operator[](int index) { return arr[index]; }
	const Array& operator+=(T& newVal);
	// Getters
	T* getArr() const { return arr; }
	int getSize() const { return size; }

	// Friend functions
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
			for (int i = 0; i < arr.size; i++)
			{
				os << i + 1 << ".";
				os << *arr.arr[i] << endl;
			}
		}
		return os;
	}
};

template<class T>
const Array<T>& Array<T>::operator+=(T& newVal)
{
	T* temp = new T[size + 1]; // Create bigger array to add the new value

	// Move the pointers from the current array to temp
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = newVal; // Add the new value
	size++;

	delete[] arr; // Free the current array
	arr = temp; // Update array to temp
	return *this;
}

#endif // __ARRAY_H