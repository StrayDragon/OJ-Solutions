// ---
// id         : 1086
// title      : Tree Traversals Again
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <functional>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::function<void(int, int, int)> pre_in_to_post;

using namespace std;

int main() {
  vector<int> prenodes;
  vector<int> innodes;
  stack<int> stk;
  int n;
  cin >> n;
  getchar();
  string instruction;
  while (getline(cin, instruction)) {
    auto space_pos = instruction.find(' ');
    if (space_pos == string::npos) {
      // Pop
      innodes.push_back(stk.top());
      stk.pop();
    } else {
      // Push X
      int num = stoi(instruction.substr(space_pos + 1));
      prenodes.push_back(num);
      stk.push(num);
    }
  }

  vector<int> postnodes;
  pre_in_to_post = [&](int i, int j, int root_i) {
    if (i <= j) {
      int index = i;
      while (prenodes[root_i] != innodes[index]) index++;
      pre_in_to_post(i, index - 1, root_i + 1);
      pre_in_to_post(index + 1, j, root_i + 1 + index - i);
      postnodes.push_back(innodes[index]);
    }
  };
  pre_in_to_post(0, innodes.size() - 1, 0);

  if (!postnodes.empty()) cout << postnodes[0];

  for (auto it = postnodes.begin() + 1; it != postnodes.end(); ++it)
    cout << " " << *it;
  return 0;
}