#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        string s;
        cin >> s;
        int w, q, n;
        cin >> w >> q;
        n = s.size();

        vector<vector<int>> f(10);
        for(int i = 0; i <= n-w; i++){
            int num = stoi(s.substr(i, w));
            int r = stoi(s.substr(i, w))%9;
            if(f[r].size() == 0){
                f[r].push_back(i+1);
            }
            else if(f[r].size() == 1){
                int num2 = stoi(s.substr(f[r][0] - 1, w));
                if(num2 > num) f[r].insert(f[r].begin(), i+1); 
                else f[r].push_back(i+1);
            }
            else if(f[r].size() == 2){
                int num2 = stoi(s.substr(f[r][0] - 1, w));
                int num3 = stoi(s.substr(f[r][1] - 1, w));
                if(num2 > num){
                    f[r].insert(f[r].begin(), i+1);
                    f[r].pop_back();
                }
                else if(num3 > num){
                    f[r].pop_back();
                    f[r].push_back(i+1);
                }
            }
        }
        // for(int i = 0; i < 10; i++){
        //     int bck = f[i].size();
        //     for(int j = bck-1; j > 0; j--){
        //         if(f[i][j] )
        //     }
        // }

        for(int qq = 0; qq < q; qq++){
            int l, r, k;
            cin >> l >> r >> k;
            int a = (stoi(s.substr(l-1, r-l+1)))%9;
            int x = -1, y = -1;
            for(int i = 0; i <= 9; i++){
                if(!f[i].empty()){
                    int b = (k-a*i+99)%9;
                    if(i == b && f[i].size() >= 2){
                        x = f[i][0];
                        y = f[i][1];
                        break;
                    }
                    else if(!f[b].empty()){
                        x = f[i][0];
                        y = f[b][0];
                        break;
                    }
                }
            }
            cout << x << " " << y << "\n";
        }
        t--;
    }
    return 0;
}