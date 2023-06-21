//CodeStudio Code
#include <bits/stdc++.h> 
void sort012(int *arr, int n) {
   vector<int> freq(3, 0);
   for(int i {}; i < n; i++) freq[arr[i]]++;
   freq[1] += freq[0];
   freq[2] += freq[1];
   int i;
   for(i = 0; i < freq[0]; i++) arr[i] = 0;
   for( ; i < freq[1]; i++) arr[i] = 1;
   for( ; i < freq[2]; i++) arr[i] = 2;
}

//LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void sortColors(vector<int>& nums) {
        int n = size(nums);
        for(int i {}; i < n-1; i++) for(int j {}; j < n-i-1; j++) if(nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
    }
};
