//CodeStudio Code
#include <bits/stdc++.h> 
int atoi(string str) {
    int ans {};
    for(char i:str) if(isdigit(i)) ans = ans*10+i-'0';
    return (str[0] == '-')? -ans:ans;
}

//LeetCode Code
class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int len = size(s);
        bool neg = false; 
        for(int i {}; i < len ; i++){
            if((s[i]>='0' && s[i]<='9') || s[i]=='+' || s[i]=='-'){
                if(s[i] == '-') neg = true;
                if(s[i] == '+' || s[i] == '-') i++;
                while(i<len && (s[i]>='0' && s[i]<='9')){
                    ans = (ans*10)+(s[i]-'0');
                    if(!neg && ans>=INT_MAX) return INT_MAX;
                    else if(neg && (-1LL*ans)<=INT_MIN) return INT_MIN;
                    i++;
                }
                break;
            }
           else if(s[i]>='a' && s[i]<='z' || (s[i]>='A' && s[i]<='Z') || s[i]=='.') break;
        } 
        if(neg) ans = -ans;
        return ans;
    }
};
