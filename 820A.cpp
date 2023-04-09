#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int a, b, c;
        cin >> a >> b >> c;
        int c1 = a-1;
        int c2 = abs(b-c) + abs(c-1);
        int ans = -1;
        if(c1 == c2) ans = 3;
        else if(c1 > c2) ans = 2;
        else ans = 1;
        cout << ans << "\n";
        t--;
    }
    return 0;
}