#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int solve(vector<string> &A) {
    int n = A.size();
    if(n < 3) return 0;
    
    vector<double> f3(3);
    double sum = 0;
    for(int i = 0; i < 3; i++){
        f3[i] = stod(A[i]);
        sum += stod(A[i]);
    }
    sort(f3.begin(), f3.end());
    for(int i = 3; i < n; i++){
        if(sum > 1 && sum < 2) return 1;
        else if(sum > 2){
            if(stod(A[i]) < f3[2]){
                sum += stod(A[i]) - f3[2];
                f3[2] = stod(A[i]);
                sort(f3.begin(), f3.end());
            }
        }
        else{
            if(stod(A[i]) > f3[0]){
                sum += stod(A[i]) - f3[0];
                f3[0] = stod(A[i]);
                sort(f3.begin(), f3.end());
            }
        }
        // cout << f3[0] << " " << f3[1] << " " << f3[2] << "\n"; 
    }
    return 0;
    
    
}


int main(){
	vector<string> A = {"2.673662", "2.419159", "0.573816", "2.454376", "0.403605", "2.503658", "0.806191"};
	cout << solve(A);
	return 0;
}