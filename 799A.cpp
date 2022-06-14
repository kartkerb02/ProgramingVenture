#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int n = 0;
        if(b > a){
            n++;
        }
        if(c > a){
            n++;
        }
        if(d > a){
            n++;
        }
        cout << n << "\n";
        t--;
    }
    return 0;
}