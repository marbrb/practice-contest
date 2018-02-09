#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct union_find {
  vi p; union_find(int n) : p(n, -1) { }
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
  bool unite(int x, int y) {
    int xp = find(x), yp = find(y);
    if (xp == yp) return false;
    if (p[xp] > p[yp]) swap(xp,yp);
    p[xp] += p[yp], p[yp] = xp;
    return true; }
int size(int x) { return -p[find(x)]; } };


int main() {
  int t;
  cin >> t;
  union_find uf(1);
  while (t--) {
    int n=0, a, b, yes=0, no=0;
    char c;
    string s;
    cin >> n; cin.ignore();

    uf = union_find(n + 1);
    while (getline(cin, s) && s != ""){
      stringstream ss(s);
      ss >> c >> a >> b;

      if (c == 'c') {
        uf.unite(a, b);
      } else {
        if (uf.find(a) == uf.find(b)){
          yes++;
        } else {
          no++;
        }
      }
    }
    cout << yes << ',' << no << '\n';
    if (t > 0) {
      cout << '\n';
    }
  }
  return 0;
}
