class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void update(int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        }

        int query(int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        }

        void rangeUpdate(int l, int r, int val) {
            update(l, val);
            update(r + 1, val);
        }
    };

public:
    vector<bool> palindromePath(
        int n, vector<vector<int>>& edges,
        string s, vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> parent(n), depth(n), tin(n), tout(n);
        vector<int> rootMask(n, 0), order;
        vector<bool> visited(n, false);

        stack<int> st;
        st.push(0);
        visited[0] = true;
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            tin[u] = (int)order.size();
            order.push_back(u);

            rootMask[u] =
                (u == 0 ? 0 : rootMask[parent[u]]) ^
                (1 << (s[u] - 'a'));

            for (int v : adj[u]) {
                if (visited[v]) continue;

                visited[v] = true;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push(v);
            }
        }

        for (int i = 0; i < n; i++)
            tout[i] = tin[i];

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            tout[parent[u]] = max(tout[parent[u]], tout[u]);
        }

        for (int u = 0; u < n; u++)
            up[0][u] = parent[u];

        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j))
                    u = up[j][u];
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return parent[u];
        };

        Fenwick fw(n + 1);
        vector<bool> answer;

        for (string& q : queries) {
            string type;
            int u;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                fw.rangeUpdate(tin[u] + 1, tout[u] + 1, delta);
                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int maskU = rootMask[u] ^ fw.query(tin[u] + 1);
                int maskV = rootMask[v] ^ fw.query(tin[v] + 1);
                int maskW = 1 << (s[w] - 'a');

                int pathMask = maskU ^ maskV ^ maskW;

                answer.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return answer;
    }
};