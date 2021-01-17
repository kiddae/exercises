#include <iostream>
using namespace std;

int multiple_sum(int limit) {
  int sum = 0;
  for (int i = 0; i < limit; i++) {
    if (i % 3 == 0 or i % 5 == 0)
      sum += i;
  }
  return sum;
}

int main() {
  cout << "Sum of multiples of 3 and 5 from 0 to 10: " << multiple_sum(10)
       << endl;
  cout << "Sum of multiples of 3 and 5 from 0 to 1000: " << multiple_sum(1000)
       << endl;
}
