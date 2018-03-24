#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, ii> lii;
typedef vector<lii> vlii;
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


double dist(int x1, int y1, int x2, int y2){
  return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}


int main() {
  int cases, n,m, x, y, w;
  cin >> cases;
  bool blank=false;
  while (cases--){
    cin >> n;
    vii towns(n+1);
    for (int i=1;i<=n;i++){
      cin >> x >> y;
      towns[i] = ii(x, y);
    }
    vlii edges;
    for (int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        edges.push_back(make_pair(dist(towns[i].first, towns[i].second, towns[j].first, towns[j].second), ii(i, j)));
      }
    }

    union_find uf(n+1);
    cin >> m;
    while (m--){
      cin >> x >> y;
      uf.unite(x, y);
    }
    if(blank){
      cout << '\n';
    }
    blank=true;
    sort(edges.begin(), edges.end());
    int cont = 0;
    for (auto e: edges){
      if (uf.unite(e.second.first, e.second.second)){
        cout << e.second.first << ' ' <<  e.second.second << '\n';
        cont++;
      }
    }
    if (!cont)
      cout << "No new highways need\n";

  }

  return 0;
}
