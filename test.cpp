#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string add(string s1, string s2){
    int n1 = s1.size();
    int n2 = s2.size();
    int mx = max(n1, n2);
    
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    if(n1 < n2){
        s1 += string(n2 - n1,'0');
    }
    else{
        s2 += string(n1 - n2,'0');
    }
    
    string out = "";
    int carry = 0;
    int curr;
    for(int i = 0; i < mx; i++){
        curr = (int)s1[i] - 48 + (int)s2[i] - 48 + carry;
        if(curr > 9){
            carry = 1;
            curr -= 10;
        }
        else{
            carry = 0;
        }
        out += char(curr + 48);
    }
    if(carry == 1){
        out += '1';
    }
    reverse(out.begin(), out.end());
    return out;
}
string multiply_x(string s, char x){
    int c = (int)x - 48;
    int carry = 0, temp;
    string out = "";
    for(int i = s.size() -1 ; i >= 0; i--){
        temp = ((int)s[i]-48)*c + carry;
        out += char(temp%10 + 48);
        carry = temp/10;
    }
    if(carry != '0'){
        out += char(carry + 48);
    }
    reverse(out.begin(), out.end());
    return out;
}
string multiply(string num1, string num2) {
    string out = "";
    string temp;
    for(int i = num1.size() - 1; i >= 0; i--){
        temp = multiply_x(num2, num1[i]) + string(num1.size() - 1 - i ,'0');
        out = add(temp, out);
    }
    return out;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    //cout << add("12","93");
    cout << multiply("123", "49");
        
    
    return 0;
}