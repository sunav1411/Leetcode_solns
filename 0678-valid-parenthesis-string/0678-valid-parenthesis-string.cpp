class Solution{
public:
    bool checkValidString(string s){
        vector<int> left,star;
        int idx=0;

        for(char ch:s){
            if(ch=='(') left.push_back(idx);
            else if(ch=='*') star.push_back(idx);
            else{
                if(!left.empty()) left.pop_back();
                else if(!star.empty()) star.pop_back();
                else return false;
            }
            idx++;
        }

        while(!left.empty()&&!star.empty()){
            if(left.back()<star.back()){
                left.pop_back();
                star.pop_back();
            }else break;
        }

        return left.empty();
    }
};