#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int fold(vector<int>& lens, int max_len) {
  std::sort(lens.begin(), lens.end());
  int result = (lens[0] + lens[1]) / 2;
  for (int i = 2; i < lens.size(); i++) {
    if (result > max_len)
      break;
    result = (result + lens[i]) / 2;
  }
  return result;
}

int main() {
  int n, max_len = 0;
  cin >> n;

  vector<int> lens;
  for (int len; n-- && cin >> len;) {
    lens.push_back(len);
    if (max_len < len) {
      max_len = len;
    }
  }

  cout << fold(lens, max_len);
  return 0;
}