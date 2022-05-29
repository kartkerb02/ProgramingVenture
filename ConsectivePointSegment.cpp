#include<bits/stdc++.h>
using namespace std;

void exe(){
    int n;
    cin >> n;
    int ones = 0, twos = 0, prev, curr;
    cin >> prev;
    if(n == 1){
        cout << "YES" << "\n";
        return;
    }
    else{
        for(int i =1; i< n; i++){
            cin >> curr;
            if(curr - prev > 3){
                cout << "NO" << "\n";
                return;
            }
            else if(curr - prev == 3){
                twos += 1;
            }
            else if(curr - prev == 2){
                ones += 1;
            }
            prev = curr;
        }
        if ((twos == 1 && ones == 0) || (twos ==0 && ones <= 2)){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t > 0){
        exe();
        t--;
    }
}