#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, k, ins, cont;
  ins = -1;
  cont = 0;
  string s;

  cin >> n >> k;
  cin >> s;

  for (int i=0; i<n; i++) {
    if (s[i] != 'Y') {
      cont += 1;
      ins = max(ins, cont);
    } else {
      cont = 0;
    }
  }

  if (ins == k) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }


  return 0;
}
