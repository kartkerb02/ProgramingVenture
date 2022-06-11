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
        ll odd = 0, even = 0, out = 0;
        for(int i = 0; i < n; i++){
            cin >> temp;
            if(temp%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        out = even*(even-1)/2 + odd*(odd-1)/2;
        cout << out << "\n";
        t--;
    }
    return 0;
}