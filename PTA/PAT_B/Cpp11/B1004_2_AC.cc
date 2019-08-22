#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct Record {
  string name, id;
  int score;
};

int main() {
  int n;
  cin >> n;
  vector<Record> records;
  for (Record r; n-- && cin >> r.name >> r.id >> r.score;) records.push_back(r);

  auto min_max_itr = std::minmax_element(
      records.begin(), records.end(),
      [](Record& a, Record& b) { return a.score < b.score; });

  cout << min_max_itr.second->name << " " << min_max_itr.second->id << '\n';
  cout << min_max_itr.first->name << " " << min_max_itr.first->id << '\n';
  return 0;
}