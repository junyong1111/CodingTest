// https://jypark1111.tistory.com/147
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll max_value(vector<vector<ll> >&dp){
    ll max_val = 0;
    for(ll i=0; i<dp.size(); i++){
        for(ll j=0; j<dp.size(); j++){
            if(max_val < dp[i][j]){
                max_val = dp[i][j];
            }
        }
    }
    return max_val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    ll n = 0;
    cin >> n;

    vector<vector<ll> >triangle(n, vector<ll>(n, 0));
    vector<vector<ll> >dp(n, vector<ll>(n, 0));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<=i; j++)
            cin >> triangle[i][j];
    }
    dp[0][0] = triangle[0][0];
    for(ll i=1; i<n; i++){
        for(ll j=0; j<=i; j++){
            if(j==0){
                dp[i][j] = dp[i-1][j] + triangle[i][j]; // 자신의 위 + 자기 자신
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) +  triangle[i][j]; // 왼쪽 대각, 자신의 위 중 큰 값 + 자기 자신
            }
        }
    }

    cout << max_value(dp) << "\n";
    return 0;
}