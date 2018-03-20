#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector <pair<int, ii>> viii;

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
  int n,m, x, y, w;

  while (cin >> n >> m && (n && m)){
      viii edgeList;
      vi res;
      union_find uf(n);
      while (m--){
        cin >> x >> y >> w;
        edgeList.push_back(make_pair(w, ii(x,y)));
      }

      sort(edgeList.begin(), edgeList.end());
      for (auto e : edgeList){
        if (!uf.unite(e.second.first, e.second.second)){
          res.push_back(e.first);
        }
      }
      if (!res.size()){
        cout << "forest\n";
      } else {
        sort(res.begin(), res.end());
        bool c = false;
        for (int e : res){
          if (c) cout << ' ';
          cout << e;
          c = true;
        }cout << '\n';
      }
  }

  return 0;
}
