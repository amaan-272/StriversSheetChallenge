//CodeStudio Code
#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    vector<int> ans;
    stack<int> st;
    st.push(-1);
    for(int i {}; i < price.size(); i++) {
        while(st.top()!=-1 && price[st.top()]<=price[i]) st.pop();
        ans.push_back((st.top() == -1)? i+1:i-st.top()); 
        st.push(i);
    }
    return ans;
}

//LeetCode Code
class StockSpanner {
public:
    stack<pair<int,int>> a;
    StockSpanner() {}
    
    int next(int price) {
        int ans {1};
        while(!a.empty() && a.top().first<=price) {
            ans += a.top().second;
            a.pop();
        }
        a.push({price, ans});
        return ans;
    }
};
