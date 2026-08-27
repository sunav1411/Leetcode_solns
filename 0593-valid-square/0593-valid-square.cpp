class Solution{
public:
    bool validSquare(vector<int>& p1,vector<int>& p2,vector<int>& p3,vector<int>& p4){
        vector<long> dist={
            distSq(p1,p2),distSq(p1,p3),distSq(p1,p4),
            distSq(p2,p3),distSq(p2,p4),distSq(p3,p4)
        };

        sort(dist.begin(),dist.end());

        return dist[0]>0&&dist[0]==dist[1]&&dist[1]==dist[2]&&
               dist[2]==dist[3]&&dist[4]==dist[5]&&dist[3]<dist[4];
    }

private:
    long distSq(vector<int>& a,vector<int>& b){
        return (long)(a[0]-b[0])*(a[0]-b[0])+
               (long)(a[1]-b[1])*(a[1]-b[1]);
    }
};