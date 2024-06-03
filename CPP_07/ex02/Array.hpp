#pragma once

#include <iostream>

template <typename T>
class Array {
	private:
		T 		*arr;
		size_t	length;

	public:
		/* OCCF */
		Array(): arr(NULL), length(0) {}

		Array( unsigned int n ): arr(new T[n]), length(n) {}

		Array ( const Array& other ) {
			*this = other;
		}

		Array& operator=( const Array& other ) {
			if (this != &other) {
				length = other.length;
				arr = new T[length];
				for (size_t i = 0; i < length; i++) {
					arr[i] = other.arr[i];
				}
			}

			return *this;
		}

		~Array() { delete[] arr; }

		// operator []
		T& operator[]( size_t index ) {
			if ( index >= length)
				throw std::out_of_range("Index is out of range");

			return this->arr[index];
		}

		// size getter
		size_t size() const { return this->length; }
};
