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

        int A[n];
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        
        int temp;
        for(int i = 0; i < n/2; i++){
            if(A[n-2*i-1] < A[n-2*i-2]){
                temp = A[n-2*i-1];
                A[n-2*i-1] = A[n-2*i-2];
                A[n-2*i-2] = temp;
            }
        }
        bool out = true;
        for(int i =0; i < n-1; i++){
            if(A[i] > A[i+1]){
                out = false;
                break;
            }
        }
        cout << (out? "YES" : "NO") << "\n";
        t--;
    }


    return 0;
}