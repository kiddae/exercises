#include <iostream>
#include <math.h>

void prime_factors(long n)
{
    int p = 2;
    while (p <= std::sqrt(n))
    {
        if (n%p == 0)
        {
            std::cout << p << " * ";
            n /= p;
        }
        else
        {
            p++;
        }
    }
    if (n>1) std::cout << n;
}

int main()
{
    prime_factors(600851475143);
}
