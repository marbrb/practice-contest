#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

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

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vi *adj = new vi[n+1];
        int x, y;
        for (int i=0; i<m; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        bool vis[n+1];
        for (int i=0; i<=n; i++) vis[i]=false;

        int dis[n+1];
        for (int i=0; i<=n; i++) dis[i]=0;

        bfs(1, adj, vis, dis);

        cout << dis[n] << '\n';
    }
    return 0;
}
