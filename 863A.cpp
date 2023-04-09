#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
  ll t;
  cin >> t;
  while(t--){
    ll n;
    char d;
    cin >> n >> d;  

    string s;
    cin >> s;

    ll ind = 0;
    while(ind < n && s[ind] >= d) ind++;
    cout << s.substr(0, ind) + d + s.substr(ind, n - ind) << "\n";
  }
  return 0;
}