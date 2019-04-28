#include <iostream>
#include <vector>

using namespace std;
int main() {
  vector<int> vi {0,1,2,3,4,5,6,7,8};
  int n = vi.size(), k = 1;
  
  vector<int> res;
  int i,j;
  for(i = k-1; i < n; i += k){
    for(j = i; j >= i/k*k ;j--){
      //res.push_back(vi[j]);
      cout << vi[j] << " ";
    }
  }
  if(i-k != n){
   for(auto ii = i-k+1; ii != n;++ii)
    cout << vi[ii] << " ";
  }
  
  for(auto i : res)
    cout << i << " ";
  return 0;
}