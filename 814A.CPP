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
        cout << (((n&1) ^ (m&1)) ? "Burenka\n" : "Tonya\n");
        t--;
    }
    return 0;
}