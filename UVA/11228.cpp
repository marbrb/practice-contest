#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;


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

    int size(){
      int cont =0;
      for (int e:p){
        if (e<0)cont++;
      }
      return cont;
    }
};

int main(){
  int t, n, r, x, y;
  cin >> t;

  for (int z=1;z<=t;z++){
    cin >> n>>r;
    union_find sameState(n);
    union_find uf(n);
    vector<ii> points(n);
    for (int i=0;i<n;i++){
      cin >> x >> y;
      points[i] = ii(x,y);
    }

    vector<pair<float, ii>> edgeList;

    for (int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        float dist = sqrt(pow((points[j].first - points[i].first),2) + pow((points[j].second - points[i].second), 2));
        if (dist <= r)
          sameState.unite(i, j);
        edgeList.push_back(make_pair(dist, ii(i,j)));
      }
    }

    sort(edgeList.begin(), edgeList.end());

    float roads=0, railroads=0;
    for (auto e : edgeList){
      if (uf.unite(e.second.first, e.second.second)){
        if(sameState.find(e.second.first) ==  sameState.find(e.second.second)){
          roads += e.first;
        } else {
          railroads += e.first;
        }
      }
    }
    cout << "Case #" << z << ": " << sameState.size() << ' ' << round(roads) << " " << round(railroads) << '\n';
  }

  return 0;
}
