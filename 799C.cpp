#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n = 8;
        char board[9][9] = {};
        int num = 0;
        int x = -1, y = -1;
        int r = 1 , c = -1;
        bool get = false;
        for(int i = 1; i <= 8; i++){
            for(int j = 1; j <= 8; j++){
                cin >> board[i][j];
            }
        }
        for(int i = 1; i <= 8 && r*c < 0; i++){
            x = -10;
            y = -10;
            num = 0;
            for(int j = 1; j <= 8 && r*c < 0; j++){
                if(board[i][j] == '#'){
                    if(get){
                        r = i;
                        c = j;
                    }
                    num++;
                    if(x == -10){
                        x = j;
                    }
                    else{
                        y = j;
                    }
                    if(num == 2 && y-x == 2){
                        get = true;
                    }
                }
                
            }
            //cout << x << " " << y << "\n";
            
        }
        cout << r <<  " " << c << "\n";
        t--;
    }
    return 0;
}