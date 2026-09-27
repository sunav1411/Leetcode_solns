class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        auto sorelanuxi=source;

        long long jiju=0;

        for(int i=0;i<source.size();i++){
            jiju+=(long long)source[i]-target[i];
        }
        return jiju==0;
    }
};