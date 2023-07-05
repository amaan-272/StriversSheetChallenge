//CodeStudio Code
#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) {
    if(n == 1) return "1";
    string ans = "1";
    for(int i {1}; i < n; i++) {
        int count {1}, len = ans.size();
        string temp = "";
        for(int j {}; j < len; j++) {
            while(j+1<len && ans[j]==ans[j+1]) {
                j++;
				count++;
            }
            temp += (to_string(count)+ans[j]);
            count = 1;
        }
		ans = temp;
    }
	return ans;
}

//LeetCode Code
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i {1}; i<n; i++) {
            int len = size(ans), count {1};
            string tmp="";
            char c = {ans[0]};
            for(int j {1}; j < len; j++) {
                if(ans[j] == ans[j-1]) count++;
                else {
                    char cc=count+48;
                    tmp += cc;
                    tmp += c;
                    c = ans[j];
                    count = 1;
                }
            }
            char cc = count+48;
            tmp += cc;
            tmp += c;
            ans = tmp;    
        }
        return ans;
    }
};
