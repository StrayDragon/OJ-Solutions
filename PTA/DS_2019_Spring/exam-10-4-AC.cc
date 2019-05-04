#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int years_dict[55] = {0};
int main() {
  int n;
  cin >> n;
  set<int> service_year_set;
  for (int year; n--;) {
    cin >> year;
    service_year_set.insert(year);
    ++years_dict[year];
  }

  for (auto i : service_year_set) cout << i << ":" << years_dict[i] << endl;
  return 0;
}
