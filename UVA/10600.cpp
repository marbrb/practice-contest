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
  int t, n, m, x, y, w;
  cin >> t;
  while (t--){
    cin >> n >> m;
    viii edges;
    for (int i=0; i<m; i++){
      cin >> x >> y >> w;
      edges.push_back(make_pair(w, ii(x, y)));
    }

    sort(edges.begin(), edges.end());
    union_find uf(n+1);
    vb used(m, 0);
    int mst1=0;
    int k=0;
    for (auto e : edges){
      if (uf.unite(e.second.first, e.second.second)){
        mst1 += e.first;
        used[k] = 1;
      }
      k++;
    }

    vb mark(m, 0);
    int mst, added, mst2=1e8, index;
    for (int i=0;i<m;i++){
      if (used[i]){
        mark[i]=1;
        union_find uf2(n+1);
        index=0;
        mst=0;
        added=0;
        for (auto e : edges){
          if ((uf2.find(e.second.first) != uf2.find(e.second.second)) && !mark[index]){
            mst+=e.first;
            uf2.unite(e.second.first, e.second.second);
            added++;
          }
          index++;
        }
        if (added == n-1){
          mst2 = min(mst2, mst);
        }

        mark[i]=0;
      }
    }

    cout << mst1 << ' ' << mst2 << '\n';
  }

  return 0;
}
