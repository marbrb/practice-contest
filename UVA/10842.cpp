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


int main() {
  int t, n, m, x, y, w, z=1;
  cin >> t;
  while (t--){
    cin >> n >> m;
    viii edges;
    while (m--){
      cin >> x >> y >> w;
      edges.push_back(make_pair(w, ii(x, y)));
    }

    sort(edges.rbegin(), edges.rend());
    union_find uf(n);
    int mini=1e8;

    for (auto e : edges){
      if (uf.unite(e.second.first, e.second.second))
        mini = min(mini, e.first);
    }
    cout << "Case #" << z << ": "<< mini << '\n';
    z++;
  }
  return 0;
}
