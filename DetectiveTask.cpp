#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t > 0){
        string response;
        int n, right1, left0;

        cin >> response;
        n = response.size();
        right1 = -1;
        left0 = n;

        for(int i = 0; i < n; i++){
            if(response[i] == '1'){
                right1 = i;
            }
            if(response[i] == '0'){
                left0 = min(i,left0);
            }
        }
        if(left0 == n && right1 == -1){
            cout << n << "\n";
        }
        else if(left0 != n && right1 == -1){
            cout << left0 + 1 << "\n";
        }
        else if(left0 == n && right1 != -1){
            cout << n - right1 << "\n";
        }
        else{
            cout << left0 - right1 + 1 << "\n";
        }
        t--;
    }


    return 0;
}