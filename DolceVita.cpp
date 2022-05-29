#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, x;
    cin >> t;
    while(t>0){
        cin >> n >> x;
        int rates[n];
        long long crates[n];
        for(int i = 0; i < n; i ++){
            cin >> rates[i];
        }
        sort(rates, rates + n);
        crates[0] = rates[0];
        for(int i = 1; i < n; i ++){
            crates[i] = crates[i-1] + rates[i];
            
        }
        
    
        long long lltn = n-1, days = 0, y;
        long long out = 0;
        while(crates[lltn] > x && lltn >= 0){
            lltn --;
        }
      
        while(lltn != -1){
            y = ((x- crates[lltn]) / (lltn+1)) +1 - days;
            days += y;
            out += y*(lltn+1);
            lltn--;
        }
        cout << out << "\n";
        t--;
    }

    return 0;
}

/*
while (mid > 0){
            high = n;
            low = 0;
            mid = n/2;
            if(x < crates[0] + offset){
                mid = 0;
            }
            else if(crates[n-1] + n*offset < x){
                mid = n;
            }
            else{
                while(high - low > 1){
                    if((crates[mid] + (mid+1)*offset) < x && (crates[mid+1] + (mid+2)*offset) > x){
                        break;
                    }
                    else if((crates[mid] + (mid+1)*offset) > x){
                        high = mid;
                    }
                    else{
                        low = mid;
                    }
                    mid = (low + high)/2;
                }
                mid ++;
            }
            out += mid;
            offset += 1;
        }
        */