class Solution {
public:
    int hIndex(vector<int>& citations) {
          sort(citations.begin(),citations.end());
          int count=0;

        for(int idx=citations.size()-1;idx>=0;idx--){
            int need=count+1;
            if(citations[idx]<need) break;
            count++;
        }
        return count;
    }
};