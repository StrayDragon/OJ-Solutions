#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n, k;
  // scanf("%d%d\n", &n, &k);
  cin >> n >> k;
  // cin.ignore();

  unordered_map<string, vector<int>> dict;
  for (int course_id, _ /*registed_student*/; k--;) {
    // scanf("%d%d\n", &course_id, &_);
    cin >> course_id >> _;
    // cin.ignore();
    // string sink;
    // std::getline(cin, sink, '\n');
    // stringstream stream(sink);
    // for (string student; stream >> student;)
    //   dict[student].push_back(course_id);
    for (string student; _--;) {
      cin >> student;
      dict[student].push_back(course_id);
    }
  }
  // cin.ignore();
  // string sink;
  // std::getline(cin, sink, '\n');
  // stringstream stream(sink);
  // for (string student; stream >> student;) {
  for (string student; cin >> student;) {
    auto ids = dict[student];
    std::sort(ids.begin(), ids.end());
    // printf("%s %lu", student.c_str(), ids.size());
    cout << student << " " << ids.size();
    for (const auto& id : ids)
      // printf(" %d", id);
      cout << " " << id;
    // putchar('\n');
    cout << '\n';
  }

  return 0;
}