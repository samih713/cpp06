#include "Data.hpp"
#include "Serializer.hpp"
#include "iostream"

using std::cout;
using std::endl;

int main()
{
    Data test("Samih Kamal");

    cout << "serialize" << endl;
    uintptr_t address = Serializer::serialize(&test);
    cout << address << endl;

    cout << "deserialize" << endl;
    Data *access = Serializer::deserialize(address);
    cout << access->str();
}
