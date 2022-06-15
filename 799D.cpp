//important GCD concept
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int t, int initial, int incr){
    int target = t*60 + t/10  + 10*(t%10);
    int X = gcd(60*24, incr);
    return (target - initial)%X == 0;
}

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
        int initial = 60*h + m;
        
        int out = 0;
        int Palins[] = {23 , 22, 21, 20, 15, 14, 13, 12, 11, 10, 05, 04, 03, 02, 01, 00};
        for(int i = 0; i < 16; i++){
            if(check(Palins[i], initial, incr)){
                out++;
            }
        }
        cout << out << "\n";
        t--;
    }
    return 0;
}