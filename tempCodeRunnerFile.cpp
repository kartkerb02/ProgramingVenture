#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, temp;
        cin >> n;
        
        int clash[n+2] = {0};
        int out[n];
        for (int i = 1; i <= n; i++){
            cin >> temp;
            clash[i] = (temp == i)? 1 : 0;
            out[i] = i;
        }
        // for(int i = 1; i <= n ; i++){
        //     cout << clash[i] << " ";
        // }
        
        // cout << "\n";
        if(n == 1){
            cout << -1 << "\n";
        }
        else{
            int rem, temp;
            for(int i = 1; i <= n; i++){
                
                if(clash[i]){
                    
                    if(clash[i-1] || clash[i+1]){
                        if(clash[i-1]&&clash[i+1]){
                            out[i] = out[i+1];
                        }
                        else if(!clash[i-1]&&clash[i+1]){
                            rem = out[i];
                            out[i] = out[i+1];
                        }
                        else if(clash[i-1]&&!clash[i+1]){
                            out[i] = rem;
                        }
                    }
                    else{
                        if(i != n){
                            temp = out[i];
                            out[i] = out[i+1];
                            out[i+1] = temp;
                        }
                        else{
                            temp = out[i];
                            out[i] = out[i-1];
                            out[i-1] = temp;
                        }
                    }
                }
            }
            for(int i = 1; i <= n; i++){
                cout << out[i] << " ";
            }
            cout << "\n";
        }

        t--;
    }
    return 0;
}