#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair <int, int> ii;
typedef pair <double, ii> lii;
typedef vector<lii> vlii;
typedef vector<ii> vii;

double dist(int x1, int y1, int x2, int y2){
  return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

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
  int cases;
  cin >> cases;
  int s, x, y;
  while (cases--){
    cin >> s;
    vii pts;
    int n=0;
    while (cin >> x && x != -1){
      cin >> y;
      pts.push_back(ii(x, y));
      n++;
    }

    vlii edges;
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
        edges.push_back(make_pair(dist(pts[i].first, pts[i].second, pts[j].first, pts[j].second), ii(i, j)));
      }
    }

    sort(edges.begin(), edges.end());
    union_find uf(n);
    int cont = 0;
    int res;
    for (auto e : edges){
      if (uf.unite(e.second.first, e.second.second)){
        cont++;
      }
      if (cont == n-s){
        res = ceil(e.first);
        break;
      }
    }

    printf("%d\n", res);
  }
  return 0;
}
