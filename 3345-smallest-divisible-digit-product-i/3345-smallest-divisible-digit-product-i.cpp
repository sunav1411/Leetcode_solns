class Solution {
private:
    int giveDigitsProd(int n){
        if(n < 10) return n;
        return (n % 10) * giveDigitsProd(n / 10);
    }

public:
    int smallestNumber(int n, int t) {
        int check = giveDigitsProd(n);

        if(check % t == 0)
            return n;
        return smallestNumber(n + 1, t);
    }
};