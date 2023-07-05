//CodeStudio Code
#include <bits/stdc++.h> 
/* This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.
	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	stack<int> st;
	for(int i {}; i < n; i++) st.push(i);
	while(st.size() > 1) {
		int a = st.top();
		st.pop();
		int b = st.top();
		st.pop();
		(knows(a, b))? st.push(b):st.push(a);
	}
	int ans = st.top();
	for(int i {}; i < n; i++) if(i != ans) if(knows(ans, i)) return -1;
	for(int i {}; i < n; i++) if(i != ans) if(!knows(i, ans)) return -1;
	return ans;
}
