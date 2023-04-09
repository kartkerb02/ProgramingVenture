#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
  ll t;
  cin >> t;
  while(t--){
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    if(x1 > n/2) x1 = n + 1 - x1;
    if(x2 > n/2) x2 = n + 1 - x2;
    if(y1 > n/2) y1 = n + 1 - y1;
    if(y2 > n/2) y2 = n + 1 - y2;
    cout << abs(min(x1, y1) - min(x2, y2)) << "\n";
  }
  return 0;
}