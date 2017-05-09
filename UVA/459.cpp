#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

void dfs(int node, vvi &adj, vb &vis) {
    if (vis[node]) return;
    vis[node] = true;
    for(int i=0; i<adj[node].size(); i++) {
        dfs(adj[node][i], adj, vis);
    }

}
int main() {
  int cases, n, a, b;
  char maxi, x, y;
  string l;
  cin >> cases;
   while (cases--) {
     cin >> maxi;
     n = (int)maxi - 65;
     vvi adj(n+1);
     vb vis(n+1,false);
     getline(cin , l);
     while (true) {
       getline(cin, l);
       if (l=="") break;

       a = (int)l[0] -65;
       b = (int)l[1] -65;
       adj[a].push_back(b);
       adj[b].push_back(a);
     }
     int cont=0;
     for (int i=0; i<n+1; i++) {
       if (!vis[i]) {
         cont++;
         dfs(i, adj, vis);
       }
     }
     cout << cont << endl;
     if (cases)
      cout << endl;
   }

  return 0;
}
