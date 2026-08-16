class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int>f(3,0);
        for(int s:stones)f[s%3]++;
        if(f[0]%2==0){
            return(f[1]>=1 && f[2]>=1);
        }
        return(abs(f[1]-f[2])>=3) ? true : false;

    }
};