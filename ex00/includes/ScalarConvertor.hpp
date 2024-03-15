#include <string>
#include <vector>

#ifndef SCALARCONVERTOR_HPP
#define SCALARCONVERTOR_HPP

/* macros */
#if defined(__DEBUG__)
#define DEBUG_PRINT(x) (cerr << x << endl)
#else
#define DEBUG_PRINT(x)
#endif // (__DEBUG__)

#define INFO_MSG(type) ("Conversion to " #type " not possible")
/* macros */

using std::string;

class ScalarConvertor
{

    public:
        static void convert(const string &);

    private:
        ScalarConvertor();
        ~ScalarConvertor();
        ScalarConvertor(const ScalarConvertor &);
        ScalarConvertor &operator=(const ScalarConvertor &);
};

#endif // SCALARCONVERTOR_HPP
