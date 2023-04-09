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
        if(n&1){
            cout << 1 << " ";
            for(int i = 1; i <= n/2; i++){
                cout << (2*i + 1) << " " << 2*i << " ";
            }
        }
        else{
            for(int i = 1; i <= n/2; i++){
                cout << 2*i << " " << 2*i - 1 << " ";
            }
        }
        cout << "\n";
        t--;
    }
    return 0;
}