#include <bits/stdc++.h>
using namespace std;

typedef map<string, int> msi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<bool> vb;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef vector <iii> viii;


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

int dist (int x1, int y1, int x2, int y2){
  return pow(x2-x1, 2) + pow(y2-y1,2);
}

int main(){
  int s, n, t, x, y;
  cin >> t;
  while (t--){
    cin >> s >> n;
    viii edgeList;
    vii pts;
    for (int i=0;i<n;i++){
      cin >> x >> y;
      pts.push_back(ii(x,y));
    }
    for (int i=0;i<n;i++){
      for (int j=i+1;j<n;j++){
        edgeList.push_back(make_pair(dist(pts[i].first, pts[i].second, pts[j].first, pts[j].second), ii(i, j)));
      }
    }

    int cont = n-s;
    double last_dist=0;;
    sort(edgeList.begin(), edgeList.end());
    union_find uf(n);
    for (auto e : edgeList){
      if (cont == 0 && s > 1){
        printf("%.2lf\n", sqrt(last_dist));
        break;
      }
      if (uf.unite(e.second.first, e.second.second)){
        cont--;
        last_dist = e.first;
      }
    }
    if (s <= 1)
      printf("%.2lf\n", sqrt(last_dist));
  }


  return 0;
}
