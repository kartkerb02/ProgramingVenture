#include<bits/stdc++.h>
using namespace std;

void exe(){
    int n, m;
    cin >> n >> m;

    char grid[n][m];
    for (int i = 0;i< n; i++){
        for (int j = 0; j< m; j++){
            cin >> grid[i][j];
        }    
    }

    int ptr;
    for(int j = 0; j < m; j++){
        ptr = n - 1;
        for(int i = n- 1; i >= 0; i--){
            if (grid[i][j]== 'o'){
                ptr = i-1;
            }
            else if(grid[i][j]== '*'){
                grid[i][j] = grid[ptr][j];
                grid[ptr][j] = '*';
                ptr -= 1;
            }
        } 
    }

    for (int i = 0;i< n; i++){
        for (int j = 0; j< m; j++){
            cout << grid[i][j] << " ";
        }    
        cout << "\n";
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t > 0){
        exe();
        t--;
    }
}