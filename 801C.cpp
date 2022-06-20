#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// int maze[1005][1005];
// bool done[1005][1005];
// bool notdone[1005][1005];

// bool search(int x, int y, int X, int Y, int target){
//     if(done[x][y] == 1){return true;}
//     else if(notdone[x][y] == 1){return false;}
//     if(y == Y){
//         int sum = 0;
//         for(int i = x; i <= X; i++){
//             sum += maze[i][y];
//         }
//         if(sum == target){
//             done[x][y] = 1;
//         }
//         else{
//             notdone[x][y] = 1;
//         }
//         return sum == target;
//     }
//     else if(x == X){
//         int sum = 0;
//         for(int i = y; i <= Y; i++){
//             sum += maze[x][i];
//         }
//         if(sum == target){
//             done[x][y] = 1;
//         }
//         else{
//             notdone[x][y] = 1;
//         }
//         return (sum == target);
//     }
//     else{
//         bool ret = search(x+1,y,X,Y,target-maze[x][y]) || search(x,y+1,X,Y,target-maze[x][y]);
//         if(ret){
//             done[x][y] = 1;
//         }
//         else{
//             notdone[x][y] = 1;
//         }
//         return ret;
//     }
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, m;
        cin >> n >> m;
        int maze[n+1][m+1];
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j++){
                cin >> maze[i][j];
            }
        }
        if((n+m)%2 == 0){
            cout << "NO\n";
        }
        else{
            // memset(done, 0, sizeof(done));
            // memset(notdone, 0, sizeof(notdone));
            // cout << (search(1,1,n,m,0) ? "YES" : "NO") << "\n";
            int minm[n+1][m+1];
            int maxm[n+1][m+1];
            minm[1][1] = maze[1][1];
            maxm[1][1] = maze[1][1];
            for(int i = 2; i <= n; i++){
                minm[i][1] = minm[i-1][1] + maze[i][1];
                maxm[i][1] = minm[i][1];
            }
            for(int i = 2; i <= m; i++){
                minm[1][i] = minm[1][i-1] + maze[1][i];
                maxm[1][i] = minm[1][i];
            }
            for(int i = 2; i <= n; i++){
                for(int j = 2; j <= m; j++){
                    minm[i][j] = min(minm[i-1][j], minm[i][j-1]) + maze[i][j];
                    maxm[i][j] = max(maxm[i-1][j], maxm[i][j-1]) + maze[i][j];
                }
            }
            //cout << minm[n][m] << " " << maxm[n][m] << "\n";
            cout << ((minm[n][m] <= 0 && maxm[n][m] >= 0) ? "YES\n":"NO\n");
        }
        t--;
    }
    return 0;
}