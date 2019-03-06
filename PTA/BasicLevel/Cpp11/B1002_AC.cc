#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  vector<string> num2hanzi{"ling", "yi",  "er", "san", "si",
                           "wu",   "liu", "qi", "ba",  "jiu"};
  string num;
  cin >> num;
  int sum = 0;

  while (not num.empty()) {
    sum += (num.back() - '0');
    num.pop_back();
  }

  vector<string> result;
  while (sum != 0) {
    result.push_back(num2hanzi[sum % 10]);
    sum /= 10;
  }

  cout << result.back();
  result.pop_back();
  for (auto it = result.rbegin(); it < result.rend(); ++it) {
    cout << " " << *it;
  }

  return 0;
}