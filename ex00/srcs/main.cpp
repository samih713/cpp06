#include "ScalarConvertor.hpp"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "usage: " << argv[0] << " something to convert" << endl;
        return 0;
    }
    ScalarConvertor::convert(argv[1]);

#if 0
    cout << "Test case 5: [1000]" << endl;
    ScalarConvertor::convert("0"); // Min int value
    cout << endl;
	k
    cout << "Test case x: [10f]" << endl;
    ScalarConvertor::convert("10f");
    cout << endl;

    cout << "Test case 8: [-9182391873913]" << endl;
    ScalarConvertor::convert("-9182391873913");
    cout << endl;

    cout << "Test case 8: [-12323423424243242423f]" << endl;
    ScalarConvertor::convert("-12323423424243242423F");
    cout << endl;

    // // float test cases
    cout << "Test case 1: [10f]" << endl;
    ScalarConvertor::convert("10f");
    cout << endl;

    cout << "Test case 2: [.f]" << endl;
    ScalarConvertor::convert(".f");
    cout << endl;

    cout << "Test case 3: [25.4f]" << endl;
    ScalarConvertor::convert("25.4f");
    cout << endl;

    cout << "Test case 4: [.24.3f]" << endl;
    ScalarConvertor::convert(".24.3f");
    cout << endl;

    cout << "Test case 5: [-.6f]" << endl;
    ScalarConvertor::convert("-.6f");
    cout << endl;

    cout << "Test case 6: [.3ff]" << endl;
    ScalarConvertor::convert(".3ff");
    cout << endl;

    cout << "Test case 7: [.]" << endl;
    ScalarConvertor::convert(".");
    cout << endl;


    // Test cases basic
    cout << "Test case 1: [1f]" << endl;
    ScalarConvertor::convert("1f");
    cout << endl;

    cout << "Test case 2: ['b']" << endl;
    ScalarConvertor::convert("'b'");
    cout << endl;

    cout << "Test case 3: [0]" << endl;
    ScalarConvertor::convert("0");
    cout << endl;

    // // // Test cases for int conversions
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

    // // Test cases for special strings
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
#endif // 0

    return 0;
}
