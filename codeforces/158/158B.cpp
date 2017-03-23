#include <bits/stdc++.h>

using namespace std;

int main() {

  int mapita[5] = {0, 0, 0, 0, 0};
  int grupos, cont, doces, unos, num;
  cont = 0;
  cin >> grupos;
  for (int i=0; i<grupos; i++) {
    cin >> num;
    mapita[num] ++;
  }

  cont += mapita[4];
  cont += (mapita[2]*2)/4;
  doces = ((mapita[2]*2) %4) != 0 ? 1 : 0;

  unos = 0;
  if (mapita[3] >= mapita[1]) {
    cont += mapita[3];
  } else {
    cont += mapita[3];
    unos = mapita[1] - mapita[3];
  }


  if (doces) {
    if (unos <= 2) {
      cont += 1;
      unos = 0;
    } else {
      cont += 1;
      unos -= 2;
    }
  }
  cont += (unos/4) + (((unos%4) != 0) ? 1 : 0);


  cout << cont << '\n';

  return 0;
}
