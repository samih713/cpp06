#include "Detector.hpp"
#include <cctype>
#include <cmath>
#include <sstream>

using std::istringstream;
using std::string;


Detector::Detector()
{}
Detector::~Detector()
{}

static Type is_special(const string &input)
{
    if (input == "nan" || input == "-inf" || input == "+inf")
        return SPECIAL;
    if (input == "nanf" || input == "-inff" || input == "+inff")
        return F_SPECIAL;
    return UNKNOWN;
}

static Type is_char(const string &input)
{
    if (input.length() == 1 && std::isprint(input[0]))
        return CHAR;
    else if (input.length() == 3 && *input.begin() == '\'' && *(input.end() - 1) == '\'')
        return Q_CHAR;
    else
        return UNKNOWN;
}

static Type is_digit(const string &input)
{
    bool hasDecimal = false;
    bool hasF = false;
    bool allZero = false;

    for (size_t i = 0; i < input.length(); ++i)
    {
        if (input[i] == '.')
        {
            if (hasDecimal)
                return UNKNOWN;
            hasDecimal = true;
            allZero = true;
        }
        else if (i > 0 && std::tolower(input[i]) == 'f' && i == input.length() - 1)
            hasF = true;
        else if (!std::isdigit(input[i]) &&
                 !(i == 0 && (input[i] == '-' || input[i] == '+')))
            return UNKNOWN;
        else if (input[i] != '0' && allZero)
            allZero = false;
    }
    if ((input.length() > 2 && input[input.length() - (hasF ? 2 : 1)] == '.') ||
        (hasDecimal && allZero) || (hasF && allZero) || (hasF && !hasDecimal))
        return hasF ? I_FLOAT : I_DOUBLE;
    else if (hasDecimal && !allZero)
        return hasF ? FLOAT : DOUBLE;
    else
        return INT;
}

Type Detector::operator()(const string &input)
{

    // check if its special
    Type type = is_special(input);
    if (type != UNKNOWN)
        return type;

    // check if its a number
    type = is_digit(input);
    if (type != UNKNOWN)
        return type;

    // check if its a char
    type = is_char(input);
    if (type != UNKNOWN)
        return type;

    // else its unknown
    return UNKNOWN;
}
