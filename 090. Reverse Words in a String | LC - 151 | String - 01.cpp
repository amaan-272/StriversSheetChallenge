//CodeStudio Code
#include <bits/stdc++.h>

string reverseString(string &str){
	stack<string> words;
	string word;
	int n = str.size();
	for(int i {}; i < n; i++) {
		if(str[i] != ' ') word += str[i];
		if(str[i]==' ' || i==n-1){   
			if(word.size()!=0){    
				words.push(word);    
				word.clear();   
			}  
		}
	}
	string ans;
	while(!words.empty()) {
		ans += words.top();
		words.pop();
		if(!words.empty()) ans += ' ';
	}	
	return ans;
}

//LeetCode Code
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word) words.emplace_back(word);
        string ans;
        int n = size(words);
        for(int i {n-1}; i >= 0; i--) {
            if(i != n-1) ans += ' ';
            ans += words[i];
        }
        return ans;
    }
};
