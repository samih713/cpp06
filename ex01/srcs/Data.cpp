#include "Data.hpp"

Data::Data(const string &value)
    : value(value)
{
    // constructor code
}

Data::~Data()
{
    // destructor code
}

Data::Data(const Data &other)
    : value(other.value)
{}

Data &Data::operator=(const Data &other)
{
    this->value = other.value;
    return *this;
}

const string &Data::str() const
{
    return value;
}
