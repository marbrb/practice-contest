#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int ene, fri;

int bfs (vvi &adj, vi &color, int node){
  color[node] = 0;
  ene++;
  queue<int> q;
  q.push(node);
  bool cycle=false;
  while(!q.empty()){
    int v =q.front(); q.pop();
    for(int i=0; i<adj[v].size(); i++){
      int u = adj[v][i];
      int c = 1 - color[v];
      if(color[u] == -1){
        fri += c;
        ene += (1 ? !c : 0);
        color[u] = c;
        q.push(u);
      } else if (color[u] == color[v]){
        cycle=true;
      }
    }
  }
  if (cycle) return 0;
  return max(ene, fri);
}


int main () {
  int t, n, enemies, e;
  cin >> t;

  while(t--) {
    cin >> n;
    vvi adj(n+1);
    vi color(n+1, -1);

    for(int j=1; j<=n;j++){
      cin >> enemies;
      for(int i=0; i<enemies; i++){
        cin >> e;
        if (e>n) continue;
        adj[j].push_back(e);
        adj[e].push_back(j);
      }
    }

    // for(int i=1; i<=adj.size()-1; i++){
    //   cout << i << " : ";
    //   for(auto e: adj[i]) cout << e <<  ' ';
    //   cout << endl;
    // }

    int res =0;
    for(int i=1; i<=adj.size()-1; i++){
      if (color[i] == -1){
        ene=0; fri=0;
        res += bfs(adj, color, i);
      }
    }

    cout << res << '\n';


  }
  return 0;
}
