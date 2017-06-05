#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj(26, vi());
bitset<26> vis;
bitset<26> exist;
vi res;

void dfs(int node){
    vis.set(node);

    for (int i=0; i< adj[node].size(); i++){
        if (!vis[adj[node][i]]){
            dfs(adj[node][i]);
        }
    }
    res.push_back(node);
}


int main() {
    string s1, s2;
    cin >> s1;
    while (cin >> s2 && s2 != "#"){
        for (int i=0; i<s1.size() && i<s2.size(); i++){
            if(s1[i] != s2[i]){
                exist.set(s1[i] - 'A');
                exist.set(s2[i] - 'A');
                adj[s1[i] - 'A'].push_back(s2[i] - 'A');
                break;  //break for
            }
        }
        s1 = s2; //copy s2 into s1
    }
    
    for(int i=0; i<26; i++){
        if(!vis[i] && exist[i]){
            dfs(i);
        }
    }
    
    for(int i=res.size()-1; i>=0; i--){
        printf("%c", res[i] + 'A');
    } cout << '\n';
    
    return 0;
}