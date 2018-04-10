#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


bool bfs (vvi &adj){
  queue<int> q;
  vi color(adj.size(), -1);
  color[0] = 0;
  q.push(0);

  while(!q.empty()){
    int v = q.front(); q.pop();
    for (int i=0; i<adj[v].size(); i++){
      int u=adj[v][i];
      if(color[u] == -1){
        color[u] = 1 - color[v];
        q.push(u);
      } else if (color[u] == color[v]) {
        return false;
      }
    }
  }

  return true;
}


int main() {
  int n, m, x, y;

  while (cin >> n && n){
    vvi adj(n);
    cin >> m;
    while(m--){
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    if (bfs(adj)){
      cout << "BICOLORABLE.\n";
    } else {
      cout << "NOT BICOLORABLE.\n";
    }
  }
  return 0;
}
