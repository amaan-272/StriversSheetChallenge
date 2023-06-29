//CodeStudio
int longestSubSeg(vector<int> &arr , int n, int k){
    int ans {}, cnt {};
    for(int i {}, j {}; i < n; i++) {
        if(!arr[i]) cnt++;
        while(cnt > k) {
            if(!arr[j]) cnt--;
            j++;
        }
        ans = max(ans, i-j+1);
    }
    return ans;
}

//LeetCode
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans {}, count {};
        for(auto i:nums) {
            if(i) count++;
            else {
                if(count > ans) ans = count;
                count = 0;
            }
        }
        if(count > ans) ans = count;
        return ans;
    }
};
