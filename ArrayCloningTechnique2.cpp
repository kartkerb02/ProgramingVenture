
#include<bits/stdc++.h>

using namespace std;

int mostFrequent(long long int arr[], int n)
{
    // Sort the array
    sort(arr, arr + n);
 
    // find the max frequency using linear traversal
    int max_count = 1, res = arr[0], curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]){
            curr_count++;
            if (curr_count > max_count) {
                max_count = curr_count;
                res = arr[i - 1];
            }
        }
        else{
            curr_count = 1;
        }
        
    }
    return max_count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    int l, temp;
    while (n > 0){
        cin >> l;
        long long int A[l];
        for (int i =0; i< l; i++){
            cin >> A[i];
        }
        int mx = mostFrequent(A ,l);
        temp = ceil(log2(float(l)/mx)) + l - mx;
        cout <<  temp << "\n";
        n--;
    }
    return 0;
}
