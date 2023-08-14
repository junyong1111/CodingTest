// https://jypark1111.tistory.com/111
#include <iostream>
#include <algorithm>
#define MAXINPUT 51

using namespace std;

typedef long long ll;

ll dp[MAXINPUT][MAXINPUT][MAXINPUT];

ll w(ll a, ll b, ll c){
    if(dp[a][b][c] != 0) // 테이블에 이미 계산된 값이 저장되어 있다면 추가 계산 없이 테이블 값 반환 
        return dp[a][b][c];
    if (a > 20 or b > 20 or c > 20){ // 계산된 값이 없다면 주어진 식에 맞게 테이블 갱신
        dp[a][b][c] = w(20, 20, 20);
    } 
    else if (a < b and b < c){
        dp[a][b][c] = (w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c));
    }
    else{
        dp[a][b][c] = (w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1));
    }
    return dp[a][b][c]; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    ll a, b, c;
    cin >> a >> b >> c;
    
    for(ll i=0; i<MAXINPUT; i++){ // i, j, k 중 1개라도 1이 들어간다면 해당 값은 무조건 1이다.
        for(ll j=0; j<MAXINPUT; j++){ // 미리 3차원 배열에 가장 작은 값부터 계산하여 테이블을 채움
            for(ll k=0; k<MAXINPUT; k++){
                if (i == 0 or j == 0 or k ==0)
                    dp[i][j][k] = 1;
            }
        }
    }
    while(true){
        if (a == -1 and b == -1 and c == -1)
            return 0; // 종료 처리
        else{
            if(a < 0 or b < 0 or c < 0) // 음수 처리
                cout << "w(" << a <<", " << b << ", " << c << ") = " << 1 << "\n";   
            else
                cout << "w(" << a <<", " << b << ", " << c << ") = " << w(a,b,c) << "\n";
            cin >> a >> b >> c;
        }
    }
    return 0;
}