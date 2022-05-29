#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t > 0){
        string num;
        cin >> num;
        cout << ((num[0] + num[1] + num[2]) == (num[3] + num[4] + num[5])? "YES": "NO") << "\n";
        t--;
    }


    return 0;
}