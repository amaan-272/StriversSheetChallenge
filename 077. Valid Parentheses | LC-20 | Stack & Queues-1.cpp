//CodeStudio Code
bool isValidParenthesis(string expression) {
    if(expression.size()%2) return false;
    stack<char> st;  
    for(char i:expression) {
        if(i=='(' || i=='{' || i=='[') st.push(i);  
        else {
            if(st.empty() || (st.top()=='(' && i!=')') || (st.top()=='{' && i!='}') || (st.top()=='[' && i!=']')) return false;
            st.pop();  
        }
    }
    return st.empty();
}

//LeetCode Code
class Solution {
public:
    bool isValid(string s) {
        stack<char> bracs;
        for(char& c:s){
            switch(c){
                case '(':
                case '{':
                case '[':
                    bracs.push(c);
                break;
                case ')':
                case '}':
                case ']': {
                    if(bracs.empty()) return false;
                    char req;
                    if(c == ')') req = '(';
                    if(c == '}') req = '{';
                    if(c == ']') req = '[';
                    if(bracs.top() == req) bracs.pop();
                    else return false;
                }
                break;
                default: return false;
            }
        }
        return bracs.empty();
    }
};
