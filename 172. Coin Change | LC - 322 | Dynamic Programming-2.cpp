//CodeStudio Code
long countWaysToMakeChange(int *denominations, int n, int value) {
    long dp[5001] = {1};
    for(int i {}; i < n; i++) for(int j = denominations[i]; j <= value; j++) dp[j] += dp[j-denominations[i]];
    return dp[value];
}

//LeetCode Code
class Solution{
public:
    bool psbl(vector<int>& coins, int amt) {
        if(amt%2) {
            for(int i {}; i < size(coins); i++) if(coins[i]%2) return false;
            return true;
        }
        return false;
    }
    
    bool check(vector<int>& coins, int index, int cnt, double target){
        double sum = (double)coins[index]*cnt;
        if(sum == target) return true;
        if(sum < target) return false;
        if(!index) return false;
        for (int i {}; i <= cnt; i++){
            double remain = target-coins[index]*i;
            if(!remain) break;
            if(check(coins, index-1, cnt-i, remain)) return true;    
        }
        return false;
    }
    
    int coinChange(vector<int>& coins, int amt) {
        if(psbl(coins, amt)) return -1;
        sort(begin(coins), end(coins));
        int n = size(coins), least = amt/coins.back(), most = amt/coins[0];
        for(int i {least}; i <= most; i++) if(check(coins, n-1, i, amt)) return i;
        return -1;
    }
};
