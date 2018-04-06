#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi res;
bool cond=false;

void dfs(vvi &adj, int node, vi &vis){
  vis[node] = 1;
  for (int i=0; i< adj[node].size(); i++){
    if (!vis[adj[node][i]]){
      dfs(adj, adj[node][i], vis);
    } else if(vis[adj[node][i]] == 1){
      cond=true;
      break;
    }
  }

  vis[node] = 2;
  res.push_back(node);
}

int main(){
  int n, m, x, y;
  while(cin >> n >> m && n){
    res = vi(0);
    vvi adj(n+1);
    vi vis(n+1);
    vi ind(n+1, 0);
    while (m--){
      cin >> x >> y;
      adj[x].push_back(y);
      ind[y]++;
    }
    vii nodes;
    for (int i=1;i<=n;i++){
      nodes.push_back(ii(ind[i], i));
    }

    sort(nodes.begin(), nodes.end());

    cond=false;
    for (int i=0;i<n;i++){
      if (!vis[nodes[i].second])
        dfs(adj, nodes[i].second, vis);
    }

    if (cond){
      cout << "IMPOSSIBLE\n";
      continue;
    }

    for (int i=n-1;i>=0;i--){
      cout << res[i] << endl;
    }
  }
  return 0;
}
