#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data original;
    original.id = 123;
    original.name = "Test Data";
    original.value = 456.78f;

    // Serializamos el puntero
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized: " << raw << std::endl;
	
    // Deserializamos el puntero
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized: " << deserialized << std::endl;

    // Verificamos que el puntero deserializado es igual al original
    if (deserialized == &original) {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "ID: " << deserialized->id << std::endl;
        std::cout << "Name: " << deserialized->name << std::endl;
        std::cout << "Value: " << deserialized->value << std::endl;
    } else {
        std::cout << "Deserialization failed!" << std::endl;
    }

    return 0;
}
