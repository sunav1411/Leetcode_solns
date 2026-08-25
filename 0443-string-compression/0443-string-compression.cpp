class Solution {
public:
    int compress(vector<char>& chars) {
        string temp="";
        for(int i=0;i<chars.size();){
            char ch=chars[i];
            int cnt=0;
            while(i<chars.size() and chars[i]==ch){
                cnt++;
                i++;
            }
            temp+=ch;
            if(cnt>1){
                temp+=to_string(cnt);
            }
        }
         for(int j = 0; j < temp.size(); j++) {
            chars[j] = temp[j];
        }
        return temp.size();
    }
};