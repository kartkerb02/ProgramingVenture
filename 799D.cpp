#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        string init;
        int incr;
        cin >> init >> incr;

        int h = stoi(init.substr(0,2));
        int m = stoi(init.substr(3,2));
        int curr = 60*h + m;
        int initial = curr;
        
        int out = 0;
        while(true){
            if(palin(curr)){
                out++;
            }
            curr+=incr;
            if(curr == initial){
                break;
            }
        }
        cout << out << "\n";
        t--;
    }
    return 0;
}