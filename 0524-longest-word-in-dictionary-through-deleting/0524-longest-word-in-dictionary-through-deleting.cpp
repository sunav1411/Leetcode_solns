class Solution{
public:
    string findLongestWord(string s,vector<string>& dictionary){
        int n=s.size();
        int next_pos[1005][26];

        for(int c=0;c<26;c++)
            next_pos[n][c]=n;

        for(int idx=n-1;idx>=0;idx--){
            for(int c=0;c<26;c++)
                next_pos[idx][c]=next_pos[idx+1][c];
            next_pos[idx][s[idx]-'a']=idx;
        }

        string best="";
        for(auto word:dictionary){
            int len=word.size();
            int best_len=best.size();

            if(len<best_len) continue;
            if(len==best_len&&word>=best) continue;

            int pos=0;
            bool ok=true;

            for(char ch:word){
                pos=next_pos[pos][ch-'a'];
                if(pos==n){
                    ok=false;
                    break;
                }
                pos++;
            }

            if(ok) best=word;
        }
        return best;
    }
};