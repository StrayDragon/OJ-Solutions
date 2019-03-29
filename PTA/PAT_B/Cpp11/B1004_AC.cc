#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
  string name;
  string number;
  int score;
};

int main() {
  int n;
  cin >> n;
  vector<Student> students;
  for (int i = 0; i < n; ++i) {
    Student s;
    cin >> s.name >> s.number >> s.score;
    students.push_back(s);
  }
  sort(students.begin(), students.end(),
       [](Student s1, Student s2) { return s1.score < s2.score; });

  cout << students[students.size() - 1].name << " "
       << students[students.size() - 1].number << '\n';
  cout << students[0].name << " " << students[0].number << '\n';

  return 0;
}