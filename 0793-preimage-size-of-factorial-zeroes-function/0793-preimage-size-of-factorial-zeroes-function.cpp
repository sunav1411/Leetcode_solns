class Solution{
public:
    int countZeros(int num){
        unsigned power=5;
        int result=0;
        while(power<=num){
            result+=num/power;
            power*=5;
        }
        return result;
    }

    int preimageSizeFZF(int k){
        unsigned left=1,right=((unsigned)k/6+1)*25;

        while(left<=right){
            unsigned mid=left+(right-left)/2;
            int zeros=countZeros(mid);

            if(zeros==k) return 5;
            else if(zeros>k) right=mid-1;
            else left=mid+1;
        }
        return 0;
    }
};