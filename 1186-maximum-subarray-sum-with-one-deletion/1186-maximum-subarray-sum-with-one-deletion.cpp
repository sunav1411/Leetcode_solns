class Solution{
public:
    int maximumSum(vector<int>& arr){
        int deleted=0;
        int curr=arr[0];
        int answer=arr[0];

        for(int idx=1;idx<arr.size();idx++){
            deleted=max(deleted+arr[idx],curr);
            curr=max(curr+arr[idx],arr[idx]);
            answer=max(answer,max(deleted,curr));
        }

        return answer;
    }
};