// ---
// id         : 1036_2
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

#define HIGHEST 101
#define LOWEST -1

struct Student {
  string name;
  string id;
  int grade;
} M, F, t;

int main() {
  int n;
  cin >> n;

  M.grade = HIGHEST;
  F.grade = LOWEST;
  for (char gender; n--;) {
    cin >> t.name >> gender >> t.id >> t.grade;
    if (gender == 'M' && t.grade < M.grade)
      M = t;
    else if (gender == 'F' && t.grade > F.grade)
      F = t;
  }

  if (F.grade == LOWEST)
    cout << "Absent\n";
  else
    cout << F.name << " " << F.id << '\n';
  if (M.grade == HIGHEST)
    cout << "Absent\n";
  else
    cout << M.name << " " << M.id << '\n';
  if (F.grade == LOWEST || M.grade == HIGHEST)
    cout << "NA\n";
  else
    cout << (F.grade - M.grade) << '\n';

  return 0;
}