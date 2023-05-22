#pragma once

#include "Base.hpp"

class Derived2 : public Base
{
	int _value2;
public:

	Derived2(int value)
		:_value2(value)
	{
	}

	void print() const override
	{
		std::cout << "Derived2: " << _value2 << std::endl;
	}
};

// Aqui el 1 es basicamente el id de la clase que se construye.  El indice que
// tendria en el map, se puede usar otra cosa, pero lo hago sencillo para que se
// entienda

static const bool __attribute__((unused))_registered_derived2 =
	Base::RegisterDerivedClass<Derived2>(2);

