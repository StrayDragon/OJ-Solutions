// ---
// id         : 1141
// title      : PAT Ranking of Institutions
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void lowerify(string& s) {
  for (auto& c : s) {
    c = tolower(c);
  }
}

double get_ws(char level, double value) {
  if (level == 'B')
    return value / 1.5;
  else if (level == 'A')
    return value;
  else if (level == 'T')
    return value * 1.5;
  return -9999;
}

struct RankItem {
  string school;
  int tws;
  int amount;
};

int main() {
  int n, score;
  cin >> n;
  unordered_multimap<string, pair<string, int>> mdict;
  unordered_set<string> schools;
  for (string id, school; n--;) {
    cin >> id >> score >> school;
    lowerify(school);
    schools.insert(school);
    mdict.insert({school, {id, score}});
  }

  vector<RankItem> rank_items;

  for (const string& school : schools) {
    auto its = mdict.equal_range(school);
    double sum = 0;
    int cnt = std::distance(its.first, its.second);
    unordered_set<string> ids;

    for (auto it = its.first; it != its.second; ++it)
      ids.insert(it->second.first.substr(1, 5));

    for (auto& id : ids)
      for (auto it = its.first; it != its.second; ++it)
        if (id == it->second.first.substr(1, 5))
          sum += get_ws(it->second.first[0], it->second.second);

    rank_items.push_back({school, (int)sum, cnt});
  }

  std::sort(rank_items.begin(), rank_items.end(),
            [](const RankItem& lhs, const RankItem& rhs) {
              if (lhs.tws == rhs.tws) {
                if (lhs.amount == rhs.amount) {
                  return lhs.school < rhs.school;
                } else {
                  return lhs.amount < rhs.amount;
                }
              } else {
                return lhs.tws > rhs.tws;
              }
            });

  int rank = 1, len = rank_items.size();

  printf("%d\n%d %s %d %d\n", len, rank, rank_items[0].school.c_str(),
         rank_items[0].tws, rank_items[0].amount);
  for (auto i = 1; i <= len - 1; i++) {
    if (rank_items[i - 1].tws == rank_items[i].tws) {
      printf("%d %s %d %d\n", rank, rank_items[i].school.c_str(),
             rank_items[i].tws, rank_items[i].amount);
    } else {
      printf("%d %s %d %d\n", i + 1, rank_items[i].school.c_str(),
             rank_items[i].tws, rank_items[i].amount);
      rank = i + 1;
    }
  }
  return 0;
}
