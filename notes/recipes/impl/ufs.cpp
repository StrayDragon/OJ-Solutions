#include <algorithm>
#include <iostream>
#include <iterator>

namespace oj {
namespace sets {

const int MAX_FATHER_ARR_CAPACITY = 10;
static int father[MAX_FATHER_ARR_CAPACITY];
void ufs_init() {
  for (int i = 0; i < MAX_FATHER_ARR_CAPACITY; i++) {
    father[i] = i;
    // father[i] = -1;
  }
}

int ufs_find_father(int x) {
  while (x != father[x]) {
    x = father[x];
  }
  return x;
}

int ufs_find_father_zip(int x) {
  int a = x;

  while (x != father[x]) {
    x = father[x];
  }

  while (a != father[a]) {
    int z = a;
    a = father[a];
    father[z] = x;
  }

  return x;
}

int ufs_find_father_zip_recursive(int x) {
  if (x = father[x])
    return x;
  else {
    int f = ufs_find_father_recursive(father[x]);
    father[x] = f;
    return f;
  }
}

int ufs_find_father_recursive(int x) {
  return (x == father[x]) ? x : ufs_find_father_recursive(father[x]);
}

void ufs_union(int a, int b) {
  int af = ufs_find_father(a);
  int bf = ufs_find_father(b);
  if (af != bf)
    father[af] = bf;
}

}  // namespace sets
}  // namespace oj

#include "../preinclude.hpp"
namespace oj {

void example_ufs_find() {
  using namespace std;
  using oj::sets::father;
  using oj::sets::ufs_find_father_zip;
  eg::start();
  cout << "In oj::example_ufs_find()\n";
  father[0] = 0;
  father[1] = 0;
  father[2] = 1;
  father[3] = 2;
  father[4] = 3;
  father[5] = 4;
  father[6] = 5;
  father[7] = 6;
  father[8] = 7;
  father[9] = 8;

  std::copy(begin(father), end(father), ostream_iterator<int>(cout, " ")),
      cout << endl;
  ufs_find_father_zip(9);

  std::copy(begin(father), end(father), ostream_iterator<int>(cout, " ")),
      cout << endl;
  eg::over();
}

}  // namespace oj