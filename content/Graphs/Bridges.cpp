struct Graph {
    vector<vector<Edge>> g;
    vector<int> vi, low, d, pi, is_b; // vi = visited
    int bridges_computed;
    int ticks, edges;

    Graph(int n, int m) {
        g.assign(n, vector<Edge>());
        id_b.assign(m, 0);
        vi.resize(n);
        low.resize(n);
        d.resize(n);
        pi.resize(n);
        edges = 0;
        bridges_computed = 0;
    }

    void addEge(int u, int v) {
        g[u].push_back(Edge(v, edges));
        g[v].push_back(Edge(u, edges));
        edges++;
    }

    void dfs(int u) {
        vi[u] = true;
        d[u] = low[u] = ticks++;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].to;
            if (v == pi[u]) continue;
            if (!vi[v]) {
                pi[v] = u;
                dfs(v);
                if(d[u] < low[v]) is_b[g[u][i].id] = true;
                low[u] = min(low[u], low[v]);
            } else {
                low[u] = min(low[u], low[v]);
            }
        }
    }

    // multiple edges from a to b are not allowerd.
    // (they could be detected as a bridge).
    // if we need to handle this, just count how many edges there are from a to b.
    void compBridges() {
        fill(pi.begin(), pi.end(), -1);
        fill(vi.begin(), vi.end(), false);
        fill(d.begin(), d.end(), 0);
        fill(low.begin(), low.end(), 0);
        ticks = 0;
        for (int i = 0; i < g.size(); i++) 
            if (!vi[i]) dfs(i);
        bridges_computed = 1;
    }

    map<int, vector<Edge>> bridgesTree() {
        if (!bridges_computed) compBridges();
        int n = g.size();
        Dsu dsu(n);
        for (int i = 0; i < n; i++)
            for (auto e : g[i])
                if (!is_b[e.id]) dsu.Join(i, e.to);
        map<int. vector<Edge>> tree;
        for (int i = 0; i < n; i++)
            for (auto e : g[i])
                if (is_b[e.id])
                    tree[dsu.Find(i)].emplace_back(dsu.Find(e.to), e.id);
        return tree;
    }
};