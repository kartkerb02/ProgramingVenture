#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n , m;
    cin >> t;

    while(t > 0){
        cin >> n >> m;
        long long int mat[n][m];
        int a = 0, b = 0;
        bool poss = true;
        vector<long long int> count[n];

        for(int i = 0; i < n && poss; i++){
            
            cin >> mat[i][0];
            for(int j = 1; j < m; j++){
                cin >> mat[i][j];
                if(mat[i][j] < mat[i][j-1]){
                    count[i].push_back(j);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(count[i].size() > 2){
                poss = false;
                break;
            }
            else if(count[i].size() == 1){
                a = count[i][0] - 1;
                b = count[i][0];
                while(a > 0 && mat[i][a] == mat[i][a-1]){
                    a--;
                }
                while(b < m-1 && mat[i][b] == mat[i][b+1]){
                    b++;
                }
                break;
            }
            else if(count[i].size() == 2){
                a = count[i][0] - 1;
                b = count[i][1];
                while(a > 0 && mat[i][a] == mat[i][a-1]){
                    a--;
                }
                while(b < n-1 && mat[i][b] == mat[i][b+1]){
                    b++;
                }
                break;
            }
        }
        //cout << a << " " << b << "#" << endl;
        if(poss){
            bool out = true;
            long long int temp;
            for(int i = 0; i < n && out; i++){
                temp = mat[i][a];
                mat[i][a] = mat[i][b];
                mat[i][b] = temp;
                for(int j = 1; j < m && out; j++){
                    if(mat[i][j] < mat[i][j-1]){
                        out = false;
                    }
                }
            }
            if(out){
                cout << a+1 << " " << b+1 << endl;
            }
            else{
                cout << -1 << endl;
            }
        }   
        else{
            cout << -1 << endl;
        }
        

       
        
        t--;
    }

    return 0;
}