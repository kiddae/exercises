#include <iostream>
#include <vector>

bool valid_braces(std::string braces) {
  std::vector<char> s;
  for (char i : braces) {
    switch (i) {
    case '(':
      s.push_back(')');
      break;
    case '{':
      s.push_back('}');
      break;
    case '[':
      s.push_back(']');
      break;
    case ']':
    case '}':
    case ')':
      if (s.empty() || s.back() != i) // illegal if close brace before opening,
                                      // or if wrong opening brace
        return false;
      s.pop_back();
    }
  }
  return s.empty();
}

int main() {
  std::cout << valid_braces("(()") << std::endl;
  return 0;
}
