#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

using namespace std;
using qq_num_t = long long;

int main() {
  int n;
  cin >> n;
  char cmd;
  qq_num_t qq;
  string passwd;
  unordered_map<qq_num_t, string> dict;
  while (n--) {
    cin >> cmd >> qq >> passwd;
    getchar();
    switch (cmd) {
      case 'L':
        if (dict.find(qq) != dict.end()) {
          if (passwd != dict[qq]) {
            cout << "ERROR: Wrong PW\n";
          } else {
            cout << "Login: OK\n";
          }
        } else {
          cout << "ERROR: Not Exist\n";
        }
        break;
      case 'N':
        if (dict.find(qq) != dict.end()) {
          cout << "ERROR: Exist\n";
        } else {
          dict[qq] = passwd;
          cout << "New: OK\n";
        }
        break;
    }
  }
  return 0;
}