//CodeStudio Code
#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int> ans;
	int i {}, j {};
	while(i<m && j<n) {
		if(arr1[i] < arr2[j]) ans.emplace_back(arr1[i]), i++;
		else ans.emplace_back(arr2[j]), j++;
	}
	while(i < m) ans.emplace_back(arr1[i++]);
	while(j < n) ans.emplace_back(arr2[j++]);
	return ans;
}

//LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i {m-1}, j {n-1}, k {m+n-1};
        while (j >= 0) {
            if(i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
    }
};
