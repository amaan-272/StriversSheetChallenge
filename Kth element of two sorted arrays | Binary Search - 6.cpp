//CodeStudio Code#include <bits/stdc++.h>

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int n, int m, int k) {
    if(n > m) return ninjaAndLadoos(row2, row1, m, n, k);
    int low = max(0, k-m), high = min(n, k); 
    while(low <= high) {
        int mid1 = (low+high) >> 1;
        int mid2 = k-mid1;
        int low1 = (mid1 == 0)? INT_MIN:row1[mid1-1];
        int low2 = (mid2 == 0)? INT_MIN:row2[mid2-1];
        int high1 = (mid1 == n)? INT_MAX:row1[mid1];
        int high2 = (mid2 == m)? INT_MAX:row2[mid2];
        if(low1<=high2 && low2<= high1) return max(low1, low2);
        else if(low1 > high2) high = mid1-1;
        else low = mid1+1;
    }
    return 1;
}
