//CodeStudio Code
#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x) {
    int n = arr.size(), ans {};
    for(int i {}; i < n; i++) {
        int tmp {};
        for(int j {i}; j < n; j++) {
            tmp ^= arr[j];
            if(tmp == x) ans++;
        }
    }
    return ans;
}
