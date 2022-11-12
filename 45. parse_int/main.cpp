#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

template <class T> void test(T a, T b) {
  std::cout << a << " " << b << ": " << (a == b) << std::endl;
}

std::string implode(std::vector<std::string>::iterator a,
                    std::vector<std::string>::iterator b) {
  // Implode vector of strings to " " delimited string
  auto v = std::vector<std::string>(a, b);
  std::ostringstream imploded;
  std::copy(v.begin(), v.end(),
            std::ostream_iterator<std::string>(imploded, " "));
  return imploded.str();
}

std::vector<std::string> split(std::string s, const std::string &del,
                               const std::string &del2) {
  // Split string into vector
  std::vector<std::string> output;
  size_t pos;
  while ((pos = s.find(del) < s.find(del2) ? s.find(del) : s.find(del2)) !=
         std::string::npos) {
    output.push_back(s.substr(0, pos));
    s.erase(0, pos + del.length());
  }
  output.push_back(s);
  return output;
}

long parse_int(std::string number) {
  std::map<std::string, int> defined = {
      {"one", 1},        {"two", 2},       {"three", 3},     {"four", 4},
      {"five", 5},       {"six", 6},       {"seven", 7},     {"eight", 8},
      {"nine", 9},       {"ten", 10},      {"eleven", 11},   {"twelve", 12},
      {"thirteen", 13},  {"fourteen", 14}, {"fifteen", 15},  {"sixteen", 16},
      {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, {"ten", 10},
      {"twenty", 20},    {"thirty", 30},   {"forty", 40},    {"fifty", 50},
      {"sixty", 60},     {"seventy", 70},  {"eighty", 80},   {"ninety", 90},
  };
  std::vector<std::string> bases = split(number, " ", "-");
  long output = 0;
  for (int i = bases.size() - 1; i >= 0; i--) {
    if (bases[i] == "and")
      continue;
    if (defined.find(bases[i]) != defined.end())
      output += defined.find(bases[i])->second;
    else if (bases[i] == "hundred") {
      auto nextit = std::find(bases.begin(), bases.end(), "thousand") + 1;
      if (nextit - 1 == bases.end()) {
        nextit = bases.begin();
      }
      output += 100 * parse_int(implode(nextit, bases.begin() + i));
      i = nextit - bases.begin();
    } else if (bases[i] == "thousand") {
      output += 1000 * parse_int(implode(bases.begin(), bases.begin() + i));
      i = bases.begin() - bases.begin();
    } else if (bases[i] == "million")
      return 1000000;
    else if (bases[i] == "zero")
      return 0;
  }
  return output;
}

int main() {
  test<long>(parse_int("one thousand three hundred thirty-seven"), 1337);
  test<long>(parse_int("two hundred and forty-six"), 246);
  test<long>(parse_int("twenty-six thousand three hundred and fifty-nine"),
             26359);
  test<long>(
      parse_int(
          "seven hundred eighty-three thousand nine hundred and nineteen"),
      783919);
  return 0;
}
