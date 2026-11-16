class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string str="";
            int j=s.size()/k;
            for(int i=0; i<j*k; i+=k){
                int n=0;
                for(int l=0; l<k; l++){
                    n+=s[i+l]-'0';
                }
                str+=to_string(n);
            }
            if(j*k<s.size()){
                int m=0;
                for(int i=j*k; i<s.size(); i++){
                    m+=s[i]-'0';
                }
                str+=to_string(m);
            }
            s=str;
        }
        return s;
    }
};