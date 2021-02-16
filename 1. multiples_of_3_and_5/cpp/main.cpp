#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int multiple_sum(int limit) {
  int sum = 0;
  for (int i = 0; i < limit; i++) {
    if (i % 3 == 0 or i % 5 == 0)
      sum += i;
  }
  return sum;
}

int main() {
  int a;
  cout << "What limit? ";
  cin >> a;
  cout << "Sum of multiples of 3 and 5 from 0 to " << a << ": "
       << multiple_sum(a) << endl;
}
