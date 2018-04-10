#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map <int, char> mic;

int len;

mic mapi1;

void topsort(vvi &adj, int node, vi ind, vb vis, vi res){
  vis[node] = 1;
  res.push_back(node);

  for(int i=0; i< adj[node].size();i++){
    int v = adj[node][i];
    if(!vis[v])
      ind[v]--;
  }

  for(int i=0; i<len;i++){
    if (!vis[i] && (ind[i] == 0))
      topsort(adj, i, ind, vis, res);
  }


  if (res.size() == len){
    for(int i=0; i<len;i++)
      cout << mapi1[res[i]];
    cout << '\n';
    return;
  }
}


int main() {
  string s1, s2;
  bool blank = false;

  while(getline(cin, s1)){
    if (blank) cout << '\n';
    blank = true;
    len = (s1.size() + 1) / 2;
    getline(cin, s2);

    mapi1 = mic();
    map<char, int> mapi2;
    vector<char> nodes;
    for(int i=0; i<s1.size(); i+=2){
      nodes.push_back(s1[i]);
    }

    sort(nodes.begin(), nodes.end());
    for(int i=0; i<len;i++){
      mapi1[i] = nodes[i];
      mapi2[nodes[i]] = i;
    }
    vvi adj(len);
    vi ind(len);

    for(int i=0; i<s2.size()-2; i+=4){
      char c1 = s2[i], c2 = s2[i+2];
      adj[mapi2[c1]].push_back(mapi2[c2]);
      ind[mapi2[c2]]++;
    }

    vb vis(len);
    for(int i=0; i<len;i++){
      if(ind[i] == 0){
        topsort(adj, i, ind, vis, vi());
      }
    }
  }

  return 0;
}
