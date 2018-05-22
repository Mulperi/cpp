#include <iostream>

void callBack()
{
    std::cout << "callback printing" << std::endl;
}

void someFunction(void (&cb)())
{
    cb();
}

int main()
{
    someFunction(callBack);

    return 0;
}