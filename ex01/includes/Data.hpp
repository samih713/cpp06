#include <string>

#ifndef DATA_HPP
#define DATA_HPP

using std::string;

class Data
{

    public:
        Data(const string &value);
        ~Data();
        Data(const Data &other);
        Data         &operator=(const Data &other);
        const string &str() const;

    private:
        string value;
};

#endif // DATA_HPP
