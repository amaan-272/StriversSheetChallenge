//CodeStudio Code
#include <bits/stdc++.h> 

long long ayushGivesNinjatest(int n, int m, vector<int> time) {
    long long low = *max_element(time.begin(), time.end()), high = 1e18, ans = 1e18;
    while(low <= high) {
        long long mid {low+(high-low)/2}, curr {1}, sum {};
        for(int i {}; i < m; i++) {
            if(sum+time[i] > mid) {
                sum = 0;
                curr++;
            }
            sum += time[i];
        }
        if(curr > n) low = mid+1;
        else {
            ans = min(ans, mid);
            high = mid-1;
        }
    }
    return ans;
}
