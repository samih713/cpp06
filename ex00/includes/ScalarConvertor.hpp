/* includes */
#include <string>
#include <vector>

#ifndef SCALARCONVERTOR_HPP
#define SCALARCONVERTOR_HPP

/* macros */
#if defined(__DEBUG__)
#define DEBUG_PRINT(x) (std::cerr << x << std::endl)
#else
#define DEBUG_PRINT(x)
#endif // (__DEBUG__)

#define PRECISION 8

/* using */
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
