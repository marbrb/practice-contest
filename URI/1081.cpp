#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

//void
void dfs(int node, int cont, bool *vis, vi *adj) {
    if (vis[node]) return;
    vis[node] = true;
    string st;
    for (int i=0; i<= cont; i++) st += "  ";
    for(int i=0; i<adj[node].size(); i++) {
        if (vis[adj[node][i]])
            cout << st << node << "-" << adj[node][i] << "\n";
        else
            cout << st << node << "-" << adj[node][i] << " pathR(G," << adj[node][i] << ")\n";

        dfs(adj[node][i], cont+1, vis, adj);
    }

}

int main() {
    int n, v, e;
    int auxv, auxe;
    cin >> n;
    for (int i=1; i<=n; i++){
        cout << "Caso " << i << ":\n";
        cin >> v >> e;
        vi *adj = new vi[v];
        bool vis[v];

        for (int i=0; i<v;i++) vis[i]=false;

        for (int i=0; i<e; i++) {
            cin >> auxv >> auxe;
            adj[auxv].push_back(auxe);
        }
        for (int i=0; i<v; i++) sort(adj[i].begin(), adj[i].end());

        for (int i=0; i<v; i++){
            if (!vis[i] && adj[i].size()>0){
                dfs(i, 0, vis, adj);
                cout << '\n';
            }
        }

    }




  return 0;
}
