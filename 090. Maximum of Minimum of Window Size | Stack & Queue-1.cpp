//CodeStudio Code
#include <bits/stdc++.h>

vector<int> maxMinWindow(vector<int> a, int n) {
    stack<int> nums;
    vector<int> left(n), right(n), ans(n, INT_MIN);
    left[0] = -1;
    nums.push(0);
    for(int i {}; i < n; i++) {
        while(!nums.empty() && a[nums.top()]>=a[i]) nums.pop();
        left[i] = nums.empty()? -1:nums.top();
        nums.push(i);
    }
    while(!nums.empty()) nums.pop();
    right[n-1] = n;
    nums.push(n-1);
    for(int i {n-2}; i >= 0; i--) {
        while(!nums.empty() && a[nums.top()]>=a[i]) nums.pop();
        right[i] = nums.empty()? n:nums.top();
        nums.push(i);
    }
    for(int i {}; i < n; i++) ans[right[i]-left[i]-2] = max(ans[right[i]-left[i]-2], a[i]);
    for(int i {n-2}; i >= 0; i--) ans[i] = max(ans[i], ans[i+1]);
    return ans;
}
