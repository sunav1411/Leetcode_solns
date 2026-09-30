class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int maxi = 0;
        int depth = 0;
        vector<int> arr;
        for(auto ch: seq){
            if(ch == '(') depth++;
            arr.push_back(depth);
            maxi = max(depth, maxi);
            if(ch == ')') depth--;
        }

        int half = maxi/2;
        for(int i=0; i<arr.size(); i++)
            arr[i] = arr[i] > half ? 1 : 0;
        
        return arr;
    }
};