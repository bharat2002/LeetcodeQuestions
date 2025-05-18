#include <iostream>

int sumofNumbers(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n+sumofNumbers(n-1);
}

int main()
{
    std::cout<<"The sum of numbers"<<sumofNumbers(3);
}