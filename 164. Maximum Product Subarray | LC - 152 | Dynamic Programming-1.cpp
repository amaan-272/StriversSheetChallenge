//CodeStudio Code
#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n) {
    int ans = INT_MIN, maxi {1}, mini {1};
    for(int i:arr){
        if(i < 0) swap(maxi, mini);
        maxi = max(i, maxi*i);
        mini = min(i, mini*i);
        ans = max(maxi, ans);
    }
    return ans;
}

//LeetCode Code
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int ans = INT_MIN, maxi {1}, mini {1};
        for(int i:arr){
            if(i < 0) swap(maxi, mini);
            maxi = max(i, maxi*i);
            mini = min(i, mini*i);
            ans = max(maxi, ans);
        }
        return ans;
    }
};
