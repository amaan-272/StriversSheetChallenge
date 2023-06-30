//CodeStudio Code
string longestPalinSubstring(string str) {
    int n = str.size(), maxlen {1}, start {}, left, right;
    for(int i = 0; i < n; i++){
        left = i-1; 
        right = i+1;
        while(right<n && str[i]==str[right]) right++;
        while(left>=0 && str[i]==str[left]) left--;
        while(right<n && left>=0 && str[left]==str[right]){
            right++;
            left--;
        }
        int len {right-left-1};
        if(maxlen < len){
            maxlen = len;
            start = left+1;
        }
    }
    return str.substr(start, maxlen);
}

//LeetCode Code
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxlen = 1, begin = 0, left, right;
        for (int i = 0; i < n; i++){
            left = i-1; right = i+1;
            while(right<n && s[i]==s[right]) right++;
            while(left>=0 && s[i]==s[left]) left--;
            while(right<n && left>=0 && s[left]==s[right]){
                right++;
                left--;
            }
            int len = right-left-1;
            if(maxlen < len){
                maxlen = len;
                begin = left+1;
            }
        }
        return s.substr(begin, maxlen);
    }
};
