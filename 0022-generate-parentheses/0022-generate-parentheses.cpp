class Solution {
public:
    void generate(int op,int cp,vector<char> &str, vector<string> &result,int i,int len)
    {
        if(i == len){
            result.push_back(string(str.begin(),str.end()));
        }
        if(op>0)
        {
            str[i]='(';
            generate(op-1,cp,str,result,i+1,len);
        }
        if(cp>op)
        {
            str[i]=')';
            generate(op,cp-1,str,result,i+1,len);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n<=0){return result;}
        vector<char> str(n*2);

        str[0]='(';
        generate(n-1,n,str,result,1,n*2);

        return result;
        
    }
};