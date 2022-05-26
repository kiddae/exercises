#include <iostream>
using namespace std;

int even_fib(int n) {
  int *fib = new int[n];
  fib[0] = 0, fib[1] = 1;
  int sum = 0;
  for (int i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    sum += (fib[i] % 2 == 0) ? fib[i] : 0;
  }
  delete[] fib;
  return sum;
}

int main() {
  cout << "What limit? ";
  int a;
  cin >> a;
  cout << "Sum of all even values of the Fibonacci sequence up to " << a << ": "
       << even_fib(a) << endl;
}
