#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(string& a, string& b, int n, int m){
    if(a.substr(n-m+1,m-1) != b.substr(1, m-1)) return 0;
    for(int i = 0; i < n-m+1; i++){
        if(a[i] == b[0]) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n , m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;

        if(solve(a, b, n, m)) cout << "YES\n";
        else cout << "NO\n";

        t--;
    }
    return 0;
}