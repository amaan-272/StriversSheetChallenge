//CodeStudio Code
#include <bits/stdc++.h> 
int findMinimumCoins(int amount) {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int ans {}, i {9};
    while(amount && i) {
        if(amount < coins[i-1]) {
            i--;
            continue;
        }
        ans++;
        amount -= coins[i-1];
    }
    return ans;
}
