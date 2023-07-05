//CodeStudio Code
int romanToInt(string s) {
    int ans {};
    for(char i:s) {
        if(i == 'I') ans += 1;
        else if(i == 'V') ans += 5;
        else if(i == 'X') ans += 10;
        else if(i == 'L') ans += 50;
        else if(i == 'C') ans += 100;
        else if(i == 'D') ans += 500;
        else if(i == 'M') ans += 1000;
    }
    for(int i {}; i < s.size()-1; i++) {
        if(s[i]=='I' && s[i+1]=='V') ans -= 2;
        else if(s[i]=='I' && s[i+1]=='X') ans -= 2;
        else if(s[i]=='X' && s[i+1]=='L') ans -= 20;
        else if(s[i]=='X' && s[i+1]=='C') ans -= 20;
        else if(s[i]=='C' && s[i+1]=='D') ans -= 200;
        else if(s[i]=='C' && s[i+1]=='M') ans -= 200;
    }
    return ans;
}

//LeetCode Code
class Solution {
public:
    int romanToInt(string s) {
        int ans {};
        for(char& i:s) {
            if(i == 'I') ans += 1;
            else if(i == 'V') ans += 5;
            else if(i == 'X') ans += 10;
            else if(i == 'L') ans += 50;
            else if(i == 'C') ans += 100;
            else if(i == 'D') ans += 500;
            else if(i == 'M') ans += 1000;
        }
        for(int i {}; i < size(s)-1; i++) {
            if(s[i]=='I' && s[i+1]=='V') ans -= 2;
            else if(s[i]=='I' && s[i+1]=='X') ans -= 2;
            else if(s[i]=='X' && s[i+1]=='L') ans -= 20;
            else if(s[i]=='X' && s[i+1]=='C') ans -= 20;
            else if(s[i]=='C' && s[i+1]=='D') ans -= 200;
            else if(s[i]=='C' && s[i+1]=='M') ans -= 200;
        }
        return ans;
    }
};
