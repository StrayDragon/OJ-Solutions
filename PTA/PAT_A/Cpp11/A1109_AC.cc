#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Student {
  string name;
  int height;
};

int main() {
  int n, k;
  cin >> n >> k;

  vector<Student> students(n);
  for (int i = 0; i < n; i++)
    cin >> students[i].name >> students[i].height;

  sort(students.begin(), students.end(), [](Student& lhs, Student& rhs) {
    return lhs.height != rhs.height ? lhs.height > rhs.height
                                    : lhs.name < rhs.name;
  });

  for (int m, j, t = 0, row = k; row;) {
    if (row == k)
      m = n - n / k * (k - 1);
    else
      m = n / k;
    vector<string> stemp(m);
    stemp[m / 2] = students[t].name;
    j = m / 2 - 1;
    for (int i = t + 1; i < t + m; i = i + 2)
      stemp[j--] = students[i].name;
    j = m / 2 + 1;
    for (int i = t + 2; i < t + m; i = i + 2)
      stemp[j++] = students[i].name;
    cout << stemp[0];
    for (int i = 1; i < m; i++)
      cout << " " << stemp[i];
    cout << endl;
    t = t + m;
    row--;
  }
  return 0;
}