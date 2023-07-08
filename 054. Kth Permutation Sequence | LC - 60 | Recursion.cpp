//CodeStudio Code
int fac(int n) {    
    int ans {1};    
    for(int i {1}; i <= n; i++) ans *= i;    
    return ans; 
}

int find(vector<bool> &s, int idx) {    
    idx++;    
    int n = s.size();    
    int cnt {};    
    for(int i {}; i < n; i++)    {        
        if(!s[i]) cnt++;       
        if(cnt == idx) return i;    
    }    
    return n-1; 
}

string kthPermutation(int n, int k)  {    
    k--;    
    string ans;        
    vector<bool> s(n, false);        
    for(int i {n-1}; i >= 0;i--)    {        
        int f = fac(i), curr = find(s, k/f);                             
        ans += to_string(curr+1);        
        s[curr] = true;   
        k %= f;           
    }        
    return ans; 
}  

//LeetCode Code
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int fac(int n){
        if(n > 1) return n*fac(n-1);
        else return 1;
	}
    
    string getPermutation(int n, int k) {
        int total = fac(n);
        k--;
        k %= total;
        vector<bool> store(n, true);
        string ans = "";
        for(int i {n}; i ; i--){
            total /= i;
            int skip {k/total+1}, idx {};
            for(int j {}; j < size(store); j++){
				if(!skip) break;
				if(store[j]) skip--, idx = j;
			}
            k %= total;
            store[idx] = false;
            ans += to_string(idx+1);
        }
        return ans;
    }
};
