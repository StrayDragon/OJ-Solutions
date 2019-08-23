// ---
// id         : 1031
// title      : Hello World for U
// difficulty : Easy
// score      : 20
// tag        : Simple Simulation
// keyword    : draw
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <string>
using namespace std;

string input;
void solution1(int n1, int n2, int n3) {
  char drawboard[30][30];
  for (auto& row : drawboard)
    for (auto& i : row)
      i = ' ';
  int i = 0;
  for (int r = 1; r <= n1; r++)
    drawboard[r][1] = input[i++];
  for (int b = 2; b <= n2; b++)
    drawboard[n1][b] = input[i++];
  for (int r = n3 - 1; r >= 1; r--)
    drawboard[r][n2] = input[i++];
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      cout << drawboard[i][j];
    }
    cout << '\n';
  }
}

void solution2(int n, int n1, int n2) {
  for (int i = 0; i < n1 - 1; i++) {
    cout << input[i];
    for (int j = 0; j < n2 - 2; j++) {
      cout << " ";
    }
    cout << input[n - i - 1] << '\n';
  }
  for (int i = 0; i < n2; i++) {
    cout << input[n1 + i - 1];
  }
}

int main() {
  cin >> input;
  const int n = input.size();
  int n1 = (n + 2) / 3, n3 = n1, n2 = n + 2 - n1 - n3;
  // solution1(n1, n2, n3);
  solution2(n, n1, n2);
  return 0;
}