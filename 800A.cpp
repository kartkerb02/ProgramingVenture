#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int a, b;
        cin >> a >> b;
        string s = "";
        int common = min(a,b);

        for(int  i = 0; i < common; i++){
            s += "01";
        }
        //s = "01"*common;
        if(a > b){
            int diff = a-b;
            for(int  i = 0; i < diff; i++){
                s += '0';
            }
        }
        else{
            int diff = b-a;
            for(int  i = 0; i < diff; i++){
                s += '1';
            }
        }
        cout << s << "\n";
        t--;
    }
    return 0;
}