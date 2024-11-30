#include "includes/Identify.hpp"

int main()
{

 

    {
        Base *random = generate();
        std::cout << "Pointer test: ";
        identify(random);
        delete random;
    }

    {
        Base *random = generate();
        Base &base = *random;
        std::cout << "Reference test: ";
        identify(base);
        delete random;
    }
    return 0;
}