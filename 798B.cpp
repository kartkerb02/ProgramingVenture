#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n;
        cin >> n;
        
        int orig[n+1] = {};
        int out[n+1] = {};
        for (int i = 1; i <= n; i++){
            cin >> orig[i];
            out[i] = i;
        }
        if(n == 1){
            cout << -1 << "\n";
        }
        else{
            for(int i = 1; i <= n; i++){
                if(orig[i] == out[i]){
                    if(i < n){
                        swap(out, i, i+1);
                    }
                    else if(i > 1){
                        swap(out, i , i-1);
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

