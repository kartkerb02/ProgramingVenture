#include<bits/stdc++.h>
using namespace std;

void Merge(int* arr, int l, int m, int r){
    int i = l;
    int j = m+1;
    int k = l;

    int temp[r - l + 5];

    while(i <= m && j <= r){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= m){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= r){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}

void MergeSort(int* arr, int l, int r){
    if(l < r){
        int m = (r - l)/2 + l;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
    }
    
}

int main(){
    int A[] = {3,2,1,4,5,6};
    
    MergeSort(A, 0, 5);
    for(auto x : A){cout << x << "\n";}
    return 0;
}
