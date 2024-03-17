#include "Detector.hpp"
#include "string"

#ifndef TYPEWRAPPER_HPP
#define TYPEWRAPPER_HPP

using std::string;

typedef string *t_special;

class TypeWrapper
{
    public:
        TypeWrapper(const string &input);
        ~TypeWrapper();
        operator int() const;
        operator char() const;
        operator float() const;
        operator double() const;

    private:
        union _value
        {
                char        c;
                long long   i;
                long double d;
                long double f;
                t_special   s;
        } value;
        Type type;
        TypeWrapper(const TypeWrapper &);
        TypeWrapper &operator=(const TypeWrapper &);
};

#endif // TYPEWRAPPER_HPP
