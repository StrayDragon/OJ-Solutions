#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n, p;
  cin >> n >> p;

  vector<int> vi;
  for (int i; n-- && cin >> i;)
    vi.push_back(i);
  std::sort(vi.begin(), vi.end());

  int result = 0;
  for (int tmp = 0, i = 0; i < vi.size(); i++) {
    for (int j = i + result; j < vi.size(); j++) {
      if (vi[j] <= vi[i] * p) {
        tmp = j - i + 1;
        if (tmp > result)
          result = tmp;
      } else {
        break;
      }
    }
  }

  cout << result;
  return 0;
}