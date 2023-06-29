//CodeStudio Code
#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i {n-1}; i >= 0; i--) {
        while(!st.empty()) {
            if(st.top() > arr[i]) {
                ans[i] = st.top();
                break;
            }
            st.pop();
        }
        st.push(arr[i]);
    }
    return ans;
}

//LeetCode Code
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int> freq;
       stack<int> st;
       int n2 = size(nums2);
       st.push(nums2[n2-1]);
       freq[nums2[n2-1]]--;
       for(int i {n2-2}; i >= 0; i--) {
           while(!st.empty() && st.top()<=nums2[i]) st.pop();
           (size(st))? freq[nums2[i]]=st.top():freq[nums2[i]]--;
           st.push(nums2[i]);
       }
       vector<int> ans;
       for(int i:nums1) ans.emplace_back(freq[i]);
       return ans;
    }
};
