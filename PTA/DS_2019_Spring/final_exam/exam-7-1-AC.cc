#include <functional>
#include <iostream>
#include <vector>

using namespace std;

std::function<void(int, int, int)> post_in_to_pre;

int main() {
  int n;
  cin >> n;
  vector<int> postorder(n), inorder(n), preorder;
  for (int i = 0; i < n; ++i)
    cin >> postorder[i];
  for (int i = 0; i < n; ++i)
    cin >> inorder[i];

  post_in_to_pre = [&](int i, int j, int root_i) {
    if (i <= j) {
      int idx = i;
      while (postorder[root_i] != inorder[idx])
        idx++;
      preorder.push_back(inorder[idx]);
      post_in_to_pre(i, idx - 1, root_i - 1 - (j - idx));
      post_in_to_pre(idx + 1, j, root_i - 1);
    }
  };

  post_in_to_pre(0, n - 1, n - 1);
  if (n != 0)
    cout << "Preorder: " << preorder[0];
  for (int i = 1; i < n; i++)
    cout << " " << preorder[i];

  return 0;
}