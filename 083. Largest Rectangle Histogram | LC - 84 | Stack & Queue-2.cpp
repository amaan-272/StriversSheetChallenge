//CodeStudio
#include <bits/stdc++.h>

bool satisfied(stack<int>& st, vector<int>& heights, int i) {
    if(!st.empty() && (i == heights.size() || heights[st.top()] >= heights[i]))
        return true;
    return false;
}

int largestRectangle(vector<int>& heights) {
    stack<int> st;
    int ans {}, n = heights.size();
    for(int i {}; i < n+1; i++) {
        while(satisfied(st, heights, i)) {
            int ht = heights[st.top()], wt {i};
            st.pop();
            if(!st.empty()) wt = i-st.top()-1;
            ans = max(ans, wt*ht);
        }
        st.push(i);
    }
    return ans;
}

//LeetCode
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans {}, top, ran;
        heights.emplace_back(0);
        for(int i {}; i < size(heights); i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                top = heights[st.top()];
                st.pop();
                ran = st.empty()? -1:st.top();
                ans = max(ans, top*(i-ran-1));
            }
            st.push(i);
        }
        return ans;
    }
};
