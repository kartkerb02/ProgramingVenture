#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int m;
        cin >> m;
        int k = m, cnt = 0;
        while(k){
            k /= 10;
            cnt++;
        }
        int ret = m - pow(10, cnt-1);
        cout << ret << "\n";
        t--;
    }
    return 0;
}