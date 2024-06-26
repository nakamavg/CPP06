#include <cstdlib>
#include <ctime>  
#include <iostream>

class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};



Base *generate() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int choice = std::rand() % 3; 

    switch (choice) {
        case 0:
		{
			std::cout << "Generated A" << std::endl;
            return new A();
		}

		case 1:
		{
			std::cout << "Generated B" << std::endl;
			return new B();
		}

		case 2:
		{
			std::cout << "Generated C" << std::endl;
			return new C();
		}
	}
	return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "Identified type: A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "Identified type: B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "Identified type: C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    identify(&p);
}

int main() {
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}