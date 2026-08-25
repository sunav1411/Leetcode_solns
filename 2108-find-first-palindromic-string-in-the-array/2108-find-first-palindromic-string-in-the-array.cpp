class Solution {

bool checkPalindrome(string s){
    int start = 0;
    int end = s.size() - 1;

    while(start < end){
        if(s[start] == s[end]){
            start++;
            end--;
        }
        else return false;
    }

    return true;
}
public:
    string firstPalindrome(vector<string>& words) {

        for(int i = 0 ; i < words.size() ;i++){

            string str = words[i];

            if(checkPalindrome(str)) return str;
        }

        return "";
        
    }
};