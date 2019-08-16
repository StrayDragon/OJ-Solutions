// ---
// id         : 1028
// title      : List Sorting
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>

#define ALL(x) begin(x), end(x)
using namespace std;

struct Record {
  int id, grade;
  string name;
};

bool policy1(const Record& lhs, const Record& rhs) {
  return lhs.id < rhs.id;
}

bool policy2(const Record& lhs, const Record& rhs) {
  return (lhs.name == rhs.name) ? lhs.id < rhs.id : lhs.name < rhs.name;
}

bool policy3(const Record& lhs, const Record& rhs) {
  return (lhs.grade == rhs.grade) ? lhs.id < rhs.id : lhs.grade < rhs.grade;
}

int main() {
  int n, c;
  cin >> n >> c;

  vector<Record> records;
  for (Record t; n--;) {
    cin >> t.id >> t.name >> t.grade;
    records.push_back(t);
  }

  switch (c) {
    case 1:
      sort(ALL(records), policy1);
      break;
    case 2:
      sort(ALL(records), policy2);
      break;
    case 3:
      sort(ALL(records), policy3);
      break;
    default:
      break;
  }

  for (Record& t : records)
    printf("%06d %s %d\n", t.id, t.name.c_str(), t.grade);
  return 0;
}