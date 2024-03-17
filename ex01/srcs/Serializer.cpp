#include "Serializer.hpp"
#include <assert.h>

#define DONT_USE (assert(false && "Told you don't use"));

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

// DONT_USE
Serializer::Serializer(){ DONT_USE }

Serializer::~Serializer(){ DONT_USE }

Serializer::Serializer(const Serializer &){ DONT_USE }

Serializer &Serializer::operator=(const Serializer &)
{
    DONT_USE
}
