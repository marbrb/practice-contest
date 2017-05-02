#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

void dfs(int node, vi &components, bool *vis, vi *adj) {
    if (vis[node]) return;
    vis[node] = true;
    components.push_back(node);
    for(int i=0; i<adj[node].size(); i++) {
        dfs(adj[node][i], components, vis, adj);
    }

}

int main() {
    int n, v, e, a,b;
    char auxv, auxe;
    cin >> n;
    for (int j=1; j<=n; j++){
        cout << "Case #" << j <<":\n";
        cin >> v >> e;
        vi *adj = new vi[v];
        bool vis[v];

        for (int i=0; i<v;i++) vis[i]=false;

        for (int i=0; i<e; i++) {
            cin >> auxv >> auxe;
            a = (int)auxv - 97; b = (int)auxe - 97;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int cont=0;
        for (int i=0; i<v; i++){
          if (!vis[i]){
              vi components;
              dfs(i, components, vis, adj);
              sort(components.begin(), components.end());
              for (int com: components) {
                printf("%c,", (char)com + 97);
              }
              cout << '\n';
              cont++;
          }

        }
        cout << cont << " connected components\n\n";

    }

  return 0;
}
