class Solution{
public:
    bool detectCapitalUse(string word){
        int bade=0;
        for(char ch:word)
            if(isupper(ch)) bade++;
        return bade==word.length()||bade==0||(bade==1&&isupper(word[0]));
    }
};