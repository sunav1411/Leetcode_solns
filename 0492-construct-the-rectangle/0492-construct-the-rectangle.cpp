class Solution{
public:
    vector<int> constructRectangle(int area){
        int side=(int)sqrt(area);
        while(area%side!=0) side--;
        return {area/side,side};
    }
};