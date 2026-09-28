class Solution {
public:
    int maxDepth(string &s) {
        int ans = 0;
        int curr = 0;
        int skip = 0;

        for(char &c : s){
          if(c == '(') curr++;
          else if(c == ')'){
            if(skip == curr && skip){
                curr--;
                skip--;
                continue;
            }
            ans = max(ans,curr);
            curr--;
            skip = curr;
          }
        }

        return ans;
    }
};