#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAXD = '9' + 10;

string num_to_en[MAXD];

string sum_of_digits(const string& digits) {
  vector<int> d;
  int n;
  for (auto& digit : digits) {
    int addend = int(digit - '0');
    if (d.empty())
      d.push_back(addend);
    else {
      for (int i = 0, tmp_sum = d[i] + addend;;) {
        d[i] = tmp_sum % 10;
        if (tmp_sum / 10 == 0)
          break;
        else {
          if (i == d.size() - 1) {
            d.push_back(1);
            break;
          } else {
            tmp_sum = d[i + 1] + 1;
            i++;
          }
        }
      }
    }
  }
  string sum = "";
  for (auto rit = d.rbegin(); rit != d.rend(); ++rit) {
    sum += '0' + *rit;
  }
  return sum;
}

int main() {
  num_to_en['0'] = "zero";
  num_to_en['1'] = "one";
  num_to_en['2'] = "two";
  num_to_en['3'] = "three";
  num_to_en['4'] = "four";
  num_to_en['5'] = "five";
  num_to_en['6'] = "six";
  num_to_en['7'] = "seven";
  num_to_en['8'] = "eight";
  num_to_en['9'] = "nine";

  string digits;
  cin >> digits;

  string result = sum_of_digits(digits);

  cout << num_to_en[result[0]];
  for (auto it = result.begin() + 1; it < result.end(); ++it) {
    cout << " " << num_to_en[*it];
  }

  return 0;
}