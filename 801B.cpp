#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;   
    while(t){
        ll n;
        cin >> n;
        ll A[n];
        for(ll i = 0; i < n; i++){cin >> A[i];}
        if(n%2 == 1){
            cout << "Mike\n";
        }
        else{
            int minm = INT_MAX, minj = INT_MAX, indm = 0, indj = 0;
            for(int i = 0; i < n; i+=2){
                if(A[i] < minm){
                    minm = A[i];
                    indm = i;
                }
            }
            for(int i = 1; i < n; i+=2){
                if(A[i] < minj){
                    minj = A[i];
                    indj = i;
                }
            }
            //cout << minm << minj << " " << indm << indj << "\n";
            if(minm < minj || (minm == minj && indm < indj)){
                cout << "Joe\n";
            }
            else{
                cout << "Mike\n";
            }
        }
        t--;
    }
    return 0;
}