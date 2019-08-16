// ---
// id         : 1137
// title      : Final Grading
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum { G, G_p, G_midterm, G_final };
struct Student {
  string id;
  int grades[4];

  Student() { std::fill(grades, grades + 4, -1); }
};

int main() {
  int p, m, n;
  cin >> p >> m >> n;

  unordered_map<string, Student> dict;
  for (Student s; p--;) {
    cin >> s.id >> s.grades[1];
    if (s.grades[G_p] >= 200) {
      dict[s.id] = s;
    }
  }

  for (Student s; m--;) {
    cin >> s.id >> s.grades[G_midterm];
    if (dict.find(s.id) != dict.end()) {
      dict[s.id].grades[G_midterm] = s.grades[G_midterm];
    }
  }

  for (Student s; n--;) {
    cin >> s.id >> s.grades[G_final];
    if (dict.find(s.id) != dict.end()) {
      dict[s.id].grades[G_final] = s.grades[G_final];
    }
  }

  vector<Student> students;
  for (auto& kv : dict) {
    int m = kv.second.grades[G_midterm];
    int f = kv.second.grades[G_final];
    int g = std::round((m > f) ? m * 0.4 + f * 0.6 : f);
    if (g >= 60) {
      kv.second.grades[G] = g;
      students.push_back(kv.second);
    }
  }

  std::sort(students.begin(), students.end(),
            [](const Student& lhs, const Student& rhs) {
              return (lhs.grades[G] != rhs.grades[G])
                         ? lhs.grades[G] > rhs.grades[G]
                         : lhs.id < rhs.id;
            });

  for (auto s : students) {
    printf("%s %d %d %d %d\n", s.id.c_str(), s.grades[G_p], s.grades[G_midterm],
           s.grades[G_final], s.grades[G]);
  }

  return 0;
}