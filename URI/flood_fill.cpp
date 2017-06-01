int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

//n y m solo se usan si matrix no es cuadrada.
void flood_fill(vs &matrix, int r, int c, char c1, char c2, int n, int m){
  if(r >= m || r < 0  || c >= n || c < 0)
    return;
  if (matrix[r][c] != c1) return;
  matrix[r][c] = c2;
  for (int i=0; i<8; i++)
    flood_fill(matrix, r + dr[i], c + dc[i], c1, c2, n, m);
}
