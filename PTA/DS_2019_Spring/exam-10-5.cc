#include <algorithm>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

static auto __ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();

using namespace std;

int exam_scores[10] = {0};
int n, k, m;
struct User {
  int id, total_score = 0;
  vector<int> scores = vector<int>(6, -1);

  User() = default;
  User(int uid, int pid, int score) {
    id = uid;
    if (score == -1) scores[pid] = 0;
    scores[pid] = score;
  }

  void update(int pid, int score) {
    if (score == -1 && scores[pid] == -1) scores[pid] = 0;
    if (scores[pid] < score) scores[pid] = score;
  }

  void sum_and_check() {
    int pass_cnt = 0;
    bool is_passing[6];
    std::fill(is_passing, is_passing + 6, false);
    for (int i = 1; i <= k; i++) {
      if (scores[i] != -1) total_score += scores[i];
      if (!is_passing[i] && exam_scores[i] == scores[i]) {
        pass_cnt++;
        is_passing[i] = true;
      };
    }
    scores[0] = pass_cnt;
  }

  bool is_submitted() const {
    for (int i = 1; i < scores.size(); i++)
      if (scores[i] != -1) {
        return true;
      }
    return false;
  }

  bool operator<(const User& other) const {
    if (total_score != other.total_score)
      return total_score < other.total_score;
    else
      return (scores[0] < other.scores[0]);
  }
};

const int MAXN = 100010;
int user_pos_dict[MAXN];

ostream& operator<<(ostream& out, const User& u) {
  if (u.is_submitted()) {
    out << setfill('0') << setw(5) << u.id;
    out << " " << u.total_score << " ";
    auto it = u.scores.begin() + 1;
    if (*it == -1)
      out << '-';
    else
      out << *it;
    ++it;
    for (; it != u.scores.begin() + 1 + k; ++it) {
      if (*it == -1)
        out << " -";
      else
        out << " " << *it;
    }
  }
  return out;
}

int main() {
  std::fill(user_pos_dict, user_pos_dict + MAXN, -1);
  cin >> n >> k >> m;
  for (int i = 1; i <= k; i++) cin >> exam_scores[i];
  vector<User> users;
  for (int user_id, problem_id, score; m--;) {
    cin >> user_id >> problem_id >> score;
    if (user_pos_dict[user_id] == -1) {
      if (score != -1) {
        User u(user_id, problem_id, score);
        users.push_back(u);
        user_pos_dict[user_id] = users.size() - 1;
      }
    } else {
      users[user_pos_dict[user_id]].update(problem_id, score);
    }
  }
  for (auto& u : users) u.sum_and_check();
  std::sort(users.begin(), users.end());
  int rank_i = 1, i = 1;
  int ri = users.size() - 1;
  do {
    cout << rank_i << " " << users[ri--] << '\n';
    i++;
    if (users[ri].total_score != users[ri + 1].total_score) {
      rank_i = i;
    }
  } while (ri >= 1);
  cout << rank_i << " " << users[ri] << '\n';
  return 0;
}
