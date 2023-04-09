#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int j, int x, int y, map<pair<int,int>, set<pair<int,int>>>& adj, int level, set<pair<int , int>>& visited, vector<int, vector<int, vector<int>>>& dp) {
    if(i == x && y == j && level <= 4) return true;
    if(dp[i][j][level] == 0) return false;
    if(dp[i][j][level] == 1) return true;
    if(level > 4) return false;
    visited.insert({i,j});
    for(auto p : adj[{i, j}]) {
        if(!visited.count(p)) {
            if(dfs(p.first, p.second, x, y, adj, level+1, visited)){
                for(int q = 0; q <= level; q++) dp[x][i][j] = 1;
                return true;
            }
            else{
                for(int q = level; q < 5; q++){
                    dp[i][j][q] = 0;
                }
            }
        }
    }
    visited.erase({i,j});
    for(int q = level; q < 5; q++){
        dp[i][j][q] = 0;
    }
    return false;
}
string canReach(int N, int M, vector<vector<int>> grid, int x1, int y1, int x2, int y2){
    x1--; y1--; x2--; y2--;

    map<pair<int,int>, set<pair<int,int>>> adj;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int x = grid[i][j];
            for(int k = 0; k < N; k++){
                for(int l = 0; l < M; l++){
                    if(x%grid[k][l] == 0 && (k != i || l != j)){
                        adj[{i,j}].insert({k,l});
                    }
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(i>0) adj[{i,j}].insert({i-1,j});
            if(j>0) adj[{i,j}].insert({i,j-1});
            if(i < N-1) adj[{i,j}].insert({i+1, j});
            if(j < M-1) adj[{i,j}].insert({i, j+1}); 
        }
    }
    set<pair<int,int>> visited;
    
    vector<int, vector<int, vector<int>>> dp = (101, vector<int>(101, vector<int>(5, -1)));
    if(dfs(x1, y1, x2, y2, adj, 0, visited, dp)) return "YES";
    return "NO";
}

int main(){
    int N;
    cin >> N;
    int M ;
    cin >> M;
    vector<vector<int>> Grid(N, vector<int> (M));
    for(int i_Grid = 0; i_Grid < N; i_Grid++) {
        for(int j_Grid = 0; j_Grid < M; j_Grid++) {
            cin >> Grid[i_Grid][j_Grid];
        }
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        string ans;
        ans = canReach(N, M, Grid, x1, y1, x2,y2);
        cout << ans << "\n";
    }
    return 0;
}