#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;

int drow[] = {-1, -1, 0, 0, 1, 1};
int dcol[] = {-1, 0, -1, 1, 0, 1};

void dfs(vs &graph, int row, int col, char c1, char c2) {
  if (row >= graph.size() || row < 0 || col < 0 || col >= graph.size())
    return;
  if (graph[row][col] != c1) return;

  graph[row][col] = c2;
  for (int i=0; i<6; i++)
    dfs(graph, row + drow[i], col + dcol[i], c1, c2);

}
int game = 1;
int main() {
  int n;
  char c;
  string s;

  while (cin >> n && n){
    getline(cin, s);
    vs graph;
    for (int i=0; i<n; i++) {
      getline(cin, s);
      graph.push_back(s);
    }

    for (int i=0; i<n; i++){
      //verify only the black player
      if(graph[0][i] == 'b')
        dfs(graph, 0, i, 'b', '.');
    }

    bool cond = false;
    for (int i=0; i<n; i++) {
      if(graph[n-1][i] == '.'){
        cond=true;
        break;
      }
    }

    if (cond)
      cout << game << " " << "B\n";
    else
      cout << game << " " << "W\n";
    game +=1;
  }

  return 0;
}
