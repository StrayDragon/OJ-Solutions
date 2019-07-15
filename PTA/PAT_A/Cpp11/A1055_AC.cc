#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person {
  string name;
  int age, net_worth;
};

int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<Person> people;
  vector<int> age_dict(210, 0);
  for (Person p; n--;) {
    cin >> p.name >> p.age >> p.net_worth;
    people.push_back(p);
  }

  std::sort(people.begin(), people.end(), [](Person& lhs, Person& rhs) {
    if (lhs.net_worth == rhs.net_worth) {
      if (lhs.age == rhs.age)
        return lhs.name < rhs.name;
      else
        return lhs.age < rhs.age;
    } else {
      return lhs.net_worth > rhs.net_worth;
    }
  });

  vector<Person> candidates;
  for (int i = 0; i < people.size(); i++) {
    if (age_dict[people[i].age] < 100) {
      candidates.push_back(people[i]);
      age_dict[people[i].age]++;
    }
  }

  for (int m, amin, amax, i = 1; k--; i++) {
    cin >> m >> amin >> amax;

    vector<Person> targets;
    for (auto&& p : candidates) {
      if (amin <= p.age && p.age <= amax) {
        targets.push_back(p);
      }
    }

    cout << "Case #" << i << ":\n";
    if (targets.empty()) {
      cout << "None";
    } else {
      for (auto it = targets.begin(); m-- && it != targets.end(); ++it) {
        cout << (*it).name << " " << (*it).age << " " << (*it).net_worth
             << "\n";
      }
    }
  }
  return 0;
}