void dfs(int node, bool *vis, vi *adj) {
    vis[node] = true;
    for(int i=0; i<adj[node].size(); i++) {
        if (!adj[node][i])
          dfs(adj[node][i], vis, adj);
    }
}
