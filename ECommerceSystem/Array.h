#pragma once


#include "OutResources.h"
#include <typeinfo>

/***************************************************************************

This template Array class types must have a "<<" operator.
(We are using it only for feedback class and it has the relevant operator.)

****************************************************************************/

template<class T>
class Array
{
	int size;
	T** arr;
public:
	Array() { arr = nullptr; size = 0; }
	Array(const Array& other) = delete;
	T& operator[](int index) { return arr[index]; }
	const T& operator[](int index) const { return arr[index]; }
	const Array& operator+=(const T& newVal);
	
	//getters
	const int getSize() const { return size; }



	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		os << typeid(arr.arr + 6) << ": ";

		/*for (int i = 0; i < arr.size; i++)
			os << arr.arr[i];*/

		if (arr.size == 0)
		{
			os << "None." << endl;
		}
		else
		{
			os << endl;
			for (int i = 0; i < arr.size; i++)
			{
				os << i + 1 << ".";
				os << *arr[i] << endl;
			}
		}

		return os;
	}
};

template<class T>
const Array<T>& Array<T>::operator+=(const T& newVal)
{
	T** temp = new T*[size + 1]; // Create bigger array to add the new user

	// Move the pointers from the current array to temp
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = &newVal; // Add the new user
	size++;

	delete[] arr; // Free the current array
	arr = temp; // Update users array to temp
	return *this;
}
