#include "TypeWrapper.hpp"
#include "sstream"
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>

#include <cstdio>

using std::cout;
using std::istringstream;
using std::runtime_error;

TypeWrapper::TypeWrapper(const string &input)
{
    Detector detect;
    type = detect(input);
    try
    {
        switch (type)
        {
            case CHAR: value.c = input[0]; break;
            case Q_CHAR: value.c = input[1]; break;
            case INT:
            {
                istringstream iss(input);
                iss >> std::noskipws;
                if (!(iss >> value.i && iss.eof()))
                    throw runtime_error("\nint failed");
                if (value.i > std::numeric_limits<int>::max() ||
                    value.i < std::numeric_limits<int>::min())
                    throw runtime_error("\nfint failed");
                break;
            }
            case I_FLOAT:
            case FLOAT:
            {
                string        temp(input.substr(0, input.length() - 1));
                istringstream iss(temp);
                iss >> std::noskipws;
                if (!(iss >> value.f && iss.eof()))
                    throw runtime_error("\nfloat failed");
                if (value.f < (-1.0f * std::numeric_limits<float>::max()) ||
                    value.f > std::numeric_limits<float>::max())
                    throw runtime_error("\nfloat failed");
                break;
            }
            case I_DOUBLE:
            case DOUBLE:
            {
                istringstream iss(input);
                iss >> std::noskipws;
                if (!(iss >> value.d && iss.eof()))
                    throw runtime_error("\ndouble failed");
                if (value.d > std::numeric_limits<double>::max() ||
                    value.d < (-1.0 * std::numeric_limits<double>::max()))
                    throw runtime_error("\ndouble failed");
                break;
            }
            case SPECIAL:
            case F_SPECIAL: value.s = new string(input); break;
            default: break;
        }
    }
    catch (runtime_error &e)
    {
        type = UNKNOWN;
    }
}

TypeWrapper::~TypeWrapper()
{
    if (type == SPECIAL || type == F_SPECIAL)
        delete value.s;
}

static char checkPrintable(int val)
{
    // worried about truncation
    if (val <= 255 && val >= 0)
    {
        if (isprint(val))
            return static_cast<char>(val);
        else
            throw runtime_error("Non displayble");
    }
    throw runtime_error("impossible");
}

// type cast overload char
TypeWrapper::operator char() const
{
    switch (type)
    {
        case CHAR:
        case Q_CHAR: return value.c;
        case INT: return checkPrintable(value.i);

        case I_FLOAT: return checkPrintable(value.f);

        case I_DOUBLE: return checkPrintable(value.d);

        default: break;
    }
    throw runtime_error("impossible");
}

// type cast overload int
TypeWrapper::operator int() const
{
    switch (type)
    {
        case CHAR:
        case Q_CHAR: return static_cast<int>(value.c);
        case INT: return value.i;

        case I_FLOAT: return static_cast<int>(value.f);

        case I_DOUBLE: return static_cast<int>(value.d);
        default: break;
    }
    throw runtime_error("impossible");
}

// type cast overload int
TypeWrapper::operator float() const
{
    std::cout.precision(PRECISION);
    switch (type)
    {
        case CHAR:
        case Q_CHAR: cout << static_cast<float>(value.c); throw runtime_error(".0f");
        case INT: cout << static_cast<float>(value.i); throw runtime_error(".0f");

        case I_FLOAT: cout << static_cast<float>(value.f); throw runtime_error(".0f");
        case FLOAT: cout << static_cast<float>(value.f); throw runtime_error("f");

        case I_DOUBLE: cout << static_cast<float>(value.d); throw runtime_error(".0f");
        case DOUBLE: cout << static_cast<float>(value.d); throw runtime_error("f");

        case SPECIAL: throw runtime_error(*value.s + "f");
        case F_SPECIAL: throw runtime_error(*value.s);
        default: break;
    }
    throw runtime_error("impossible");
}

TypeWrapper::operator double() const
{
    std::cout.precision(PRECISION);
    switch (type)
    {
        case CHAR:
        case Q_CHAR: cout << static_cast<double>(value.c); throw runtime_error(".0");
        case INT: cout << static_cast<double>(value.i); throw runtime_error(".0");

        case I_FLOAT: cout << static_cast<double>(value.f); throw runtime_error(".0");
        case FLOAT: return static_cast<double>(value.f);

        case I_DOUBLE: cout << static_cast<double>(value.d); throw runtime_error(".0");
        case DOUBLE: return static_cast<double>(value.f);

        case SPECIAL: throw runtime_error(*value.s);
        case F_SPECIAL: throw runtime_error(value.s->substr(0, value.s->length() - 1));
        default: break;
    }
    throw runtime_error("impossible");
}
