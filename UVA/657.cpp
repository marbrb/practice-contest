#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int cont;

void flood_fill(vs &matrix, int r, int c, char c1, char c2, int h, int w){
    if (r >= h || r < 0 || c >= w || c < 0) return;
    if (matrix[r][c] != c1) return;
    // aiuda
    if (matrix[r][c] == 'X' && matrix[r][c] != c1){
        flood_fill(matrix, r, c, 'X', '.', h, w);
        cont++;
        return;
    }
    matrix[r][c] = c2;
    for (int i=0; i<8; i++) {
        flood_fill(matrix, r + dr[i], c + dc[i], c1, c2, h, w);
    }
}

int num = 1;
int main() {
    int w, h;
    string s;

    while (cin >> h >> w && h && w) {
        vs matrix;
        cin.ignore();
        for (int i=0; i<h; i++){
            getline(cin, s);
            matrix.push_back(s);
        }


        for (int i=0; i<h; i++)
            cout << matrix[i] << '\n';

        vi res;
        for (int i=0; i<h ; i++) {
            for (int j=0; j<w; j++) {
                if (matrix[i][j] == '*') {
                    cont = 0;
                    flood_fill(matrix, i, j, '*', '.', h, w);
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
        cout << '\n';
    }

  return 0;
}
