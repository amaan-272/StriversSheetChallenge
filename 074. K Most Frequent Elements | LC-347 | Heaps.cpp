//CodeStudio Code
#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr) {
    map<int, int> freq;
    vector<int> ans;
    for(int i:arr) freq[i]++;
    priority_queue<pair<int, int>> pq;
    for(auto i:freq) pq.push({i.second, i.first});
    for(int i {}; i < k; i++) {
        ans.emplace_back(pq.top().second);
        pq.pop();
    }
    sort(begin(ans), end(ans));
    return ans;
}

//LeetCode Code
class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        return a.second>b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> freq;
        unordered_map<int, int> a;
        for(auto i:nums) a[i]++;
        for(auto i:a) freq.push_back({i.first, i.second});
        sort(begin(freq), end(freq), cmp);
        vector<int> ans;
        for(int i {}; i < k; i++) ans.emplace_back(freq[i].first);
        return ans;
    }
};
