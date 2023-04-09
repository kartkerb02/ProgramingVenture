#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

static int mn;

int dfs(int x, vector<int>& pr, vector<bool>& vis, vector<vector<int>>& graph, vector<int>& depth,vector<int>& high){
    vis[x] = 1;
    int mn = 1e6;
    for(int ch : graph[x]){
        if(!vis[ch]){
            depth[ch] = 1 + depth[x];
            pr[ch] = x;
            mn = min(mn, dfs(ch, pr, vis, graph, depth, high));
        }
        if(ch != pr[x]) mn = min(mn, depth[ch]);
    }
    return high[x] = mn;
}
vector<pair<int, int>> bridges(vector<vector<int>>& graph, int n){
    vector<int> pr(n, -1);
    vector<bool> vis(n, 0);
    vector<int> depth(n, 1e6);
    vector<int> high(n, -1);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            depth[i] = 0;
            dfs(i, pr, vis, graph, depth, high);
            high[i] = -1;
        }
    }

    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++){
        // cout << high[i] << " ";
        if(high[i] >= depth[i]) ans.push_back({pr[i], i});
    }
    return ans;

}

int main(){
    int n = 4;
    vector<vector<int>> graph{
        {0, 1},
        {2, 1},
        {0, 3}
    };
    vector<vector<int>> adj(n);
    for(auto e : graph){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<pair<int, int>> vp = bridges(adj, n);
    for(auto e : vp){
        cout << e.first << " <-> " << e.second << "\n";
    }
    cout << mn << "yes";
    return 0;
}