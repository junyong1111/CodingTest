// https://jypark1111.tistory.com/141
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 15
using namespace std;

typedef long long ll;

typedef struct TiPi{
    ll ti;
    ll pi;
}TiPi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll N = 0;
    cin >> N;
    vector<ll>dp(MAX_SIZE+1, 0);
    vector<TiPi>tipi(MAX_SIZE+1);
    for(ll i=1; i<=N; i++)
        cin >> tipi[i].ti >> tipi[i].pi;
    ll answer = 0;
    for(ll i=N; i>=1; i--){
        if(i + tipi[i].ti <= N+1){ // 현재 날짜로부터 상담이 가능한경우 dp테이블 갱신 가능 워킹 백워드 방식으로 뒤부터 접근 
            dp[i] = max(dp[i+1], dp[i+tipi[i].ti] + tipi[i].pi);
            // 현재 dp 테이블의 값은 2가지 중 최댓값으로 설정
            // 1. 현재 상담을 선택하지 않는 경우 -> 이전 상담값
            // 2. 현재 상담을 선택한 경우 -> 상담이 끝나는 시점의 값과 자기 자신의 값
            // 2개의 값 중 큰 값을 선택하여 dp 테이블 갱신
        }
        else
            dp[i] = dp[i+1]; //상담이 불가능한 경우 그 다음날 값을 가져옴
    }
    cout <<  *max_element(dp.begin(), dp.end()) << "\n";
    
    return 0;
}