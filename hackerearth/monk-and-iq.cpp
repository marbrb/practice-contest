#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

typedef tuple<ll, ll, ll, ll, ll> tup;
int main() {
    tup tupi;

  priority_queue<tup, vector<tup>, greater<tup> > min_heap;
  int c, p, n;
  cin >> c >> p >> n;

  ll iq;
  //claves desde 1 (id_curso, IQs)
  for (ll i=1; i<=n; i++) {
    cin >> iq;

    min_heap.push(tup (iq, i, 1, 0, iq));
  }

  for (ll i=n+1; i<=c; i++){

    min_heap.push(tup (0, i, 0, 0, 0));
  }
  int cont=0;
  ll aux = p;
  ll f;
  while (cin >> f) {
    cont+=1;
    tup m;
    m = min_heap.top();
    cout << get<1>(m) << ' ';
    min_heap.pop();
    tup t((get<4>(m)+f) * (get<2>(m)+1), get<1>(m), get<2>(m)+1, get<4>(m), f);
    min_heap.push(t);
  }
  aux -= cont;
  while (aux != 0) {
      ll f=0;
      tup m;
      m = min_heap.top();
      cout << get<1>(m) << ' ';
      min_heap.pop();
      tup t((get<4>(m)+f) * (get<2>(m)+1), get<1>(m), get<2>(m)+1, get<4>(m), f);
      min_heap.push(t);
      aux -= 1;
  }

  return 0;
}
