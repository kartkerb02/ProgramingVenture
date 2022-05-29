#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, q, temp, OUT, l, r, m;
    cin >> t;   
    while(t > 0){
        cin >> n >> q;
        int A[n+1] = {};

        OUT = 0;
        
        for(int i = 1; i <= n; i++){
            cin >> A[i];
        }
        sort(A+1, A+n+1, greater<int>());
        for(int i = 0; i < n; i++){
            A[i+1] += A[i]; 
        }
        for(int i = 0; i <= n; i++){
            cout << A[i] << " ";
        }
        cout << "#\n";
        for(int i = 0; i < q; i++){
            cin >> temp;
            if(temp > A[n]){
                OUT = -1;
            }
            else{
                l = 1;
                r = n+1;
                m = l + (r-l)/2;
                OUT = m;
                while(r>l){
                    if(A[m] == temp){
                        OUT = m;
                        break;
                    }
                    else if(A[m] < temp){
                        l = m;
                    }
                    else{
                        if(A[m-1] < temp){
                            OUT = m;
                            break;
                        }
                        else{
                            r = m;
                        }
                    }
                    m = l + (r-l)/2;
                    OUT = m;
                }
            }
            cout << OUT << "\n";
        }
        t--;
    }
    return 0;
}