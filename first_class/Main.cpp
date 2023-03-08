#include <iostream>
#include <cstdlib>
#include <cstring>

#define Log(x) std::cout << x << std::endl;

void increment(int * value)
{
   (*value)++;
}

void increment_ref(int& value)
{
   value++;
}

int main()
{
    int a = 5;
    increment(&a);
    Log(a);
    a = 5;
    increment_ref(a);
    Log(a);
    return 0;
}