//CodeStudio Code
vector<vector<int>> ans;
vector<int> subset;

void solve(vector<int>& arr, int k, int ind) {
    if(ind == arr.size()) {
        if(accumulate(begin(subset), end(subset), 0) == k) ans.push_back(subset);
        return;
    }
    subset.push_back(arr[ind]);
    solve(arr, k, ind+1);
    subset.pop_back();
    solve(arr, k, ind+1);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
    ans.clear();
    subset.clear();
    solve(arr, k, 0);
    return ans;
}

//LeetCode Code
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void solve(vector<int>& candidates, int target, int i) {
        if(i == size(candidates)) {
            if(target == 0) ans.push_back(temp);
            return;
        }
        if(candidates[i] <= target) {
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i], i);
            temp.pop_back();
        }
        solve(candidates, target, i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        temp.clear();
        solve(candidates, target, 0);
        return ans;
    }
};
