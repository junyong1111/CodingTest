// https://jypark1111.tistory.com/137
#include <iostream>
#include <vector>
#define SIZE 1001

using namespace std;
typedef long long ll;

vector<ll>dp(SIZE, 0);

ll tileing(ll N){
    if(dp[N] == 0)
        dp[N] = (tileing(N-1) + tileing(N-2)) ;
    return dp[N]% 10007;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll N = 0;
    cin >> N;
    dp[1] = 1; dp[2] = 2;
    cout << tileing(N) << "\n";
    
    return 0;
}