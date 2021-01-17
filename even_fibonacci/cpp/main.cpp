#include <iostream>
using namespace std;

int fib(int n)
{
    // Returns the nth number of the Fibonacci sequence
    if (n <= 1) return n;
    else return fib(n-1) + fib(n-2);
}

int even_fib(int n)
{
    // Returns the sum of all the even numbers in the
    // nth first values of the Fibonacci sequence
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        if (fib(i) % 2 == 0) sum += fib(i);
    }
    return sum;
}

int main()
{
    cout << even_fib(10) << endl;
}
