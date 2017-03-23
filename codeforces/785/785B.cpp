#include <bits/stdc++.h>

using namespace std;

int main () {

  int case1, case2,aux1,aux2;
  int menorSegundaFila1,menorSegundaFila2,mayorPrimeraFila1,mayorPrimeraFila2;
  cin >> case1;

  menorSegundaFila1 = 1e9 +10;
  mayorPrimeraFila1 =-1;
  menorSegundaFila2 = 1e9 +10;
  mayorPrimeraFila2 =-1;

  for (int i = 0; i < case1; i++) {
    cin >> aux1 >> aux2;
    menorSegundaFila1 = min(menorSegundaFila1, aux2);
    mayorPrimeraFila1 = max(mayorPrimeraFila1, aux1);
  }

    cin >> case2;
    for (int i = 0; i < case2; i++) {
      cin >> aux1 >> aux2;
      menorSegundaFila2 = min(menorSegundaFila2, aux2);
      mayorPrimeraFila2 = max(mayorPrimeraFila2, aux1);
    }

  int res1,res2;
  res1=mayorPrimeraFila1- menorSegundaFila2;
  res2=mayorPrimeraFila2- menorSegundaFila1;

  if (res1 < 0 && res2 <0){
    cout <<"0"<<'\n';
    return 0;
  }

  if (res1 > res2) {
    cout << res1 <<'\n';
  } else {
    cout << res2 <<'\n';
  }

  return 0;
}
