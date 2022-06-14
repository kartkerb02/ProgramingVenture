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
        int A[n] = {};
        for(int i = 0; i < n; i++){cin >> A[i];}

        sort(A, A+n);
        int rep = 0;
        for(int i = 1; i < n; i++){
            if(A[i] == A[i-1]){
                rep++;
            }
        }
        if(rep%2 == 1){
            rep++;
        }
        cout << n - rep << "\n";
        t--;
    }
    return 0;
}