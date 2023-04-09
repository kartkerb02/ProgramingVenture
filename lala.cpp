#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dfs(int x, vector<vector<int>>& adj, vector<bool>& vis){
    vis[x] = 1;
    int ans = 1;
    for(int u : adj[x]){
        if(!vis[u]){
            ans += dfs(u, adj, vis);
        }
    }
    return ans;
}
int count(int x, vector<vector<int>>& adj){
    int N = adj.size();
    vector<bool> vis(N, 0);
    return dfs(x, adj, vis);
}
long long solve(int N, vector<vector<long long>> edges){
    vector<long long> e = edges[0];
    int mx = 0;
    for(int i = 0; i < edges.size(); i++){
        if(edges[mx][2] < edges[i][2]) mx = i;
    }
    vector<vector<int>> adj(N + 1);
    for(int i = 0; i < edges.size(); i++){
        if(i != mx){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    }
    int ans = count(edges[mx][0], adj);
    ans += count(edges[mx][1], adj);

    edges.erase(edges.begin() + mx);
    return ans + solve(N, edges);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> s;
    s.insert(2);
    s.insert(3);
    s.insert(9);
    auto it = s.end();
    it--;
    s.erase(it);
    for(int x : s) cout << x << " ";
    return 0;
}