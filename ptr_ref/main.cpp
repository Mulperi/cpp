// Pointer and reference stuff

#include <iostream>
#include <string>
using namespace std;

// & is the address-of operator, and can be read simply as "address of"
// * is the dereference operator, and can be read as "value pointed to by"

void getValues()
{
    int myvar = 25;
    int *foo = &myvar;

    cout << (myvar) << endl; // 25
    cout << (*foo) << endl;  // 25
}

void add(int &a) // Takes in a reference of int that is passed
{
    std::cout << a << std::endl;
    a++;
}

void square(int x, int &result) // Takes in a reference of int that is passed
{

    result = x * x; // Modifies the reference value
}

int &returningReference(int &x) // Returns a reference to a value
{

    return ++x; // "return x++;" would have been wrong
}

int main()
{

    string s1{"Test 1"};
    string *pointer1{&s1};     // Pointer1 POINTS to a VALUE in address of s1 so it's the same as s1
    cout << *pointer1 << endl; // Test 1

    string s2{"Test 2"};
    string &ref{s2};     // ref references to a variable s2
    cout << ref << endl; // Test 2

    int number{1};
    add(number);
    cout << number << endl; // 2

    int resultVariable;
    square(3, resultVariable);
    cout << resultVariable << endl; // 9

    int number2{2};
    cout << returningReference(number2) << endl; // 3

    int z = 1;
    int &x = z;
    x += 1;
    cout << x << endl; // 2

    getValues();

    return 0;
}