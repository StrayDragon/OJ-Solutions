#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Item {
  int order, cnt;
  Item(int o, int c) : order(o), cnt(c) {}
  bool operator<(const Item& other) const {
    return (cnt == other.cnt ? order < other.order : cnt > other.cnt);
  }
};
int times[50010];

int main() {
  int n, k;
  cin >> n >> k;

  set<Item> items;
  for (int t, first = true; n--;) {
    cin >> t;
    if (!first) {
      cout << t << ':';
      int cnt = 0;
      for (auto& item : items) {
        if (cnt == k) break;
        cnt++;
        cout << ' ' << item.order;
      }
      cout << '\n';
    }
    auto it = items.find(Item(t, times[t]));
    if (it != items.end()) items.erase(it);
    times[t]++;
    items.insert(Item(t, times[t]));
    if (first) first = false;
  }
  return 0;
}