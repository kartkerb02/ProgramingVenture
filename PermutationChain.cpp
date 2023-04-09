#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n){
    vector<int> v(n);
    for(int i = 1; i <= n; i++) v[i-1] = i; 
    cout << n << "\n";
    for(int i = 0; i < n; i++) cout << v[i] << " ";
    cout << "\n";
    for(int i = n-1; i > 0; i--){

        int tmp = v[i];
        v[i] = v[i-1];
        v[i-1] = tmp;

        for(int j = 0; j < n; j++) cout << v[j] << " ";
        cout << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n;
        cin >> n;
        solve(n);
        t--;
    }
    return 0;
}