#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void flood_fill(vs &matrix, int r, int c, char c1, char c2, int h, int w, vs &copy){
    if (r >= h || r < 0 || c >= w || c < 0) return;
    if (matrix[r][c] == '.') return;

    if (matrix[r][c] == 'X') copy[r][c] = 'X';
    matrix[r][c] = c2;
    for (int i=0; i<4; i++) {
        flood_fill(matrix, r + dr[i], c + dc[i], c1, c2, h, w, copy);
    }
}
void flood2(vs &matrix, int r, int c, char c1, char c2, int h, int w){
    if (r >= h || r < 0 || c >= w || c < 0) return;
    if (matrix[r][c] != c1) return;
    matrix[r][c] = c2;
    for (int i=0; i<4; i++) {
        flood2(matrix, r + dr[i], c + dc[i], c1, c2, h, w);
    }
}

int num = 1;
int main() {
    int w, h;
    string s;

    while (cin >> w >> h && h && w) {
        vs matrix;
        cin.ignore();

        for (int i=0; i<h; i++){
            getline(cin, s);
            matrix.push_back(s);
        }

        vi res;
        for (int i=0; i<h ; i++) {
            for (int j=0; j<w; j++) {
                if (matrix[i][j] == 'X') {
                    vs copy(h, string(w, '.'));
                    flood_fill(matrix, i, j, 'X', '.', h, w, copy);

                    int cont = 0;
                    for (int k=0; k<h; k++) {
                      for (int y=0; y<w; y++) {
                        if (copy[k][y] == 'X') {
                          flood2(copy, k, y, 'X', '.', h, w);
                          cont++;
                        }
                      }
                    }
                    res.push_back(cont);
                }
            }
        }

        cout << "Throw " << num << '\n';
        num += 1;
        sort(res.begin(), res.end());
        cout << res[0];
        for (int i=1; i<res.size(); i++)
            cout << " " << res[i];
        cout << "\n\n";
    }

  return 0;
}
