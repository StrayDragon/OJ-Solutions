#include <cstdio>
#include <vector>
using namespace std;

vector<int> preorders, inorders;
bool is_first = true;

void post_order_first(int preleft_i, int inleft_i, int inright_i) {
  if (inleft_i > inright_i || !is_first)
    return;
  int i = inleft_i;
  while (inorders[i] != preorders[preleft_i])
    i++;
  post_order_first(preleft_i+1, inleft_i, i - 1);
  post_order_first(preleft_i + i - inleft_i + 1, i + 1, inright_i);
  if (is_first) {
    printf("%d", inorders[i]);
    is_first = false;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  for (int num, i = n; i--;) {
    scanf("%d", &num);
    preorders.push_back(num);
  }

  for (int num, i = n; i--;) {
    scanf("%d", &num);
    inorders.push_back(num);
  }

  post_order_first(0, 0, n - 1);

  return 0;
}