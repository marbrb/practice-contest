#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};


void dfs(vs &graph, int r, int c, char c1, char c2) {
  if (r < 0 || r >= graph.size() || c < 0 || c >= graph.size())
    return;
  if (graph[r][c] != c1) return;
  graph[r][c] = c2;
  for (int i=0; i<8; i++)
    dfs(graph, r + dr[i], c + dc[i], c1, c2);
}
int img = 1;
int main() {
  int n;
  string s;
  while (cin >> n) {
    cin.ignore();
    vs graph;
    for(int i=0; i<n; i++){
      getline(cin, s);
      graph.push_back(s);
    }
    int cont=0;
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
        if (graph[i][j] == '1'){
          dfs(graph, i, j, '1', '.');
          cont++;
        }
      }
    }
    cout << "Image number " << img << " contains " << cont << " war eagles.\n";
    img++;
  }

  return 0;
}
