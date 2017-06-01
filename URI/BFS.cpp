void bfs(int init, vi *adj, bool *vis, int *level) {
    queue<int> q;
    vis[init] = true;
    level[init] = 0;
    q.push(init);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i=0; i< adj[v].size(); i++) {
            if (!vis[adj[v][i]]) {
                vis[adj[v][i]] = true;
                level[adj[v][i]] = level[v] +1;
                q.push(adj[v][i]);
            }
        }
    }
}
