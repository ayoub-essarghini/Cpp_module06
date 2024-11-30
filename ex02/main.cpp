#include "includes/Identify.hpp"

int main() {



Base* base = new A();

Base& ref = *base;

    try{
        dynamic_cast<B&>(ref);
        std::cout << "done" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    // {
    //     Base* random = generate();
    //     std::cout << "Pointer test: ";
    //     identify(random); 
    //     delete random;
    // }

    // {
    //     Base* random = generate();
    //     Base& base = *random;
    //     std::cout << "Reference test: ";
    //     identify(base);
    //     delete random;
    // }
    return 0;
}