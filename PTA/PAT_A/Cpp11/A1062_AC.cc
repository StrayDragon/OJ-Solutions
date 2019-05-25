#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

#define ALL(x) (x).begin(), (x).end()

struct Person {
  int id, virtue, talent;
  Person() = default;
  Person(int i, int v, int t) : id(i), virtue(v), talent(t) {}
};

void sort_and_display(vector<Person>& persons) {
  std::sort(ALL(persons), [](const Person& lhs, const Person& rhs) -> bool {
    int ltotal = lhs.talent + lhs.virtue, rtotal = rhs.talent + rhs.virtue;
    if (ltotal == rtotal) {
      if (lhs.virtue == rhs.virtue) {
        return lhs.id < rhs.id;
      } else {
        return lhs.virtue > rhs.virtue;
      }
    }
    return ltotal > rtotal;
  });
  for (const auto& it : persons)
    cout << it.id << " " << it.virtue << " " << it.talent << '\n';
}

int main() {
  int n, l, h;
  cin >> n >> l >> h;

  vector<Person> sages, noblemen, foolmen, others;
  for (Person guy; n--;) {
    cin >> guy.id >> guy.virtue >> guy.talent;

    // Filter the smallmen:
    // that is, only the ones whose grades of talent and virtue are both not
    // below this line will be ranked;
    if (guy.virtue < l || guy.talent < l)
      continue;

    // that is, those with both grades **not below** this line(h) are considered
    // as the "sages"
    if (guy.virtue >= h && guy.talent >= h)
      sages.push_back(guy);
    // Those with talent grades **below** h but virtue grades not are cosidered as
    // the "noblemen"
    else if (guy.talent < h && guy.virtue >= h)
      noblemen.push_back(guy);
    // Those with **both** grades **below** h, but with virtue **not lower** than talent are
    // considered as the "fool men"
    else if (guy.talent < h && guy.virtue < h && guy.virtue >= guy.talent)
      foolmen.push_back(guy);
    // The rest of people whose grades both pass the L line are ranked after the
    // "fool men".
    else if (guy.virtue >= l && guy.talent >= l)
      others.push_back(guy);
  }

  cout << (sages.size() + noblemen.size() + foolmen.size() + others.size())
       << '\n';
  sort_and_display(sages);
  sort_and_display(noblemen);
  sort_and_display(foolmen);
  sort_and_display(others);
  return 0;
}
