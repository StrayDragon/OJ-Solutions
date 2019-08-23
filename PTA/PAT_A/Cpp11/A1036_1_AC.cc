// ---
// id         : 1036_1
// title      : Boys vs Girls
// difficulty : Medium
// score      : 25
// tag        : Simple Simulation
// keyword    : minimax
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ALL(x) begin(x), end(x)

struct Student {
  string name;
  char gender;
  string id;
  int grade;
  bool operator<(const Student& other) { return grade < other.grade; }
};

int main() {
  int n;
  cin >> n;

  vector<Student> students;
  for (Student t; n--;) {
    cin >> t.name >> t.gender >> t.id >> t.grade;
    students.push_back(t);
  }

  sort(ALL(students));

  string result;

  bool is_absent1 = true;
  int grade_f;
  for (int i = students.size(); i >= 0; --i) {
    if (students[i].gender == 'F') {
      result += students[i].name + " " + students[i].id + "\n";
      is_absent1 = false;
      grade_f = students[i].grade;
      break;
    }
  }

  if (is_absent1) {
    result += "Absent\n";
  }

  int grade_m;
  int is_absent2 = true;
  for (auto& student : students) {
    if (student.gender == 'M') {
      result += student.name + " " + student.id + "\n";
      is_absent2 = false;
      grade_m = student.grade;
      break;
    }
  }

  if (is_absent2) {
    result += "Absent\n";
  }

  cout << result;
  if (is_absent1 || is_absent2) {
    cout << "NA\n";
  } else {
    cout << grade_f - grade_m << '\n';
  }

  return 0;
}