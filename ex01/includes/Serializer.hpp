#include "Data.hpp"
#include <stdint.h>

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

class Serializer
{
    public:
        static uintptr_t serialize(Data *ptr);
        static Data     *deserialize(uintptr_t raw);

    private:
        // DONT_USE
        Serializer();
        ~Serializer();
        Serializer(const Serializer &);
        Serializer &operator=(const Serializer &);
};

#endif // SERIALIZER_HPP
