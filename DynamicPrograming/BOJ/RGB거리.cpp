// https://jypark1111.tistory.com/145
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 1001
#define INF 2147483647

using namespace std;

typedef long long ll;;
typedef struct RGB{
    ll r;
    ll g;
    ll b;
}RGB;
vector<RGB>dp(SIZE);
ll min_value(){
    ll answer = INF ;
    if(dp[0].r < answer)
        answer = dp[0].r;
    if(dp[0].g < answer)
        answer = dp[0].g;
    if(dp[0].b < answer)
        answer = dp[0].b;
    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll N = 0;
    cin >> N ;
    vector<RGB>rgb(N);
    

    for(ll i=0;i <N; i++)
        cin >> rgb[i].r >> rgb[i].g >> rgb[i].b;

    dp[N-1] = rgb[N-1];
    
    for(ll i=N-2; i>=0; i--){
        dp[i].r = min(dp[i+1].g, dp[i+1].b) + rgb[i].r;
        dp[i].g = min(dp[i+1].r, dp[i+1].b) + rgb[i].g;
        dp[i].b = min(dp[i+1].r, dp[i+1].g) + rgb[i].b;
    }
    cout << min_value() << "\n";
    return 0;
}