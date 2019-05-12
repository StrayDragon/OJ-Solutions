#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  unordered_map<long long, int> record_dict;
  auto add = [&](long long num) {
    if (record_dict.find(num) == record_dict.end()) {
      record_dict[num] = 1;
    } else {
      record_dict[num]++;
    }
  };

  for (long long phone_number; n--;) {
    cin >> phone_number;
    add(phone_number);
    cin >> phone_number;
    add(phone_number);
  }

  int frequency = 0;
  for (auto kv : record_dict)
    if (frequency < kv.second)
      frequency = kv.second;
  vector<long long> chatters;
  for (auto kv : record_dict)
    if (frequency == kv.second)
      chatters.push_back(kv.first);

  auto min_it = min_element(chatters.begin(), chatters.end());
  if (chatters.size() == 1) {
    cout << *min_it << " " << frequency;
  } else {
    cout << *min_it << " " << frequency << " " << chatters.size();
  }

  // vector<pair<long long, int>> records(record_dict.begin(),
  // record_dict.end()); auto max_it = std::max_element(
  //     records.begin(), records.end(),
  //     [](const pair<long long, int>& kv1, const pair<long long, int>& kv2) {
  //       return kv1.second < kv2.second;
  //     });

  // cout << max_it->first << " " << max_it->second;
  return 0;
}