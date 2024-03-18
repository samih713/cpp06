#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "iostream"

using std::cout;
using std::endl;

int main()
{
    identify(generate()); // pointer

    identify(*generate()); // reference

    return 0;
}
