#include "ScalarConvertor.hpp"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

int main()
{
    // // Test cases basic
    cout << "Test case 1: [c]" << endl;
    ScalarConvertor::convert("c");
    cout << endl;

    cout << "Test case 2: ['b']" << endl;
    ScalarConvertor::convert("'b'");
    cout << endl;

    cout << "Test case 3: [0]" << endl;
    ScalarConvertor::convert("0");
    cout << endl;

    // // Test cases for int conversions
    cout << "Test case 4: [2147483647]" << endl;
    ScalarConvertor::convert("2147483647"); // Max int value
    cout << endl;

    cout << "Test case 5: [-2147483648]" << endl;
    ScalarConvertor::convert("-2147483648"); // Min int value
    cout << endl;

    cout << "Test case 6: [2147483648]" << endl;
    ScalarConvertor::convert("2147483648"); // Above max int value
    cout << endl;

    cout << "Test case 7: [-2147483649]" << endl;
    ScalarConvertor::convert("-2147483649"); // Below min int value
    cout << endl;

    // Test cases for special strings
    cout << "Test case 8: [-inff]" << endl;
    ScalarConvertor::convert("-inff");
    cout << endl;

    cout << "Test case 9: [+inff]" << endl;
    ScalarConvertor::convert("+inff");
    cout << endl;

    cout << "Test case 10: [nanf]" << endl;
    ScalarConvertor::convert("nanf");
    cout << endl;

    cout << "Test case 11: [-inf]" << endl;
    ScalarConvertor::convert("-inf");
    cout << endl;

    cout << "Test case 12: [+inf]" << endl;
    ScalarConvertor::convert("+inf");
    cout << endl;

    cout << "Test case 13: [nan]" << endl;
    ScalarConvertor::convert("nan");
    cout << endl;

    cout << "Test case 14: [-2147 something]" << endl;
    ScalarConvertor::convert("-2147 something"); // more than numbers // cout << endl;
    cout << endl;

    cout << "Test case 15: [-2147something]" << endl;
    ScalarConvertor::convert("-2147something"); // more than numbers no space
    cout << endl;

    cout << "Test case 16: [something-2147]" << endl;
    ScalarConvertor::convert("something-2147"); // more than numbers no space
    cout << endl;

    cout << "Test case 17: [--2147]" << endl;
    ScalarConvertor::convert("--2147"); // invalid sign
    cout << endl;

    cout << "Test case 18: [2147    ]" << endl;
    ScalarConvertor::convert("2147    "); // spcaes
    cout << endl;

    cout << "Test case 19: [    2147]" << endl;
    ScalarConvertor::convert("    2147"); // spcaes
    cout << endl;

    return 0;
}
