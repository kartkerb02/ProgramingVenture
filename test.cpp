#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        int x = 12;
        for(int i = 0; i < 20; i++){
            x+=x&-x;
            cout << x << "\n";
        }
        
    
    return 0;
}