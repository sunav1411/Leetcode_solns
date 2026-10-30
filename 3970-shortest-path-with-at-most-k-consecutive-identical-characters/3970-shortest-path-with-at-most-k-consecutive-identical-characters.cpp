class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<pair<pair<int, int>, int>> adj[n];
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({{w, v}, 1});
        }
        priority_queue<
            pair<pair<int, int>, int>,
            vector<pair<pair<int, int>, int>>,
            greater<pair<pair<int, int>, int>>
        > pq;
        pq.push({{0, 0}, 1});
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        dist[0][1] = 0;
        while(!pq.empty()){
            int wt = pq.top().first.first;
            int node = pq.top().first.second;
            int cnt = pq.top().second;
            pq.pop();
            if(cnt > k) continue;
            if(node == n-1) return wt;
            for(auto it: adj[node]){
                int adjNode = it.first.second;
                int currWt = it.first.first;
                int newCnt;

                if(labels[node] == labels[adjNode]){
                    newCnt = cnt + 1;
                } else{
                    newCnt = 1;
                }
                if(newCnt > k) continue;

                if(dist[adjNode][newCnt] > wt + currWt){
                    dist[adjNode][newCnt] = wt + currWt;
                    pq.push({{wt+currWt, adjNode}, newCnt});
                }
            }
        }

        return -1;
    }
};