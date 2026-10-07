class Solution {
public:
    void find(unordered_set<string> &ans,int idx,string &s,string &str,int open,int close,int balance){
        if(idx == s.length()){
            if(open == 0 && close == 0 && balance == 0) ans.insert(str);
            return;
        }
        if(s[idx] == '('){
            if(open > 0){
                find(ans,idx+1,s,str,open-1,close,balance);
            }
            str.push_back('(');
            find(ans,idx+1,s,str,open,close,balance+1);
            str.pop_back();
        }
        else if(s[idx] == ')'){
            if(close > 0){
                find(ans,idx+1,s,str,open,close-1,balance);
            }
            if(balance > 0){
                str.push_back(')');
                find(ans,idx+1,s,str,open,close,balance-1);
                str.pop_back();
            }
        }
        else{ 
            str += s[idx];
            find(ans,idx+1,s,str,open,close,balance);
            str.pop_back();
        }

    }
    vector<string> removeInvalidParentheses(string s) {
        int open = 0,close = 0;
        for(char c:s){
            if(c == '(')open++;
            else if(c == ')'){
                if(open > 0) open--;
                else  close++;
            }else{
                continue;
            }
        }
        if(open == close && open == 0) return {s};
        int balance = 0;
        unordered_set<string> ans;
        string str = "";
        find(ans,0,s,str,open,close,balance);
        vector<string> v(ans.begin(),ans.end());
        return v;
    }
};