#include <iostream>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin >> n;

    ll A[n+1];

    for(int i = 1; i <= n; i++){cin >> A[i];}

    ll ans = 1e18;
    for(int i = 1; i <= n; i++){
        ll moves = 0;
        ll here;
        ll rem = 0;
        for(int j = i+1; j <= n; j++){
            here = rem/A[j] + 1;
            moves += here;
            //cout << here << "@ ";
            rem = here*A[j];
        }
        rem = 0;
        for(int j = i-1; j >= 1; j--){
            
            here = rem/A[j] - 1;
            moves -= here;
            rem = here*A[j];
        }
        ans = min(moves, ans);
    }
    cout << ans << "\n";
    return 0;
}