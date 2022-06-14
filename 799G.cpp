#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n , k, temp;
        cin >> n >> k;
        ll A[n];
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        //sort(A, A+n);
        bool out[n] = {0};
        for(int i = 1; i < n; i++){
            out[i] = A[i]*2 > A[i-1];
        }
        int count = 0, curr_cnt = 0;
        for(int i = 1; i < n; i++){
            if(out[i]){
                curr_cnt++;
            }
            else{
                if(curr_cnt >= k){
                    count += curr_cnt - k + 1;
                }
                curr_cnt = 0;
            }
        }
        if(curr_cnt >= k){
            count += curr_cnt - k + 1;
        }
        cout << count << "\n";
        t--;
    }
    return 0;
}