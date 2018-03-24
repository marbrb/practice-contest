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
  int t,v,e,x,y,w,z = 1;
  cin >> t;
  while(t--){
    cout << "Case #" << z << " : ";
    z++;
    cin >> v >> e;
    viii edges;
    for (int i=0; i<e; i++){
      cin >> x >> y >> w;
      edges.push_back(make_pair(w, ii(x, y)));
    }

    if (e < v-1){
      cout << "No way\n";
      continue;
    }

    sort(edges.begin(), edges.end());
    union_find uf(v+1);

    int added =0;
    vb edgesUsed(e, 0);
    int i=0;
    for(auto e : edges){
      if (uf.unite(e.second.first, e.second.second)){
        added++;
        edgesUsed[i] = true;
      }
      i++;
    }
    if (added < v-1){
      cout << "No way\n";
      continue;
    }
    if (e == v-1){
      cout << "No second way\n";
      continue;
    }
    vb mark(e, 0);

    int mini = 1e8;
    for (int k=0; k<e;k++){
      if (edgesUsed[k]){
        mark[k] = 1;
        union_find uf2(v+1);
        i=0;
        int mst=0;
        added =0;
        for(auto e : edges){
          if ((uf2.find(e.second.first) != uf2.find(e.second.second)) && !mark[i]){
            uf2.unite(e.second.first, e.second.second);
            mst+=e.first;
            added++;
          }
          i++;
        }

        mark[k]=0;
        if(added == v-1)
          mini = min(mini, mst);
      }
    }
    cout << mini << '\n';
  }
  return 0;
}
