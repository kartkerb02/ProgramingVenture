#include<bits/stdc++.h>
using namespace std;

void fun(int n){
    int g, l, rem, rempro;
    for (int c = 1; c< n; c++){
        for (int d = 1; d< n; d++){
            if((n-d)%c == 0 && (n-c)%d == 0){
                g = lcm(c, d);
                rem = n - c - d;
                if(rem%g == 0){
                    rempro = rem/g;
                    for (int i = 1; i< rempro; i+=2){
                        if(gcd(i,rempro-i) == 1){
                            cout << i*g << " " << (rempro-i)*g << " " << c << " " << d << "\n";
                            return;
                        }
                    }
                }

            }
        }
    }
    return;
}
void fun2(int n){
    cout << 1 << " " << n-3 << " " << 1 << " " << 1 << "\n";
    return;
}

int main(){
    
    int t, n;
    cin >> t;
    for(int i = 0; i< t; i++){
        cin >> n;
        fun2(n);
    }
    return 0;
}
