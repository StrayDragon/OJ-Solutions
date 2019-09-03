// ---
// id         : 1092
// title      : To Buy or Not to Buy
// difficulty : Easy
// score      : 20
// tag        : Primary Algorithm
// keyword    : string; find
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  string _beads, beads;
  cin >> _beads >> beads;

  unordered_map<char, int> shop;
  for (auto& bead : _beads) shop[bead]++;

  bool sufficient = true;
  int cnt = 0;
  for (auto& bead : beads) {
    if (shop.find(bead) == shop.end() || shop[bead] == 0) {
      sufficient = false;
      cnt++;
    } else {
      shop[bead]--;
    }
  }

  cout << (sufficient ? "Yes" : "No") << " "
       << (sufficient ? _beads.size() - beads.size() : cnt);
  return 0;
}