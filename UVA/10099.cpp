#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;

struct union_find {
  vi p;
  union_find(int n) : p(n, -1) {}

  int find(int x) {
      return p[x] < 0 ? x : p[x] = find(p[x]);
  }

  bool unite(int x, int y){

    int xp = find(x), yp = find(y);
    if(xp == yp) return false;
    if(p[xp] > p[yp]) swap(xp, yp);
    p[xp] += p[yp];
    p[yp] = xp;
    return true;
  }
};


int sol;
void dfs(vvii &adj, int fr, int to, int res, vb &vis){
  vis[fr] = 1;
  for (int i=0; i<adj[fr].size(); i++){
    if (adj[fr][i].first == to){
      sol = min(res, adj[fr][i].second);
      return;
    }
    if(!vis[adj[fr][i].first]){
      dfs(adj, adj[fr][i].first, to, min(res, adj[fr][i].second), vis);
    }
  }
}


int main() {
  int n,r, x, y, w, z=1;
  while (cin >> n >> r && (n && r)){
    vvii adj(n+1);
    viii edges;
    while (r--){
      cin >> x >> y >> w;
      edges.push_back(make_pair(w, ii(x, y)));
    }

    sort(edges.rbegin(), edges.rend());
    union_find uf(n+1);
    for (auto e : edges){
      if (uf.unite(e.second.first, e.second.second)){
        adj[e.second.first].push_back(ii(e.second.second, e.first));
        adj[e.second.second].push_back(ii(e.second.first, e.first));
      }
    }

    int fr, to, tourists;
    cin >> fr >> to >> tourists;
    vb vis(n+1);
    dfs(adj, fr, to, 10000000, vis);
    sol--;
    cout << "Scenario #" << z << '\n';
    z++;
    cout << "Minimum Number of Trips = "<< ceil(tourists / (float) sol) << endl;
    cout << endl;
  }
  return 0;
}
