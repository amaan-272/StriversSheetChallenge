//CodeStudio Code
#include <bits/stdc++.h> 
int compareVersions(string a, string b) {
    int i {}, j {}, na = a.size(), nb = b.size();
    while(i<na || j<nb) {
        long long x {}, y {};
        while(i<na && a[i]!='.') x = x*10+(a[i++]-'0');
        while(j<nb && b[j]!='.') y = y*10+(b[j++]-'0');
        if(x>y) return 1;
        else if(x<y) return -1;  
        i++;
        j++;
    }
    return 0;
}

//LeetCode
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int compareVersion(string version1, string version2) {
        int i {}, j {}, n1 = size(version1), n2 = size(version2);
        while(i<n1 || j<n2) {
           int num1 {}, num2 {};
           while(i<n1 && version1[i]!='.') num1 = num1*10+(version1[i++]-'0');
           while(j<n2 && version2[j]!='.') num2 = num2*10+(version2[j++]-'0');
           if(num1 > num2) return 1;
           if(num1 < num2) return -1;
           i++;
           j++;
        }
        return 0;
    }
};
