#include <bits/stdc++.h>
using namespace std;

typedef map<string, int> msi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<bool> vb;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef vector <iii> viii;

int res = 0;

void dfs(vvii &adj, int fr, int to, int weight, vb &vis){
  vis[fr] = 1;
  if (fr == to){
    res = weight;
    return;
  }
  for (int i=0;i<adj[fr].size();i++){
    if (!vis[adj[fr][i].first]){
      dfs(adj, adj[fr][i].first, to, min(weight, adj[fr][i].second), vis);
    }
  }
  return;
}

struct union_find {
  vi p;
  union_find (int n) : p(n, -1) {}

  int find(int x){
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }

  bool unite (int x, int y) {
      int xp = find(x), yp = find(y);
      if (xp == yp) return false;
      if (p[xp] > p[yp]) swap(xp, yp);
      p[xp] += p[yp];
      p[yp] = xp;
      return true;
  }
};

int main(){
  int n, r, w;
  int k=1, z=0;
  while (cin >> n >> r && (n && r)) {
    string x, y;
    viii edgeList;
    msi dict;
    z++;
    while (r--){
      cin >> x >> y >> w;
      if (!dict[x]){
        dict[x] = k; k++;
      }
      if (!dict[y]){
        dict[y] = k; k++;
      }
      edgeList.push_back(make_pair(w, ii(dict[x], dict[y])));
    }
    k=1;
    cin >> x >> y; // from and to

    sort(edgeList.rbegin(), edgeList.rend());

    union_find uf(n+1);
    vvii adj(n+1);

    for (auto e : edgeList){
      if (uf.unite(e.second.first, e.second.second)){
        adj[e.second.first].push_back(ii(e.second.second, e.first));
        adj[e.second.second].push_back(ii(e.second.first, e.first));
      }
    }

    // for (int i=1;i< adj.size();i++){
    //   cout << i << " : ";
    //   for (int j=0; j < adj[i].size();j++){
    //     cout << adj[i][j].first << ' ';
    //   }cout << endl;
    // }

    vb vis(n+1, 0);
    dfs(adj, dict[x], dict[y], 1e8, vis);
    cout << "Scenario #" << z << '\n';
    cout << res << " tons\n\n";
    res = 0;

  }
  return 0;
}
