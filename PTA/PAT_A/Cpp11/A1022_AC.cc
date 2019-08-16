// ---
// id         : 1022
// title      : Digital Library
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

using Table = unordered_map<string, set<int>>;

int main() {
  int n, m, id, type;
  cin >> n;

  Table titles, authors, keywords, publishers, years;
  vector<Table*> mapping{
      &titles, &authors, &keywords, &publishers, &years,
  };

  for (string title, author, keyword, publisher, year; n--;) {
    cin >> id;
    getchar();

    std::getline(cin, title);
    titles[title].insert(id);

    std::getline(cin, author);
    authors[author].insert(id);

    while (cin >> keyword) {
      keywords[keyword].insert(id);
      if (getchar() == '\n') break;
    }

    std::getline(cin, publisher);
    publishers[publisher].insert(id);

    std::getline(cin, year);
    years[year].insert(id);
  }

  auto query_and_print([](Table& dict, string& target) {
    if (dict.find(target) == dict.end())
      puts("Not Found");
    else
      for (auto& id : dict[target]) printf("%07d\n", id);
  });

  cin >> m;
  for (string t; m-- && scanf("%d: ", &type) == 1;) {
    std::getline(cin, t);
    printf("%d: %s\n", type, t.c_str());
    query_and_print(*mapping[type - 1], t);
  }

  return 0;
}