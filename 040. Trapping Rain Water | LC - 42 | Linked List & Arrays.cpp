//CodeStudio Code
#include <bits/stdc++.h> 

long getTrappedWater(long *arr, int n){
    long ans = 0;
    vector<long> left(n), right(n);
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    for(int i {1}; i < n; i++) left[i] = max(arr[i], left[i-1]);
    for(int i {n-2}; i >= 0; i--) right[i] = max(arr[i], right[i+1]);
    for(int i {1}; i < n; i++) ans += min(left[i], right[i])-arr[i];
    return ans;
}

//LeetCode Code
class Solution {
public:
    int trap(vector<int>& height) {
        int i {1}, j = size(height)-2, left {height[i-1]}, right {height[j+1]}, ans {};
        while(i <= j){
            if(height[i] >= left){
                left = height[i];
                i++;
            } 
            else if(height[j] >= right){
                right = height[j];
                j--;
            } 
            else if(left<=right && height[i]<left){
                ans += left-height[i];
                i++;
            } 
            else {
                ans += right-height[j];
                j--;
            }
        }
        return ans;
    }
};
