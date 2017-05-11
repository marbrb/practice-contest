#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

int cont;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void flood_fill(vs &matrix, int r, int c, char c1, char c2, int n, int m){
  if(r >= n || r < 0  || c >= m || c < 0) return;
  if (matrix[r][c] != c1) return;
  matrix[r][c] = c2;
  cont++;
  for (int i=0; i<4; i++)
    flood_fill(matrix, r + dr[i], c + dc[i], c1, c2, n, m);
}

int main() {
  int t, r, c;
  string s;

  cin >> t;
  while (t--) {
    vs matrix;
    cin >> r  >> c;
    cin.ignore();
    while (getline(cin, s)) {
      if (s == "") break;
      matrix.push_back(s);
    }

    cont = 0;
    flood_fill(matrix, r-1, c-1, '0', '1', matrix.size(), matrix[0].size());

    cout << cont << '\n';
    if (t) cout << '\n';

  }

  return 0;
}
