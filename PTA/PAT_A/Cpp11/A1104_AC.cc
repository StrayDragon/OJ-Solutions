#include <cstdio>

using namespace std;

int n;
double nums[100010];

double segment_sum() {
  double sum = 0;
  for (int i = 0; i < n; i++)
    sum += nums[i] * (i + 1) * (n - i);
  return sum;
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%lf", &nums[i]);

  double result = segment_sum();
  printf("%.2f", result);

  return 0;
}