#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>
#include <vector>

using namespace std;
char name[40010][5];
vector<int> course[2510];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  unordered_set<string> students_set[k + 1];
  for (int cnt, i = 0; i < n; i++) {
    scanf("%s %d", name[i], &cnt);
    for (int course_id; cnt--;) {
      scanf("%d", &course_id);
      course[course_id].push_back(i);
    }
  }
  for (int i = 1; i <= k; i++) {
    printf("%d %lu\n", i, course[i].size());
    std::sort(course[i].begin(), course[i].end(),
              [](const int& lhs, const int& rhs) {
                return strcmp(name[lhs], name[rhs]) < 0;
              });
    for (const auto& key : course[i]) {
      printf("%s\n", name[key]);
    }
  }

  return 0;
}