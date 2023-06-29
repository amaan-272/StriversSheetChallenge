//CodeStudio Code
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt,dt+n);
    int ans {1}, cnt {1};
    for(int i{1}, j {}; i<n && j<n; ) {  
        if(at[i] <= dt[j]) {
            cnt++;
            i++;
        }
        else {
            cnt--;
            j++;
        }
        ans = max(ans, cnt); 
    }
    return ans;
}
