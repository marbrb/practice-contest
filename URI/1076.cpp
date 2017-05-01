#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

void dfs(int node, int &cont, bool *vis, vi *adj) {
    if (vis[node]) return;
    vis[node] = true;
    cont++;

    for(int i=0; i<adj[node].size(); i++) {
        dfs(adj[node][i], cont, vis, adj);
    }

}

int main() {
    int n, v, e;
    int auxv, auxe;
    cin >> n;
    while (n--){
        int init, cont=-1;
        cin >> init;
        cin >> v >> e;
        vi *adj = new vi[v];
        bool vis[v];

        for (int i=0; i<v;i++) vis[i]=false;

        for (int i=0; i<e; i++) {
            cin >> auxv >> auxe;
            adj[auxv].push_back(auxe);
            adj[auxe].push_back(auxv);
        }

        dfs(init, cont, vis, adj);
        cout << cont*2 << endl;

    }




  return 0;
}
