#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef vector <double> vd;
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef vector <id> vid;
typedef vector<bool> vb;
typedef vector <ii> vii;
typedef vector <vid> vvid;
typedef long long ll;
typedef vector <pair<double, ii>> vdii;

double res=0;

void dfs(vvid &adj, int fr, int to, vd path, vb &vis){
  vis[fr] = 1;
  if (fr == to){
    for (double e : path)
      res = max(res, e);
    return;
  }
  for (int i=0;i<adj[fr].size();i++){
    if (!vis[adj[fr][i].first]){
      path.push_back(adj[fr][i].second);
      dfs(adj, adj[fr][i].first, to, path, vis);
    }
  }
  return;
}

double dist(int x1, int y1, int x2, int y2){
  return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
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
  int n, x, y;
  ii fr, to;
  int z = 1;
  while (cin >> n && n) {
    vector<ii> pts(n);
    vdii edgeList;
    for (int i=0; i<n;i++){
      cin >> x >> y;
      pts[i] = ii(x, y);
    }

    for (int i=0; i<n;i++){
      for (int j=i+1;j<n;j++){
        edgeList.push_back(make_pair(dist(pts[i].first, pts[i].second, pts[j].first, pts[j].second),ii(i, j)));
      }
    }
    vvid adj(n+1);
    sort(edgeList.begin(), edgeList.end());
    union_find uf(n);
    for (auto e : edgeList){
      if (uf.unite(e.second.first, e.second.second)){
        adj[e.second.first].push_back(id(e.second.second, e.first));
        adj[e.second.second].push_back(id(e.second.first, e.first));
      }
    }
    vb vis(adj.size(), 0);
    vd path;

    // for (int i=0;i<n;i++){
    //   cout << i << " : " << endl;
    //   for (auto h :adj[i]){
    //     cout << h.first << ' ' << h.second << '\n';
    //   }
    // }


    dfs(adj, 0, 1, path, vis);
    cout << "Scenario #" << z << endl;
    printf("Frog Distance = %.3f\n", res);
    cout << endl;
    res =0;
    z++;
  }

  return 0;
}
