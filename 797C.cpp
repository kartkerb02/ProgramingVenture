#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n;
        cin >> n;
        int S[n+1] = {};
        int F[n+1] = {};
        for(int i = 1; i <= n; i++){
            cin >> S[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> F[i];
        }
        for(int i = 1; i <= n; i++){
            cout << F[i] - max(F[i-1], S[i]) << " ";
        }
        cout << "\n";
        t--;
    }
    return 0;
}