#include <iostream>
#include <map>
#include <string>

static const auto __ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();

using namespace std;

const int MAXN = 2010;

map<int, string> no_to_name;
map<string, int> name_to_no;
map<string, int> gang;

int graph[MAXN][MAXN], weight[MAXN];
int n, k, amount_of_people = 0;
bool visited[MAXN] = {false};

void dfs(int now_visit, int& head, int& amount_of_members, int& total_weight) {
  amount_of_members++;
  visited[now_visit] = true;
  if (weight[now_visit] > weight[head])
    head = now_visit;
  for (int i = 0; i < amount_of_people; i++) {
    if (graph[now_visit][i] > 0) {
      total_weight += graph[now_visit][i];
      graph[now_visit][i] = graph[i][now_visit] = 0;
      if (visited[i] == false)
        dfs(i, head, amount_of_members, total_weight);
    }
  }
}

void dfs() {
  for (int i = 0; i < amount_of_people; i++) {
    if (visited[i] == false) {
      int head = i, amount_of_members = 0, total_weight = 0;
      dfs(i, head, amount_of_members, total_weight);
      if (amount_of_members > 2 && total_weight > k) {
        gang[no_to_name[head]] = amount_of_members;
      }
    }
  }
}

int get_no_and_record(string& name) {
  if (name_to_no.find(name) != name_to_no.end())
    return name_to_no[name];
  else {
    name_to_no[name] = amount_of_people;
    no_to_name[amount_of_people] = name;
    int no = amount_of_people++;
    return no;
  }
}

int main() {
  int w;
  string name1, name2;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> name1 >> name2 >> w;
    int no1 = get_no_and_record(name1);
    int no2 = get_no_and_record(name2);
    weight[no1] += w;
    weight[no2] += w;
    graph[no1][no2] += w;
    graph[no2][no1] += w;
  }
  dfs();
  cout << gang.size() << '\n';
  for (auto it = gang.begin(); it != gang.end(); ++it)
    cout << it->first << " " << it->second << '\n';

  return 0;
}
