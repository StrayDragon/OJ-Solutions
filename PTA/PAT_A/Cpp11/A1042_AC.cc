// ---
// id         : 1042
// title      : Shuffling Machine
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<string> cards{""};
  auto sort_cards = [&] {
    array<string, 4> color{"S", "H", "C", "D"};
    for (int _ = 0; _ < 4; _++)
      for (int i = 1; i <= 13; i++)
        cards.push_back(color[_] + to_string(i));
    cards.push_back("J1");
    cards.push_back("J2");
  };
  sort_cards();

  vector<string> record(cards);
  vector<int> shufflings;
  int k;
  cin >> k;

  int next_pos;
  while (cin >> next_pos)
    shufflings.push_back(next_pos);
    
  while (k != 0) {
    int i = 1;
    for (auto&& next_pos : shufflings) {
      record[next_pos] = cards[i];
      i++;
    }
    cards = record;
    k--;
  }

  cout << record[1];

  for (auto it = record.begin() + 2; it != record.end(); ++it)
    cout << " " << *it;
  return 0;
}