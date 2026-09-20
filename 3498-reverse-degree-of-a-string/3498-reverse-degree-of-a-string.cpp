class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int total=0;
        for(int i=1;i<=n;i++){
            int temp=(122-s[i-1])+1;
            temp*=i;
            total+=temp;

        }
        return total;
    }
};