#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> ParseString(string s, char del){
    vector<string> words;
    stringstream sstream(s);
    string token;
    while (std::getline(sstream, token, del)){
        words.push_back(token);
    }
    return words;
}

int MaxSumSubstring(int* Arr, int n){
    int curr_max = Arr[0];
    int max_so_far = Arr[0];
    for(int i = 1 i < n; i++){
        curr_max = max(curr_max + A[i], A[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main(){
    

    return 0;
}