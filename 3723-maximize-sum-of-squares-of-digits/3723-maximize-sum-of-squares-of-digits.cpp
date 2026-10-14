class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num * 9) return "";
        string ans = "";
        int curr = 9;
        while(ans.length() < num){
            if(curr <= sum){
                ans += to_string(curr);
                sum -= curr;
            }
            else curr -= 1;
        }

        return ans;
    }
};