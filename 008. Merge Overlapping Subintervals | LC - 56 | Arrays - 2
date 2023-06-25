//CodeStudio Code
#include <bits/stdc++.h> 

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
    vector<pair<int, int>> store;
    int n = intervals.size();
    for(int i {}; i < n; i++) store.push_back({intervals[i][0], intervals[i][1]});
    sort(begin(store), end(store));
    int left {store[0].first}, right {store[0].second};
    vector<vector<int>> ans;
    for(int i {1}; i < n; i++) {
        if(store[i].first <= right) right = max(right, store[i].second);
        else {
            ans.push_back({left, right});
            left = store[i].first;
            right = store[i].second;
        }
    }
    ans.push_back({left, right});
    return ans;
}

//LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> elem;
        int n = size(intervals);
        for(int i {}; i < n; i++) elem.push_back({intervals[i][0], intervals[i][1]});
        sort(begin(elem), end(elem));
        int first {elem[0].first}, second {elem[0].second};
        vector<vector<int>> ans;
        for(int i {1}; i < n; i++) {
            if(elem[i].first <= second) second = max(second, elem[i].second);
            else {
                ans.push_back({first, second});
                first = elem[i].first;
                second = elem[i].second;
            }
        }
        ans.push_back({first, second});
        return ans;   
    }
};
