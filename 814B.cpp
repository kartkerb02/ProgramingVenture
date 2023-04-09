#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, k;
        cin >> n >> k;
        if(k%4 == 0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            if(k%4 == 1 || k%4 == 3){
                for(int i = 1; i <= n/2; i++){
                    cout << 2*i - 1 << " " << 2*i << "\n";
                }
            }
            else{
                for(int i = 0; i < n/4; i++){
                    cout << 4*i + 2 << " " << 4*i + 1 << "\n" << 4*i + 3 << " " << 4*i + 4 << "\n";
                }
                if(n%4 == 2){
                    cout << n << " " << n-1 << "\n";
                }
            }
        }
        t--;
    }
    return 0;
}