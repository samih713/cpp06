#include "ScalarConvertor.hpp"
#include "Detector.hpp"
#include "TypeWrapper.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::runtime_error;

void ScalarConvertor::convert(const string &input)
{
    TypeWrapper typeWrapper(input);
    try
    {
        cout << "char: " << static_cast<char>(typeWrapper) << endl;
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << "int: " << static_cast<int>(typeWrapper) << endl;
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << "float: " << static_cast<float>(typeWrapper) << endl;
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << "double: " << static_cast<double>(typeWrapper) << endl;
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }
}
