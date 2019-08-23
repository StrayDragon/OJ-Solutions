// ---
// id         : 1042
// title      : Shuffling Machine
// difficulty : Easy
// score      : 20
// tag        : Simple Simulation
// keyword    : mapping relationship; sort
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<string> cards{""};
  string color[]{"S", "H", "C", "D"};
  for (int _ = 0; _ < 4; _++)
    for (int i = 1; i <= 13; i++) cards.push_back(color[_] + to_string(i));
  cards.push_back("J1");
  cards.push_back("J2");
  vector<string> record(cards);

  int k;
  cin >> k;
  vector<int> next_pos_seq;
  for (int next_pos; cin >> next_pos;) next_pos_seq.push_back(next_pos);

  while (k--) {
    int i = 1;
    for (auto&& next_pos : next_pos_seq) {
      record[next_pos] = cards[i];
      i++;
    }
    cards = record;
  }

  for (int i = 1, len = record.size(); i <= len - 1; i++) {
    cout << record[i];
    if (i < len - 1) cout << " ";
  }
  return 0;
}