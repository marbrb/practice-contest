#include <bits/stdc++.h>
using namespace std;

#define MAX 2e9

bool intersetc(int *s, int *v, int n, double t) {
    double L = MAX, R = -MAX;
    for(int i=0; i<n; i++) {
        L = min(L, s[i] + (t * v[i]));
        R = max(R, s[i] - (t * v[i]));
    }

    return L <= R;
}

double bns(int *s, int *t, int n) {
  double lo = 0, hi = MAX, m;
  int i = 0;

  while(++i < 200) {
    m = (lo + hi) / 2.0;

    if(intersetc(s, t, n, m)) lo = m;
    else hi = m;

  }

  return m;
}

int main() {
  int n, *s, *t;

  cin >> n;
  s = new int[n];
  t = new int[n];

  for(int i=0; i<n; i++) cin >> s[i];
  for(int i=0; i<n; i++) cin >> t[i];

  printf("%.10f\n", bns(s, t, n));

  return 0;
}
