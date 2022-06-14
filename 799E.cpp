#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n , req, total = 0, temp;
        cin >> n >> req;
        vector<int> A;
        for(int i = 0; i < n; i++){
            cin >> temp;
            if(temp == 1){
                A.push_back(i);
                total++;
            }
        }
        if(total < req){
            cout << -1 << "\n";
        }
        else if(total == req){
            cout << 0 << "\n";
        }
        else{
            int mx = 0;
            int l = A.size();
            for(int i = 1; i + req - 1 < l - 1; i++){
                mx = max(mx, A[i+req] - A[i - 1] - 1);
            }
            mx = max(mx, A[req]);
            mx = max(mx, n - A[l - req - 1] - 1);
            cout << n - mx << "\n";
        }
        t--;
    }
    return 0;
}