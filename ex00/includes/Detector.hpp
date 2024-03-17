#include "ScalarConvertor.hpp"
#include "string"

#ifndef DETECTOR_HPP
#define DETECTOR_HPP

using std::string;

enum Type
{
    CHAR,   // char
    Q_CHAR, // quoted char
    INT,    // int

    FLOAT,   // float
    I_FLOAT, // float (convertable to int)

    DOUBLE,   // double
    I_DOUBLE, // double (convertable to int)

    SPECIAL,   // double special
    F_SPECIAL, // float specia
    UNKNOWN
};

class Detector
{
    public:
        Detector();
        ~Detector();
        Type operator()(const std::string &input);

    private:
        Detector(const Detector &);
        Detector &operator=(const Detector &);
};

#endif // DETECTOR_HPP
