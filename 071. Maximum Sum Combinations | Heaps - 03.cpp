//CodeStudio Code
#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int>pq;
	vector<int> ans;
	for(int i {}; i < n; i++) for(int j {}; j < n; j++) pq.push(a[i]+b[j]);
	for(int i {}; i < k; i++) {
		ans.emplace_back(pq.top());
		pq.pop();
	}
	return ans;
}
