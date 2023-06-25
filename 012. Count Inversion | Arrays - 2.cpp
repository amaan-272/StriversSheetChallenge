#CodeStudio Code
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    long long ans {};
    for(int i {}; i < n-1; i++) for(int j {i}; j < n; j++) if(arr[i] > arr[j]) ans++;
    return ans; 
}
