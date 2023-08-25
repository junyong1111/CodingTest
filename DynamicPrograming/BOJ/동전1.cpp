// https://jypark1111.tistory.com/131
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt" , "r" ,stdin);

    ll N, K;
    cin >> N >> K;

    // dp 배열 초기화. dp[i]는 합이 i가 되는 경우의 수를 나타냄.
    vector<ll> dp(K+1, 0);
    dp[0] = 1; // 합이 0이 되는 경우는 아무 동전도 사용하지 않는 경우 1가지 방법이 존재.

    // 동전의 가치를 입력받아 정렬한 후 사용.
    vector<ll> changes(N, 0);
    for(ll i = 0; i < N; i++)
        cin >> changes[i];
    sort(changes.begin(), changes.end());
    
    // 각 동전의 가치를 사용하여 가능한 경우의 수를 누적하여 계산.
    for(ll i = 1; i <= N; i++){
        for(ll j = changes[i-1]; j <= K; j++){
            // dp[j]에 dp[j - changes[i-1]]을 더함으로써, 현재 동전의 가치를 이용하여 합이 j가 되는 경우의 수를 갱신.
            dp[j] += dp[j - changes[i-1]];
        }    
    }

    // 합이 K가 되는 경우의 수 출력
    cout << dp[K] << "\n";
    return 0;
}
