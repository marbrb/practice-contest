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
    int n, x, auxv, auxe;
    cin >> n;
    vi *adj = new vi[n+1];
    for (int i=1; i<n; i++) {
        cin >> auxv >> auxe;
        adj[auxv].push_back(auxe);
        adj[auxe].push_back(auxv);
    }
    int level[n+1];
    cin >> x;
    for (int i=0; i<n+1;i++) level[i]=0;


    bool visited[n+1];
    for (int j=0; j<=n; j++) visited[j]=false;

    int res = 0;
    bfs(1,adj, visited, level);
    for (int i=1; i<=n; i++) {
      if (level[i] == x-1) res++;
    }
    cout << res << '\n';

    return 0;
}
