#include <bits/stdc++.h>

using namespace std;
typedef set<int> si;
typedef vector<int> vi;
int v, e;



void dfs(int node, si *adj, bool *vis) {
  if (vis[node]) return;
  vis[node] = true;
  v += 1;

  for (auto x : adj[node]) {
    if (x != node) e += 1;
    dfs(x, adj, vis);
  }
}

int main() {
  int n;
  char aux;
  cin >> n;
  si *adj = new si[n];

  bool vis[n];
  for (int i=0; i<n; i++) vis[i]=false;

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> aux;
      if (aux == 'S'){
        adj[i].insert(j);
      }
    }
  }
  vi res;
  for (int i=0; i<n; i++) {
    if (!vis[i]) {
      v = 0;
      e = 0;
      dfs(i, adj, vis);
      if (v * (v-1) != e) {
        cout << "-1\n";
        return 0;
      }
      res.push_back(v);
    }
  }
  sort(res.rbegin(), res.rend());
  cout << res.size() << '\n';
  for (int i=0; i < res.size()-1; i++) {
    cout << res[i] << " ";
  }
  cout << res.back() << '\n';

  return 0;
}
