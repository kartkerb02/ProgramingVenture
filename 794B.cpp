#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t > 0){
        int n;
        cin >> n;
        int A[n+1] = {};
        int count = 0, k = 1;
        for(int i = 1; i <= n; i++){
            cin >> A[i];
        }
        while(k <= n){
            if(A[k] < A[k-1]){
                count++;
                k++;
            }
            k++;
        }
        cout << count << "\n";
        t--;
    }
    return 0;
}