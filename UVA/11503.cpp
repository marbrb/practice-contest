#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;


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
    int size(int x) {
      return -p[find(x)];
    }
};

int main() {
  int t, f;
  cin >> t;
  while (t--){
    cin >> f;
    union_find uf(f+2);

    map<string, int> dict;

    string s1, s2;
    int i=1;
    while (f--){
      cin >> s1 >> s2;
      if (!dict[s1]){
        dict[s1] = i;
        i++;
      }
      if (!dict[s2]){
        dict[s2] = i;
        i++;
      }
      uf.unite(dict[s1], dict[s2]);
      cout << uf.size(dict[s1]) << '\n';
    }
  }

  return 0;
}
