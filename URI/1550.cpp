#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
int level[10001];
bool vis[10001];

void bfs(int a, int b, vi *adj) {
    vis[a] = true;
    level[a] = 0;
    queue<int> q;
    q.push(a);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i=0; i< adj[v].size(); i++) {
            if(!vis[adj[v][i]]) {
                if (adj[v][i] == b) {
                    level[b] = level[v] +1;
                    return;
                }
                level[adj[v][i]] = level[v] +1;
                vis[adj[v][i]] = true;
                q.push(adj[v][i]);
            }
        }

    }
}

int main() {
    //david se la come
    int t, a, b, s;
    cin >> t;
    vi *adj = new vi[10001];
    string aux;
    for (int i=0; i<10001; i++){

        if (i<10000) adj[i].push_back(i+1);

        aux = to_string(i);
        reverse(aux.begin(), aux.end());
        s = stoi(aux);
        if (s <= 10000) adj[i].push_back(s);
    }

    while (t--) {
        for (int i=0; i <10001; i++) level[i]=0;

        for (int j=0; j<10001; j++) vis[j]=false;

        cin >> a >> b;
        bfs(a, b, adj);
        cout << level[b] << '\n';
    }
}
