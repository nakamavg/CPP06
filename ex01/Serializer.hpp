#pragma once
#include <cstdint>
#include "Data.hpp"

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private:
    Serializer(); // Hacemos el constructor privado para prevenir la instanciación.
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
};

