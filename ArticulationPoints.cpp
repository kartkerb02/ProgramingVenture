#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//Please make changes
int dfs(int x, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& depth, vector<int>& pr, vector<int>& high){
    vis[x] = 1;
    int mn = 1e6;
    for(int ch : adj[x]){
        if(!vis[ch]){
            pr[ch] = x;
            depth[ch] = depth[x] + 1;
            mn = min(mn, dfs(ch, adj, vis, depth, pr, high));
        }
        if(ch != pr[x]) mn = min(depth[ch], mn);
    }
    return high[x] = mn;
}

vector<int> ArticulationPoints(vector<vector<int>>& edges, int n){
    vector<vector<int>> adj(n);
    for(auto e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> vis(n, 0);
    vector<int> depth(n, 0);
    vector<int> pr(n, -1);
    vector<int> high(n, 1e6);
    vector<int> ans;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, adj, vis, depth, pr, high);
            if(adj[i].size() > 1) ans.push_back(i);
            depth[i] = 1e6;
        }
    }
    for(int i = 0; i < n; i++){
        // cout << depth[i] << " ";
        for(int v : adj[i]){
            if(v != pr[i] && high[v] >= depth[i]){
                ans.push_back(i);
                break;
            }
        }
    }
    return ans;
}

int main(){
    int n = 7;
    vector<vector<int>> edges{
        {0, 1},
        {2, 0},
        {1, 2},
        {0, 3},
        {3, 4}

        // {0, 1},
        // {1, 2},
        // {2, 3},

        // {0, 1},
        // {1, 2},
        // {2, 0},
        // {1, 3},
        // {1, 4},
        // {1, 6},
        // {3, 5}, 
        // {4, 5}
    };
    vector<int> vp = ArticulationPoints(edges, n);
    for(auto e : vp){
        cout << e << " ";
    }
    return 0;
}