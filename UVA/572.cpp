#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};


void flood_fill(vs &matrix, int r, int c, char c1, char c2, int n, int m){
  if(r >= m || r < 0  || c >= n || c < 0)
    return;
  if (matrix[r][c] != c1) return;
  matrix[r][c] = c2;
  for (int i=0; i<8; i++)
    flood_fill(matrix, r + dr[i], c + dc[i], c1, c2, n, m);
}

int main() {
  int m, n;
  string s;
  while (cin >> m >> n && m) {
    vs matrix;
    cin.ignore();
    for (int i=0; i<m; i++) {
      getline(cin, s);
      matrix.push_back(s);
    }
    int cont = 0;
    for (int i=0; i<m; i++) {
      for (int j=0; j<n; j++) {
        if (matrix[i][j] == '@'){
          flood_fill(matrix, i, j, '@', '.', n, m);
          cont++;
        }
      }
    }
    cout << cont << '\n';
  }

  return 0;
}
