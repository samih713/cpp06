#include "ScalarConvertor.hpp"
#include <iostream>
#include <ostream>
#include <sstream>

using std::cout;
using std::endl;
using std::istringstream;

static const string INFORMATIVE_MESSAGE("Conversion not possible!");

static const char *is_special_string(const string &input);
static void        to_char(const string &input, char *const single_char);
static void        to_int(const string &input, const char singleChar);
static void        to_float(const string &input, const char singleChar);
static void        to_double(const string &input, const char singleChar);

void ScalarConvertor::convert(const string &input)
{
    char singleChar = 0;
    // char
    to_char(input, &singleChar);
    // int
    to_int(input, singleChar);
    // float
    to_float(input, singleChar);
    // double
    to_double(input, singleChar);
}

static const char *is_special_string(const string &input)
{
    if (input == "nanf" || input == "nan")
        return "nan";
    else if (input == "-inff" || input == "-inf")
        return "-inf";
    else if (input == "+inff" || input == "+inf")
        return "+inf";
    else
        return NULL;
}

static void to_char(const string &input, char *const single_char)
{
    cout << "char: ";

    if (input.length() == 1 && isprint(input[0]))
    {
        *single_char = static_cast<char>(input[0]);
        cout << *single_char << endl;
    }
    else if (input.length() == 3 &&
             (*input.begin() == '\'' && *(input.end() - 1) == '\'') && isprint(input[1]))
    {
        *single_char = static_cast<char>(input[1]);
        cout << *single_char << endl;
    }
    else
        cout << INFO_MSG(char) << endl;
}

static void to_int(const string &input, const char singleChar)
{
    cout << "int: ";

    if (singleChar)
        cout << static_cast<int>(singleChar) << endl;
    else
    {
        std::istringstream iss(input);
        iss >> std::noskipws;
        int number;
        if (iss >> number && iss.eof())
        {
            cout << number << endl;
        }
        else
        {
            cout << INFO_MSG(int) << endl;
        }
    }
}

static void to_float(const string &input, const char singleChar)
{
    const char *spString = is_special_string(input);

    cout << "float: ";

    if (singleChar)
        cout << static_cast<float>(singleChar) << ".0f" << endl;
    else if (spString)
        cout << spString << "f" << endl;
    else
    {
        std::istringstream iss(input);
        iss >> std::noskipws;
        float number;
        if (iss >> number && iss.eof())
        {
            cout << number << "f" << endl;
        }
        else
        {
            cout << INFO_MSG(float) << endl;
        }
    }
}

static void to_double(const string &input, const char singleChar)
{
    const char *spString = is_special_string(input);
    cout << "double: ";

    if (singleChar)
        cout << static_cast<double>(singleChar) << endl;
    else if (spString)
        cout << spString << endl;
    else
    {
        std::istringstream iss(input);
        iss >> std::noskipws;
        double number;
        if (iss >> number && iss.eof())
        {
            cout << number << endl;
        }
        else
        {
            cout << INFO_MSG(double) << endl;
        }
    }
}
