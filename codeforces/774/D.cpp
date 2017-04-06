#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, l, r;
  cin >> n >> l >> r;
  int a[n], b[n];

  for (int i=0; i<n; i++){
    cin >> a[i];
  }
  for (int i=0; i<n; i++){
    cin >> b[i];
  }

  bool cond =true;
  for (int i=0;i <l-1; i++){
    if (a[i] != b[i]) {
      cond = false;
      break;
    }
  }
  if (cond){
    for (int i=r;i <n; i++){
      if (a[i] != b[i]) {
        cond = false;
        break;
      }
    }
  }

  if (cond){
    cout << "TRUTH" << '\n';
  } else{
    cout << "LIE" << '\n';
  }
  return 0;
}
