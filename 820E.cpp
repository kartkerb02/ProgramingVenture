#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(int a, int b){
    cout << "? " << a << " " << b << "\n" << flush;
    int out;
    cin >> out;
    return out;
    // cout.flush()
}
void output(int x){
    cout << "! " << x << "\n" << flush;
    // cout.flush();
}
int main(){
    ll lb = 3, ub = 1e18;
    int cnt = 0;
    for(int i = 0; i < 50; i++){
        int b = (lb + ub)/2;
        int a = rand()%b;
        int resp = query(a, b);
        if(resp == -1){
            ub = b - 1;
        }
        else{
            lb = max(b, resp);
        }
    }
    output(lb);
    
    return 0;
}