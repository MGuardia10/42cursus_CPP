#pragma once

#include <iostream>
#include <cstdint> // uintptr_t
#include "Data.hpp"

class Serializer {
	private:
		Serializer();
		Serializer( const Serializer& other );
		~Serializer();

	public:
		Serializer& operator=( const Serializer& other );
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};