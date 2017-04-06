#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, c1, c2, parent, pupil;
  cin >> n >> c1 >> c2;
  char aux;
  while (cin >> aux) {
    if (aux == '1') {
      parent++;
    }else {
      pupil++;
    }
  }

  int su = pupil + parent;
  if (pupil <= parent) {
    int r = (c1 + c2)*(su/2);
    if (su%2 ==0) {
      cout << r << '\n';
    } else {
      cout << r + c1 << '\n';
    }


  } else {
    int kids = pupil/parent;
    int res;
    if (pupil%2 != 0){
      res = (c1 + (c2 * (kids-1)))*(parent -1);
      res += c1 + (c2 * kids);
      cout << res << '\n';
    } else {

    }
  }

  return 0;
}
