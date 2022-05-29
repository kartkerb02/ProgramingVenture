#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t > 0){
        int n, sum = 0, avg;
        bool out = true;
        cin >> n;
        int A[n+1] = {-1};
        for(int i = 1; i <= n; i++){
            cin >> A[i];
        }
        if(n%2 != 0){
            out = false;
        }
        else{
            sort(A+1, A+n+1);
            int mx = 1, mxnum = -1, curr = 1;
            for(int i = 1; i <= n; i++){
                if(A[i] == A[i-1]){
                    curr++;
                    if(curr > mx){
                        mx = curr;
                        mxnum = A[i];
                    }
                }
                else{
                    curr = 1;
                }
            }
            
            if(mx > n/2 || (mx == n/2 && (mxnum != A[1] && mxnum != A[n]))){
                out = false;
            }
        }
        if(out){
            cout << "yes" << "\n";
            for(int i = 1; i <= n/2; i++){
                cout << A[i] << " " << A[i + n/2] << " ";
            }
            cout << "\n";
        }
        else{
            cout << "no" << "\n";
        }
        
        t--;
    }
}