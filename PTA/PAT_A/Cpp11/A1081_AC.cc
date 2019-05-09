#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

void add(pair<int, int>& fraction, const int first, const int second) {
  if (fraction.first == 0 && fraction.second == 0) {
    fraction.first = first;
    fraction.second = second;
    return;
  }
  int u = first * fraction.second + fraction.first * second;
  int d = second * fraction.second;
  fraction.first = u;
  fraction.second = d;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cin.ignore();

  string num;
  std::getline(cin, num);

  auto fraction = make_pair(0, 0);
  stringstream ss(num);
  for (int up, down, pos, factor; ss >> num;) {
    pos = num.find('/');
    up = stoi(num.substr(0, pos));
    down = stoi(num.substr(pos + 1));
    add(fraction, up, down);
    factor = std::abs(gcd(fraction.first, fraction.second));
    if (factor != 1) {
      fraction.first /= factor;
      fraction.second /= factor;
    }
  }
  int integer = fraction.first / fraction.second;
  int frist = fraction.first % fraction.second;
  if (integer && frist)
    cout << integer << ' ' << frist << '/' << fraction.second;
  else if (integer == 0 && frist)
    cout << frist << '/' << fraction.second;
  else
    cout << integer;
  return 0;
}