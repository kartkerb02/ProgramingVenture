#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, a, b, c;
    cin >> t;
    while(t > 0){
        cin >> a >> b >> c;
        cout << a+b+c << " " <<  b+c << " "  << c  << "\n";
        t--;
    }
}