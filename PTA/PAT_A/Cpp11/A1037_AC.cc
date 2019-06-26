#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

auto read_to = [](vector<int>& pos, vector<int>& neg) {
  int n;
  cin >> n;
  for (int i; n-- && cin >> i;) {
    if (i > 0)
      pos.push_back(i);
    else
      neg.push_back(i);
  }
};

auto sort_by_des = [](vector<int>& vi) {
  std::sort(vi.begin(), vi.end(), [](int lhs, int rhs) { return lhs > rhs; });
};

auto sort_by_asc = [](vector<int>& vi) { std::sort(vi.begin(), vi.end()); };

int main() {
  vector<int> p_coupons, n_coupons;
  read_to(p_coupons, n_coupons);

  vector<int> p_products, n_products;
  read_to(p_products, n_products);

  sort_by_des(p_coupons);
  sort_by_des(p_products);

  sort_by_asc(n_coupons);
  sort_by_asc(n_products);

  int result = 0;

  for (size_t i = 0; i < p_products.size() && i < p_coupons.size(); i++) {
    result += (p_products[i] * p_coupons[i]);
  }

  for (size_t i = 0; i < n_products.size() && i < n_coupons.size(); i++) {
    result += (n_products[i] * n_coupons[i]);
  }

  cout << result;
  return 0;
}