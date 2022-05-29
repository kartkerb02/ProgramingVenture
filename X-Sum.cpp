#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n , m;
    cin >> t;
    while(t > 0){
        cin >> n >> m;
        int mx = 0;
        int A[n][m];
        int ld[m+n+1] = {};
        int ru[m+n+1] = {};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> A[i][j];
                ru[i+j] += A[i][j];
                ld[i-j+m] += A[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mx= max(mx, ru[i+j] + ld[i-j+m] - A[i][j]);
            }
        }
        cout << mx << "\n";
        t--;
    }


    return 0;
}