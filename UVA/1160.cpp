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
};

int main() {
    int a, b, res=0;
    bool c;
    union_find uf(100001);

    while (cin >> a){
        if (a == -1) {
            cout << res << '\n';
            uf = union_find(100001);
            res = 0;
            continue;
        }
        cin >> b;
        if (!uf.unite(a, b)) {
            res++;
        }
    }
    return 0;
}
