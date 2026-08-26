class Solution {
public:
    string shortestBeautifulSubstring(string s,int k){
        int n=s.size();
        string ans;
        int len=n+1;
        int i=0,j=0,ones=0;

        while(j<n){
            while(j<n&&ones<k){
                if(s[j]=='1') ones++;

                if(ones==k){
                    string t=s.substr(i,j-i+1);
                    if(t.size()<len){
                        len=t.size();
                        ans=t;
                    }
                    else if(t.size()==len&&ans>t) ans=t;
                }
                j++;
            }

            while(i<j&&ones>=k){
                if(s[i]=='1') ones--;
                i++;

                if(ones==k){
                    string t=s.substr(i,j-i);
                    if(t.size()<len){
                        len=t.size();
                        ans=t;
                    }
                    else if(t.size()==len&&ans>t) ans=t;
                }
            }
        }

        return ans;
    }
};