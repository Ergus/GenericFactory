
#include "Derived1.hpp"
#include "Derived2.hpp"

int main()
{

	Base *d1 = Base::construct(1, 1);
	Base *d2 = Base::construct(2, 2);

	d1->print();

	d2->print();

	delete d1;
	delete d2;

	return 0;
}
