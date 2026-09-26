class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        int n = knowledge.size();

        // making the map
        for(int i=0; i<n; i++){
            string key = knowledge[i][0];
            string value = knowledge[i][1];

            mp[key] = value;
        }

        string result = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                int idx = i+1;
                string temp = "";
                while(idx < s.length() && s[idx] != ')'){
                    temp += s[idx];
                    idx++;
                }

                if(mp.find(temp) != mp.end()){
                    result += mp[temp];
                }
                else{
                    result += "?";
                }

                i = idx;
            }
            else if(s[i] != '(' && s[i] != ')'){
                result += s[i];
            }
        }

        return result;
    }
};