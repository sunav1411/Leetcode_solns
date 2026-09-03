class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
    int n=num.size();
    while(k>0||n>0){
        if(n>0){
            num[n-1]+=k;
            k=num[n-1]/10;
            num[n-1]%=10;
        }else{
            num.insert(num.begin(),k%10);
            k/=10;
        }
        n--;
    }
    return num;   
    }
};