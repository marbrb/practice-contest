#include<bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

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

int main(){
  int c,n ,m, x,y,w;
  cin >>c;

  while(c--) {
    cin >> n>>m;
    viii edges;
    union_find uf(n+1);
    while(m--){
      cin >>x >> y >> w;
      edges.push_back(make_pair(w, ii(x,y)));
    }
    int res =0;
    sort(edges.rbegin(), edges.rend());
    for (auto e: edges){
      if (!uf.unite(e.second.first, e.second.second))
        res += e.first;
    }
    cout << res << '\n';
  }
  int cero; cin >> cero;

  return 0;
}
