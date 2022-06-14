#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// int numchar(string s, char c, int i, int j){
//     int sum = 0;
//     for(int x = i+1; x < j; x++){
//         if(s[x] == c){sum++;}
//     }
//     return sum;
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;   
    while(q){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        bool out = true;

        int tna = 0, tnc = 0, sna = 0, snc = 0;
        string frame_s = "", frame_t = "";
        vector<int> cnt_a_in_t;
        vector<int> cnt_c_in_t;
        vector<int> cnt_a_in_s;
        vector<int> cnt_c_in_s;
        for(int i = 0; i < n; i++){
            if(t[i] == 'a'){
                tna++;
                frame_t += 'a';
            }
            else if(t[i] == 'c'){
                tnc++;
                frame_t += 'c';
            }
            else if(t[i] == 'b'){
                cnt_a_in_t.push_back(tna);
                cnt_c_in_t.push_back(tnc);
            }

            if(s[i] == 'a'){
                sna++;
                frame_s += 'a';
            }
            else if(s[i] == 'c'){
                snc++;
                frame_s += 'c';
            }
            else if(s[i] == 'b'){
                cnt_a_in_s.push_back(sna);
                cnt_c_in_s.push_back(snc);
            }
        }
        if(cnt_a_in_s.size() == cnt_a_in_t.size() && frame_t == frame_s){
            for(int i = 0; i < cnt_a_in_s.size() && out; i++){
                if(cnt_a_in_s[i] < cnt_a_in_t[i]){
                    out = false;
                }
                if(cnt_c_in_s[i] > cnt_c_in_t[i]){
                    out = false;
                }
            }
        }
        else{
            out = false;
        }
        
        cout << (out? "YES" : "NO")  << "\n";
        q--;
    }
    return 0;
}





// vector<int> c_in_s;
//         c_in_s.push_back(-1);
//         vector<int> a_in_t;
//         a_in_t.push_back(-1);

//         for(int i = 0; i<n; i++){
//             if(s[i] == 'c' && t[i] == 'a'){
//                 out = false;
//             }
//             else if(s[i] == 'c'){
//                 c_in_s.push_back(i);
//             }
//             else if(t[i] == 'a'){
//                 a_in_t.push_back(i);
//             }
// //         }
// //         cout << out << " ";
// //         a_in_t.push_back(n);
// //         c_in_s.push_back(n);
// //         for(int i = 0; i < c_in_s.size() - 1 && out; i++){
// //             if(numchar(s, 'a', c_in_s[i], c_in_s[i+1]) != numchar(t, 'a', c_in_s[i], c_in_s[i+1])){
// //                 out = false;
// //             }
// //         }
// //         cout << out << " ";
// //         for(int i = 0; i < a_in_t.size() - 1 && out; i++){
// //             if(numchar(s, 'c', a_in_t[i], a_in_t[i+1]) != numchar(t, 'c', a_in_t[i], a_in_t[i+1])){
// //                 out = false;
// //             }
// //         }

// for(int i = 0; i < n && out ; i++){
//             if(s[i] != t[i]){
//                 if(s[i] == 'a' && t[i] == 'b'){
//                     int curr = i+1;
//                     while(curr < n && s[curr] != 'b'){
//                         if(s[curr] == 'c'){
//                             out = false;
//                             break;
//                         }
//                         curr++;
                        
//                     }
//                     if(curr == n){
//                         out = false;
//                     }
//                     else{
//                         cout << curr << 's';
//                         swap(s[i],s[curr]);
//                     }
//                 }
//                 else if(s[i] == 'c' && t[i] == 'b'){
//                     int curr = i+1;
//                     while(curr < n && t[curr] != 'c'){
//                         if(s[curr] == 'a'){
//                             out = false;
//                             break;
//                         }
//                         curr++;
                        
//                     }
//                     if(curr == n){
//                         out = false;
//                     }
//                     else{
//                         cout << curr << 't';
//                         swap(t[i],t[curr]);
//                     }
//                 }
//                 else{
//                     out = false;
//                 }
//             }
//         }