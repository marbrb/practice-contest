#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vi res;

void bfs(vvi &adj, vi &ind){
  priority_queue<int, vi, greater<int> > q;
  for(int i=1;i<ind.size(); i++){
    if(ind[i] == 0)
      q.push(i);
  }

  while(!q.empty()){
    int v = q.top(); q.pop();
    res.push_back(v);
    for(int i=0;i< adj[v].size();i++){
      if(--ind[adj[v][i]] == 0){
        q.push(adj[v][i]);
      }
    }
  }
}

int main(){
  int n, m, z=1;
  string s1, s2;
  map<string, int> mapi;

  while (cin >> n){
    cout << "Case #" << z << ": Dilbert should drink beverages in this order:";
    z++;
    res = vi();
    vvi adj(n+1);
    vi ind(n+1);
    vector<string> rev(n+1);
    for (int i=1;i<=n; i++){
      cin >> s1;
      mapi[s1] = i;
      rev[i] = s1;
    }

    cin >> m;
    for(int i=0;i<m;i++){
      cin >> s1 >> s2;
      adj[mapi[s1]].push_back(mapi[s2]);
      ind[mapi[s2]]++;
    }
    bfs(adj, ind);

    for (int e : res){
      cout << ' ' << rev[e];
    }cout << ".\n\n";

  }

  return 0;
}
