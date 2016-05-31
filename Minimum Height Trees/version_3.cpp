class Solution {
private:
    typedef vector<int> vec;
    typedef vector<pair<int, int>> vpi;
public:
    vec findMinHeightTrees(int n, vpi& edges) {
        tot = 0, ret.clear();
        if (edges.empty()) { ret.push_back(0); return ret; }
        init(n, edges);
        vec ans = solve(n);
        __free__();
        return ans;
    }
private:
    vec ret;
    int tot, *head, *dist, *pre;
    struct edge { int to, next; }*G;
    inline void init(int n, vpi& edges) {
        int m = n + 10;
        pre = new int[m];
        head = new int[m];
        dist = new int[m];
        memset(pre, -1, sizeof(int)* m);
        memset(head, -1, sizeof(int)* m);
        m = edges.size();
        G = new edge[(m + 10) << 1];
        for (int i = 0; i < m; i++) {
            int u = edges[i].first, v = edges[i].second;
            add_edge(u, v);
        }
    }
    inline void add_edge(int u, int v) {
        G[tot].to = v, G[tot].next = head[u], head[u] = tot++;
        G[tot].to = u, G[tot].next = head[v], head[v] = tot++;
    }
    inline int bfs(int s, int n, bool f = false) {
        int id = s, max_dist = 0;
        memset(dist, -1, sizeof(int) * (n + 10));
        queue<int> q; q.push(s);
        dist[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (dist[u] > max_dist) {
                max_dist = dist[id = u];
            }
            for (int i = head[u]; ~i; i = G[i].next) {
                int &v = G[i].to;
                if (-1 == dist[v]) {
                    dist[v] = dist[u] + 1;
                    if (f) pre[v] = u;
                    q.push(v);
                }
            }
        }
        return id;
    }
    inline vec solve(int n) {
        int s = bfs(0, n);
        int t = bfs(s, n, true);
        vec ans;
        for (; ~t; t = pre[t]) ret.push_back(t);
        n = ret.size();a
        if (!n) return ans;
        ans.push_back(ret[n / 2]);
        if (!(n & 1)) ans.push_back(ret[n / 2 - 1]);
        if (ans.size() > 1 && ans[0] > ans[1]) swap(ans[0], ans[1]);
        return ans;
    }
    inline void __free__() {
        delete []G; delete []pre;
        delete []dist; delete []head;
    }
};