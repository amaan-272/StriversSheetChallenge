//CodeStudio Code
vector<int> stringMatch(string text, string pattern) {
    vector<int> ans; 
    int n = text.length(), m = pattern.length(); 
    for(int i {}; i <= n-m; i++) {
        bool found = true;
        for(int j {}; j < m; j++) {
            if(text[i+j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if(found) ans.emplace_back(i+1);
    }   
    return ans;
}
