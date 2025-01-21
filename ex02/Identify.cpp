#include "includes/Identify.hpp"
#include <ctime>
#include <iostream>

Base::~Base()
{
}

Base *generate(void)
{
	switch (time(0) % 3) {
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer points to an object of type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer points to an object of type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer points to an object of type C" << std::endl;
    else
        std::cout << "Pointer points to an unknown object type" << std::endl;
}

void identify(Base &p)
{
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Reference is of type A" << std::endl;
    } catch (std::exception &e){
        try {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "Reference is of type B" << std::endl;
        } catch (std::exception &e){
            try {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "Reference is of type C" << std::endl;
            } catch (std::exception &e){
                std::cout << "Reference is of an unknown type" << std::endl;
            }
        }
    }
}


A::A()
{
}

B::B()
{
}

C::C()
{
}