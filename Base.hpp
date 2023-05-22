#pragma once

#include "GenericFactory.hpp"

#include <iostream>

// En una clase cualquiera solo necesitan tener una clase base en comun.

class Base
{
public:
	virtual ~Base()
	{
	}

	virtual void print() const
	{};

	// Esto es un wrapper sencillo para que el registro sea mas facil; pero no
	// es necesario... solo para simplificar.

	// Supongamos que solo recibo 1 argumento int... esto se puede hacer para
	// que reciba cualquier numero de argumentos, pero para que se entienda
	// mejor.
	template<typename T>
	static bool RegisterDerivedClass(int id)
	{
		// Ya sabes como soy con los assert.
		static_assert(std::is_base_of<Base, T>::value, "Base class is wrong.");

		// Hay que recordar hacer delete luego (o usar un unique_ptr)
		return GenericFactory<int, Base*, int>::getInstance().emplace(
			id,
			[](int value) -> Base* {
				return new T(value);
			}
		);
	}

	static Base *construct(int key, int value)
	{
		return GenericFactory<int, Base*, int>::getInstance().create(key, value);
	}
};
