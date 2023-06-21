//CodeStudio Code
#include <bits/stdc++.h> 
#define size(a) a.size()

int maximumProfit(vector<int> &prices){
    if(size(prices) == 1) return 0;
    int ans {}, hold = INT_MAX;
    for(int i:prices) hold = min(hold, i), ans = max(ans, i-hold);
    return ans;
}

//LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int maxProfit(vector<int>& prices) {
        if(size(prices) == 1) return 0;
        int temp = INT_MAX, ans {};
        for(int i:prices) temp = min(temp, i), ans = max(ans, i-temp);
        return ans;
    }
};
