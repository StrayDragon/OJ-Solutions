#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string zipped_passwords;
  for (int _ = 0; _ < n; _++) {
    string tmp;
    cin >> tmp;
    zipped_passwords += tmp;
    zipped_passwords += ' ';
  }

  int m;
  cin >> m;
  for (int case_cnt = 1; case_cnt <= m; case_cnt++) {
    cout << "Case #" << case_cnt << ":\n";
    string guess;
    cin >> guess;
    string::size_type pos = zipped_passwords.find(guess);
    if (pos == string::npos)
      cout << "NO\n";
    else
      cout << "YES\n";
  }

  return 0;
}