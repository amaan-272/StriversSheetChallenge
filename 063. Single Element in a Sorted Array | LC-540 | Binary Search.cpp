//CodeStudio Code
int singleNonDuplicate(vector<int>& arr) {
	int low {}, high = arr.size()-2;
    while(low <= high){
        int mid {low+(high-low)/2};
        if(arr[mid] == arr[mid^1]) low = mid+1;
		else high = mid-1;
    }
    return arr[low];
}

//LeetCode Code
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans {};
		for(int i:nums) ans ^= i;
		return ans;
    }
};
