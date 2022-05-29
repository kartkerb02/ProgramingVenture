
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    
 
    long long int t, n , a, b;
    cin >> t;
    while(t > 0){
        cin >> n >> a >> b;
 
        long long int A[n+1];
        A[0] = 0;
        long long int sum = 0, out;
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            sum += A[i];
        }
        long long int curr = 0;
        out = curr;
        for(int i = 0; i < n; i++){
            curr += (A[i+1] - A[i])*(a - (n-i-1)*b);
            out = min(out, curr);
        }
        cout << out + sum*b << endl;
        t--;
    }
 
}
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll c[200005];
// ll s[200005];
// int main()
// {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n,a,b;
// 		cin>>n>>a>>b;
// 		for(int i=1;i<=n;i++){
// 			cin>>c[i];
// 		}
// 		for(int i=n;i>=1;i--){
// 			s[i]=s[i+1]+c[i]; // s[i] = c[i] + c[i+1] ... c[n]  // n-k+1 terms
// 		}
// 		ll ans=0;
// 		ll pos=0; // curr posn of capital
// 		for(int i=1;i<=n;i++){
// 			ans+=(c[i]-pos)*b; //conquring next empire
// 			if((s[i+1]-(n-i)*pos)*b>=b*(s[i+1]-(n-i)*c[i])+a*(c[i]-pos)){   //not shifting vs shifting
// 				ans+=a*(c[i]-pos); //toll of capital shift
// 				pos=c[i]; // capital shift
// 			}
// 		}
// 		cout<<ans<<endl;
// 	}
// 	return 0;
// }