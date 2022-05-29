#include<bits/stdc++.h>
using namespace std;
int exe(){
    int rem, curr, n, out;
    cin >> n;

    int high = INT_MIN;
    int low = INT_MAX;
    cin >> rem;
    for (int i = 0; i< n-1; i++){
        cin >> curr;
        if (curr == rem){
            low = min(low,i);
            high = max(high, i);
        }
        rem = curr;
    }

    if(high == INT_MIN && low == INT_MAX || high == low){
        return 0;
    }
    
    else if(high == low + 1){
        
        return 1;
    }
    
    return high - low - 1;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t > 0){
        cout << exe() << "\n";
        t--;
    }
    return 0;
}