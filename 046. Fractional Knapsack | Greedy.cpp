//CodeStudio Code
#include <bits/stdc++.h> 

bool cmp(pair<int, int> a, pair<int, int> b) { return (double)a.second/a.first>(double)b.second/b.first; }

double maximumValue (vector<pair<int, int>>& items, int n, int w) {
    sort(begin(items), end(items), cmp);
    double ans {};
    for(auto i:items) {
        if(i.first <= w) {
            ans += i.second;
            w -= i.first;
        }
        else return ans+(i.second*(double)w/i.first);
    }
    return ans;
}
