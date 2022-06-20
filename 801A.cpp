#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, m;
        cin >> n >> m;
        int temp, mi , mj, curr_max = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> temp;
                if(temp > curr_max){
                    curr_max = temp;
                    mi = i;
                    mj = j;
                }
            }
        }
        //cout << mi << mj << "*\n";
        cout << max(mi + 1, n - mi)*max(mj + 1, m- mj) << "\n";
        t--;
    }
    return 0;
}