#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

vi sol;

void toposort(vvi &adj, int node, vb &vis){
  vis[node] = 1;
  for (int i=0; i<adj[node].size();i++){
    if(!vis[adj[node][i]]){
      toposort(adj, adj[node][i], vis);
    }
  }

  sol.push_back(node);
}
int main(){
  int n, m, x, y;
  while(cin >> n >> m && n){
    vvi adj(n+1);
    while(m--){
      cin >> x >> y;
      adj[x].push_back(y);
    }

    sol = vi(0);
    vb vis(n+1);
    for(int i=1;i<=n;i++){
      if (!vis[i])
        toposort(adj, i, vis);
    }

    bool sp=false;
    for(int i=n-1;i>=0;i--){
      if(sp){cout << ' ';}
      sp=true;
      cout << sol[i];
    }cout << endl;

  }  

  return 0;
}
