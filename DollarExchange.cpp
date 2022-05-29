#include<bits/stdc++.h>
using namespace std;

inline bool go(int x){
    return x  < (x/2 + x/3 + x/4);
}
int exe(int x){
    if(go(x)){
        return exe(x/2) + exe(x/3) + exe(x/4);
    }
    return x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    cout << exe(t);
}