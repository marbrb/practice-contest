#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool cond;


int bfs (vvi &adj, vi &color, int node) {
  int white=1, black=0;
  color[node]=0;
  queue <int> q;
  q.push(node);
  while (!q.empty()) {
    int v = q.front();q.pop();
    for(int i=0; i<adj[v].size();i++){
      int u=adj[v][i];
      int c = 1 - color[v];
      if(color[u] == -1){
        white += (1 ? !c : 0);
        black += c;
        color[u] = c;
        q.push(u);
      } else if(color[u] == color[v]){
        cond = true;
      }
    }
  }
  int mini = min(white, black);
  return (mini ? mini : max(white, black));
}


int main () {
  int t, n,m, x, y;
  cin >> t;
  while (t--){
    cin >> n >> m;
    vvi adj(n);
    vi color(n, -1);
    while(m--){
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    cond=false;
    int res = 0;
    for(int i=0; i<n;i++){
      if((color[i] == -1) && !cond)
        res += bfs(adj, color, i);
    }

    if (cond)
      cout << "-1\n";
    else
      cout << res << '\n';


  }
  return 0;
}
