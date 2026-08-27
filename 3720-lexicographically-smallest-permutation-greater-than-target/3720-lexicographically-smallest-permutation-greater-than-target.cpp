class Solution{
public:
    string lexGreaterPermutation(string s,string target){
        int size=s.size();
        string result="";
        map<char,int>freq;
        for(int idx=0;idx<size;idx++) freq[s[idx]]++;

        int found=0,pos=0;
        while(pos<size){
            if(freq.find(target[pos])!=freq.end()){
                result+=target[pos];
                freq[target[pos]]--;
                if(freq[target[pos]]==0) freq.erase(target[pos]);
                pos++;
            }else break;
        }

        if(pos<size){
            auto ptr=freq.upper_bound(target[pos]);
            if(ptr!=freq.end()){
                char bigger=ptr->first;
                freq[bigger]--;
                if(freq[bigger]==0) freq.erase(bigger);
                result+=bigger;
                found=1;
            }
        }

        if(found==0){
            for(int back=pos-1;back>=0;back--){
                freq[result[back]]++;
                auto ptr=freq.upper_bound(target[back]);
                if(ptr!=freq.end()){
                    char bigger=ptr->first;
                    freq[bigger]--;
                    if(freq[bigger]==0) freq.erase(bigger);
                    result=result.substr(0,back);
                    result+=bigger;
                    found=1;
                    break;
                }
            }
        }

        if(found==1){
            for(auto entry:freq){
                int times=entry.second;
                for(int cnt=0;cnt<times;cnt++) result+=entry.first;
            }
            return result;
        }
        return "";
    }
};