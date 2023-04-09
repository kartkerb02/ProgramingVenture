#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> DFS(int s, vector<int>& dist, vector<vector<int>>& adj){
    if(adj[s].empty()) return {0};
    vector<int> out;
    for(int x : adj[s]){
        vector<int> tmp = DFS(x);
        for(int y : tmp) out.push_back(y+1);
    }
    return out;
}

int BFS(int s, vector<int>& dist, vector<vector<int>>& adj){
    queue<int> q;
    vector<bool> vis(dist.size(), 0);
    if(adj[s].empty()) return 0;
    q.push(s);
    vis[s]=1;
    int k = 1;
    while(!q.empty()){
        int nn = q.size();
        for(int i = 0; i < nn; i++){
            int tp = q.front();
            q.pop();
            for(int x : adj[tp]){
                if(adj[x].empty()) return k;
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        k++;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, m, x, y;
        cin >> n >> m;
        vector<int> val(n);
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) cin >> val[i];
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            adj[--x].push_back(--y);
        }
        vector<vector<int>> dist(n);
        for(int i = 0; i < n; i++){
            dist[i] = DFS(i, dist, adj);
        }
        vector<int> ind(n);
        
        for(int i = 0; i < n; i++) ind[i] = i;
        sort(ind.begin(), ind.end(), [&dist](int x, int y){return dist[x] < dist[y];});
        int wait = dist[ind[0]], sum = val[ind[0]] + dist[ind[0]];
        for(int i = 0; i < n-1; i++){
            if(dist[i+1] > sum) wait += dist[i+1] - sum;
            sum += val[i+1];
        }
        int time = sum + wait - dist[ind[0]];
        cout << time << "\n";
        t--;
    }
    return 0;
}