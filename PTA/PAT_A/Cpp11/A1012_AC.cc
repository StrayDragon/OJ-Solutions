// ---
// id         : 1012
// title      : The Best Rank
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 2001;
enum { A = 0, C = 1, M = 2, E = 3 };
struct Student {
  int id, best;
  int grade[4], rank[4];
} students[MAXN];
int exist[1000010];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> students[i].id >> students[i].grade[C] >> students[i].grade[M] >>
        students[i].grade[E];
    students[i].grade[A] =
        (students[i].grade[C] + students[i].grade[M] + students[i].grade[E]) /
        3.0;
  }

  for (int I : {A, C, M, E}) {
    std::sort(students, students + MAXN,
              [&](const Student& lhs, const Student& rhs) {
                return lhs.grade[I] > rhs.grade[I];
              });
    students[0].rank[I] = 1;
    for (int i = 1; i < n; i++) {
      students[i].rank[I] = i + 1;
      if (students[i].grade[I] == students[i - 1].grade[I]) {
        students[i].rank[I] = students[i - 1].rank[I];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    exist[students[i].id] = i + 1;
    students[i].best = 0;
    int minrank = students[i].rank[A];
    for (int I : {C, M, E}) {
      if (students[i].rank[I] < minrank) {
        minrank = students[i].rank[I];
        students[i].best = I;
      }
    }
  }

  char c[] = {'A', 'C', 'M', 'E'};
  for (int id, tmp, best_i; m--;) {
    cin >> id;
    tmp = exist[id];
    if (tmp) {
      best_i = students[tmp - 1].best;
      cout << students[tmp - 1].rank[best_i] << " " << c[best_i] << '\n';
    } else {
      cout << "N/A\n";
    }
  }

  return 0;
}