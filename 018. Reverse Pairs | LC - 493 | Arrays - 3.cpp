//CodeStudio Code
#include <bits/stdc++.h> 

int search(vector<int>& ar, int target) {
	int n = ar.size(), low {}, high {n-1};
	while(low <= high) {
		int mid {low+(high-low)/2};
		if(ar[mid] > target) {
			if(!mid) return n;
			else if(ar[mid-1] <= target) return n-mid;
			else high = mid-1;
		}
		else low = mid+1;
	}
	return 0;
}

int reversePairs(vector<int> &arr, int n){
	int ans {};
	vector<int> ar;
	ar.emplace_back(arr[0]);
	for(int i {1}; i < n; i++) {
		ans += search(ar, 2*arr[i]);
		auto j = upper_bound(begin(ar), end(ar), arr[i]);
		ar.insert(j, arr[i]);
	}
	return ans;
}

//LeetCode Code
class Solution {
public:
    int mergeSort(int low, int mid, int high, vector<int>& nums) {
        int n = mid-low+1, m = high-mid, i, arr1[n], arr2[m];
        for(i = 0; i < n; i++) arr1[i] = nums[low+i];
        for(i = 0; i < m; i++) arr2[i] = nums[mid+i+1];
        int ans = 0, j = 0;
        for(i = 0; i < n; i++) {
            while(j<m && arr1[i]>(long long)2*arr2[j]) j++;
            ans += j;
        }
        i = 0;
        j = 0;
        int k = low;
        while(i<n && j<m) nums[k++] = (arr2[j]<arr1[i])? arr2[j++]:arr1[i++];
        while(i < n) nums[k++] = arr1[i++];
        while(j < m) nums[k++] = arr2[j++];
        return ans;
    }
    
    int merge(int low, int high, vector<int>& nums) {
        if(low >= high) return 0;
        int count = 0, mid = low+(high-low)/2;
        count += (merge(low, mid, nums)+merge(mid+1, high, nums)+mergeSort(low, mid, high, nums));
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        return merge(0, size(nums)-1, nums);
    }
};
