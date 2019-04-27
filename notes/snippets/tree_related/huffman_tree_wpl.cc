#include<cstdio>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;
int main(){
	int weights[] = {1,2,2,3,6};
	int n = sizeof(weights) / sizeof(int);
	for(int i = 0; i < n; i++){
		pq.push(weights[i]);
	}

	int w1,w2,wpl = 0;
	while(pq.size() > 1){
		w1 = pq.top();
		pq.pop();
		w2 = pq.top();
		pq.pop();
		pq.push(w1+w2);
		wpl += w1+w2;
	}

	printf("WPL: %d\n",wpl);
	return 0;
}

