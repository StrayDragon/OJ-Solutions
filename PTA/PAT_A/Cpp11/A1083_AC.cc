// ---
// id         : 1083
// title      : List Grades
// difficulty : Medium
// score      : 25
// tag        : Primary Algorithm
// keyword    : sort
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

using Student = tuple<string, string, int>;

int main() {
  int n;
  cin >> n;

  vector<Student> students;
  int grade, grade1, grade2;
  for (string name, id; n--;) {
    cin >> name >> id >> grade;
    students.push_back(make_tuple(name, id, grade));
  }
  cin >> grade1 >> grade2;
  std::sort(students.begin(), students.end(), [](Student& lhs, Student& rhs) {
    return std::get<2>(lhs) > std::get<2>(rhs);
  });

  bool not_matched = true;
  for (auto& it : students) {
    if (grade1 <= std::get<2>(it) && std::get<2>(it) <= grade2) {
      cout << std::get<0>(it) << " " << std::get<1>(it) << '\n';
      not_matched = false;
    }
  }

  if (not_matched)
    cout << "NONE\n";
}