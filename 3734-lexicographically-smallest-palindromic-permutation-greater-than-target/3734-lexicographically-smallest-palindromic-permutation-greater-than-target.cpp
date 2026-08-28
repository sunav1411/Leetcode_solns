class Solution{
public:
    string lexPalindromicPermutation(string str,string target){
        int freq[26]={0};
        for(char ch:str) freq[ch-'a']++;

        char center=0;
        for(int idx=0;idx<26;idx++){
            if(freq[idx]%2){
                if(center!=0) return "";
                center='a'+idx;
                freq[idx]--;
            }
        }

        int n=str.length();
        int half=n/2;

        for(int idx=0;idx<half;idx++)
            freq[target[idx]-'a']-=2;

        if(check(freq)){
            string head=target.substr(0,half);
            string rev=head;
            reverse(rev.begin(),rev.end());
            string tail="";

            if(center!=0) tail+=center;
            tail+=rev;

            if(tail>target.substr(half))
                return head+tail;
        }

        for(int idx=half-1;idx>=0;idx--){
            char ch=target[idx];
            freq[ch-'a']+=2;

            if(!check(freq)) continue;

            for(int nxt=ch-'a'+1;nxt<26;nxt++){
                if(freq[nxt]==0) continue;

                freq[nxt]-=2;
                string result=target.substr(0,idx+1);
                result[idx]='a'+nxt;

                for(int pos=0;pos<26;pos++){
                    int cnt=freq[pos]/2;
                    if(cnt>0) result.append(cnt,'a'+pos);
                }

                string rev=result;
                reverse(rev.begin(),rev.end());
                if(center!=0) result+=center;
                result+=rev;
                return result;
            }
        }

        return "";
    }

    bool check(int f[]){
        for(int idx=0;idx<26;idx++)
            if(f[idx]<0) return false;
        return true;
    }
};