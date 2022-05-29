#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
int main()
{
    int nsq = 0;
    
    for(int i = 1000; i < 10000; i++){
        if((i*i - i)%10000 == 0){
            cout  << i << " ";
        }
    }
    cout << "\n";
    return 0;
}