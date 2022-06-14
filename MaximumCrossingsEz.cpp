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

        int B[n+1] = {};
        for(int i = 1; i <=n ;i++){
            cin >> B[i];
        }

        int num = 0;
        for(int i = 1; i < n; i++){
            for(int j = i+1 ; j <= n; j++){
                if(B[j] < B[i]){
                    num++;
                }
            }
        }
        sort(B+1, B+n+1);
        // for(auto x : B){cout << x << "$";}
        // cout << "\n";
        vector<int> grp;
        int sz = 1;
        for(int i = 1; i<= n; i++){
            if(B[i] == B[i-1]){
                sz++;
            }
            else{
                if(sz != 1){
                    grp.push_back((sz*(sz-1))/2);
                    sz = 1;
                }
            }
        }
        if(sz != 0){
            grp.push_back((sz*(sz-1))/2);
            sz = 0;
        }
        for(int i = 0; i <grp.size(); i++){
            num += grp[i];
        }
        cout << num << "\n";
        t--;
    }
    return 0;
}