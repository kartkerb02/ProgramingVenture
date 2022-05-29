#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t > 0){
        int n, sum = 0;
        cin >> n;
        int w[n+1] = {}, left[n+1] = {};
        for(int i = 1; i <= n; i++){
            cin >> w[i];
            left[i] = left[i-1] + w[i];
            sum += w[i];
        }
        
        int p1 = 1, p2 = n;
        int mx = 0;
        while(p2 > p1){
            if(left[p1] == sum - left[p2-1]){
                mx = p1 + n - p2 + 1;
                p1++;
                p2--;
            }
            else if(left[p1] < sum - left[p2-1]){
                p1++;
            }
            else{
                p2--;
            }
        }
        cout << mx << "\n";
        t--;
    }
    return 0;
}