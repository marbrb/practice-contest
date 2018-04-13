#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool cond;

void bfs (vvi &adj, vi &color, int node) {
  color[node]=0;
  queue <int> q;
  q.push(node);
  while (!q.empty()) {
    int v = q.front();q.pop();
    for(int i=0; i<adj[v].size();i++){
      int u=adj[v][i];
      if(color[u] == -1){
        color[u] = 1 - color[v];
        q.push(u);
      } else if(color[u] == color[v]){
        cond = true;
      }
    }
  }
}

int main() {
  int n, x, y;
  while (cin >> n && n){
    vvi adj(n);
    vi color(n, -1);
    cond=false;
    while (cin >> x >> y && (x && y)){
      x--; y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    for (int i=0; i<n;i++){
      if (color[i] == -1 && !cond){
        bfs(adj, color, i);
      }
    }

    if (cond)
      cout << "NO\n";
    else
      cout << "YES\n";
  }

  return 0;
}
