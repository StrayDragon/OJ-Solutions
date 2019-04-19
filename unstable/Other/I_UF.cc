#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Acmer {
  string name;
  int exam;
  int time;

  Acmer(string n, int e, int t) : name(n), exam(e), time(t) {}
};

const int MAX_EXAMES_AMOUNT = 11;

vector<Acmer> exam_grades[MAX_EXAMES_AMOUNT];

void reset_exam_grades() {
  for (int i = 1; i <= MAX_EXAMES_AMOUNT; i++) {
    exam_grades[i].clear();
  }
}

int main() {
  int T;
  cin >> T;
  for (int n, case_cnt = 1; case_cnt <= T; case_cnt++) {
    cin >> n;
    vector<string> namelist;
    for (string name; n--;) {
      cin >> name;
      namelist.push_back[name];
    }
    for (string s1;;) {
      int m, t;
      cin >> s1;
      if (s1.size() == 1) break;
      cin >> m >> t;
      exam_grades[m].push_back(Acmer(s1, m, t));
    }

    // 此处排序算法

    string target_name;
    cin >> target_name;
    int target_exam;
    cin >> target_exam;

    // 此处查询算法
  }

  return 0;
}