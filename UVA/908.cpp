#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef vector <int> vi;

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

int main (){
  int n, u, v, w, k, m;
  bool f = true;
  while(cin >> n){
    if (!f) cout << endl;
    else f=false;
    
    vector<pair<int, ii>> eList;
    union_find uf(n+1);

    int cost=0;
    for (int i=0;i< n-1;i++){
      cin >> u>>v>>w;
      cost += w;
    }

    cin >> k;
    while (k--){
      cin >>u>>v>>w;
      eList.push_back(make_pair(w, ii(u, v)));
    }

    cin >> m;
    while (m--){
      cin >>u>>v>>w;
      eList.push_back(make_pair(w, ii(u, v)));
    }

    sort(eList.begin(), eList.end());
    int mstCost=0;
    for (auto e : eList){
      if (uf.unite(e.second.first, e.second.second)){
        mstCost += e.first;
      }
    }
    cout << cost << '\n';
    cout << mstCost << '\n';
  }

  return 0;
}
