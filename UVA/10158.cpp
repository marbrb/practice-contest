#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define E(x) ((x % 2) ? (x + 1) : (x - 1))

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

int main() {
  int n, x, y, c;
  cin >> n;
  union_find uf(2 * n);

  while (cin >> c) {
    cin >> x >> y;

    if (!c) return 0;

    x = (x * 2) + 1;
    y = (y * 2) + 1;

    if (c == 1){
      if ((uf.find(x) == uf.find(E(y))) || uf.find(y) == uf.find(E(x))) {
        cout << "-1\n";
      } else {
        uf.unite(x, y);
        uf.unite(E(x), E(y));
      }

    } else if (c == 2) {
      if (uf.find(x) == uf.find(y) || uf.find(E(x)) == uf.find(E(y))){
        cout << "-1\n";
      } else {
        uf.unite(x, E(y));
        uf.unite(y, E(x));
      }

    } else if (c == 3) {
      if (uf.find(x) == uf.find(y))
        cout << "1\n";
      else
        cout << "0\n";

    } else {
      if (uf.find(x) == uf.find(E(y)))
        cout << "1\n";
      else
        cout << "0\n";
    }
  }

  return 0;
}
