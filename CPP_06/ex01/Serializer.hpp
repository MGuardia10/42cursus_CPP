#pragma once

#include <iostream>
#include <stdint.h> // uintptr_t, <cstdint> not supported in c++98
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