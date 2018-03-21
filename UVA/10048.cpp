#include<bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<bool> vb;

struct union_find {
    vi p;
    union_find(int n) : p(n, -1) {}

    int find(int x) {
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

void dfs(vvii &adj, int node, int fr, int w, vvi &dists, vb &vis){
  vis[fr] = 1;
  for(int i=0; i< adj[fr].size();i++){
    if(!vis[adj[fr][i].first]){
      int m = max(w, adj[fr][i].second);
      dists[node][adj[fr][i].first] = m;
      dists[adj[fr][i].first][node] = m;
      vis[adj[fr][i].first] = 1;
      dfs(adj, node, adj[fr][i].first, m, dists, vis);
      vis[adj[fr][i].first] = 0;
    }
  }
  vis[fr] = 0;
}

int main(){
  int n, m, q, x, y, w, k=1;
  bool space=false;
  while (cin >> n >> m >> q && (n != 0 && m != 0 && q != 0)){
    union_find uf(n+1);
    viii edges;
    while (m--){
      cin >> x >> y >> w;
      edges.push_back(make_pair(w, ii(x, y)));
    }
    sort(edges.begin(), edges.end());
    vvii adj(n+1);
    vvi dists(n+1, vi(n+1, -1));

    for (auto e : edges){
      if (uf.unite(e.second.first, e.second.second)){
        adj[e.second.first].push_back(ii(e.second.second, e.first));
        adj[e.second.second].push_back(ii(e.second.first, e.first));
      }
    }

    vector<bool> vis(n+1, 0);
    for (int i=1; i<=n; i++){
      dfs(adj, i,  i, -1, dists, vis);
    }

    if (space)
      cout << '\n';
    else
      space = true;

    cout << "Case #" << k << '\n';
    k++;
    while (q--){
        cin >> x >> y;
        if (dists[x][y] == -1)
          cout << "no path\n";
        else
          cout << dists[x][y] << endl;
    }
  }

  return 0;
}
