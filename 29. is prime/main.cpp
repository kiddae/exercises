#include <iostream>

bool isPrime(int num) {
  if (num <= 1)
    return false;
  for (long i = 2; i * i <= num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int main() {
  std::cout << (isPrime(25) == false) << std::endl;
  std::cout << (isPrime(3) == true) << std::endl;
  std::cout << (isPrime(5) == true) << std::endl;
  std::cout << (isPrime(6) == false) << std::endl;
  std::cout << (isPrime(2147483647) == true) << std::endl;
  return 0;
}
