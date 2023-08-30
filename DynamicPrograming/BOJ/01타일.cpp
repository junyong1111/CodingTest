// https://jypark1111.tistory.com/136
#include <iostream>
#include <vector>
#define SIZE 1000001

using namespace std;

typedef long long ll;
vector<ll>dp(SIZE, -1);

ll tile_01(ll N){
    if(dp[N] == -1)
        dp[N] = (tile_01(N-1) + tile_01(N-2)) % 15746;
    return dp[N];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" , stdin);

    ll N = 0;
    cin >> N;

    dp[0] = 0; dp[1] = 1; dp[2] = 2;
    ll answer = tile_01(N) ;
    cout << answer << "\n";
    return 0;
}