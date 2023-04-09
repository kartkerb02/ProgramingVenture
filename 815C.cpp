#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    vector<int> dx1 = {0, 0, 1, 1, 0, 0, -1, -1, 1, 1, -1, -1};
    vector<int> dy1 = {1, 1, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0};
    vector<int> dx2 = {1, -1, 1, 1, 1, -1, -1, -1, 0, 0, 0, 0};
    vector<int> dy2 = {1, 1, 1, -1, -1, -1, 1, -1, 1, -1, 1, -1};
    while(t){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            for(int j = 0; j < m; j++) mat[i][j] = s[j] - '0';
        }
        int mn = 5, cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j]){
                    cnt++;
                    for(int k = 0; k < 12; k++){
                        int x1 = i + dx1[k];
                        int y1 = j + dy1[k];
                        int x2 = i + dx2[k];
                        int y2 = j + dy2[k];
                        if(x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0 && x1 < n && x2 < n && y1 < m && y2 < m){
                            // cout << x1 << " " << y1 << "\n";
                            mn = min(1 + mat[x1][y1] + mat[x2][y2], mn);
                        } 
                    }
                }
            }
        }
        int ans = 0;
        if(cnt == 0) ans = 0;
        else ans = cnt - mn + 1;
        cout << ans << "\n";
        t--;
    }
    return 0;
}