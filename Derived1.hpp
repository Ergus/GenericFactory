#pragma once

#include "Base.hpp"

class Derived1 : public Base
{
	int _value;
public:

	Derived1(int value)
		:_value(value)
	{
	}

	void print() const override
	{
		std::cout << "Derived1: " << _value << std::endl;
	}

};

// Aqui el 1 es basicamente el id de la clase que se construye.  El indice que
// tendria en el map, se puede usar otra cosa, pero lo hago sencillo para que se
// entienda

static const bool __attribute__((unused))_registered_derived1 =
	Base::RegisterDerivedClass<Derived1>(1);

