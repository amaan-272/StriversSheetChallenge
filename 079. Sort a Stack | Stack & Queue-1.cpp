//CodeStudio Code
#include <bits/stdc++.h> 

void solve(stack<int>& st, int x) {
	if(st.empty() || st.top()<x) {
		st.push(x);
		return;
	}
	int n = st.top();
	st.pop();
	solve(st, x);
	st.push(n);
}

void sortStack(stack<int> &stack) {
	if(stack.empty()) return;
	int x = stack.top();
	stack.pop();
	sortStack(stack);
	solve(stack, x);
}
