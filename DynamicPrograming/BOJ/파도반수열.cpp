// https://jypark1111.tistory.com/143
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 101

using namespace std;
typedef long long ll;

vector<ll>dp(SIZE, 0);

ll Padovan(ll N){
    if(N<=3)
        return 1;
    if(dp[N] == 0)
        dp[N] = Padovan(N-2) + Padovan(N-3);
    return dp[N];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);
    
    ll N = 0;
    ll testCase= 0;
    
    cin >> testCase;
    while(testCase--){
        cin >> N;
        cout << Padovan(N) << "\n";
    }
    return 0;
}