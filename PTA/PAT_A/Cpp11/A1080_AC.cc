// ---
// id         : 1080
// title      : Graduate Admission
// difficulty : Hard
// score      : 30
// tag        : Primary Algorithm
// keyword    : sort
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>

using namespace std;

#define ARR_RNG_N(x, n) x, x + n

struct Applicant {
  double ge, gi, g;  //! double/int => Right
  int choices[6];
  int no, rank = -1;
} apl[40010];

struct School {
  int quota;
  int actual = 0;
  int nos[40010], last_admit_i = -1;
} sch[110];

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) cin >> sch[i].quota;

  for (int i = 0; i < n; i++) {
    cin >> apl[i].ge >> apl[i].gi;
    apl[i].no = i;
    apl[i].g = (apl[i].ge + apl[i].gi) / 2;
    for (int j = 0; j < k; j++) cin >> apl[i].choices[j];
  }

  std::sort(ARR_RNG_N(apl, n), [](Applicant& a, Applicant& b) {
    return a.g != b.g ? a.g > b.g : a.ge > b.ge;
  });

  for (int i = 0; i < n; i++) {
    if (i > 0 && (apl[i].g == apl[i - 1].g && apl[i].ge == apl[i - 1].ge)) {
      apl[i].rank = apl[i - 1].rank;
    } else {
      apl[i].rank = i;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int cho = apl[i].choices[j];
      int cur_stu = sch[cho].actual;
      int last_i = sch[cho].last_admit_i;
      bool accepted = cur_stu < sch[cho].quota ||
                      (last_i != -1 && apl[i].rank == apl[last_i].rank);
      if (accepted) {
        sch[cho].nos[cur_stu] = i;
        sch[cho].last_admit_i = i;
        sch[cho].actual++;
        break;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    if (sch[i].actual > 0) {
      std::sort(ARR_RNG_N(sch[i].nos, sch[i].actual),
                [&](int a, int b) { return apl[a].no < apl[b].no; });
      for (int j = 0; j < sch[i].actual; j++) {
        cout << apl[sch[i].nos[j]].no;
        if (j < sch[i].actual - 1) cout << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}