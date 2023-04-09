#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n;
        cin >> n;
        int mx_x = 0, mx_y = 0, mn_x = 0, mn_y = 0;
        int x, y;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            mx_x = max(mx_x, x);
            mx_y = max(mx_y, y);
            mn_x = min(mn_x, x);
            mn_y = min(mn_y, y);
        }
        cout << 2*(0 - mn_x - mn_y + mx_x + mx_y) << "\n";
        
        t--;
    }
    return 0;
}