//CodeStudio Code
#include <bits/stdc++.h>

int getMedian(vector<vector<int>> &matrix) {
    vector<int> elem;
    for(auto i:matrix) for(int j:i) elem.emplace_back(j);
    sort(begin(elem), end(elem));
    return elem[elem.size()/2];
}
