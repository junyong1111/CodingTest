// https://jypark1111.tistory.com/155
#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 14

using namespace std;
typedef long long ll;

ll BNP(ll money, vector<ll>&days){
    ll stock = 0;
    for(ll i=1; i<=SIZE; i++){
        if(money == 0)
            break;
        else{
            stock = stock +(money/days[i]);
            money = money % days[i];
        }
    }
    return money + stock*days[SIZE];
}  

bool buypossible(vector<ll>&days, ll index){
    ll testcase = 2; // 현재 날짜 이전부터 최근 3일간 가격이 하락한 경우
    ll idx = index-1;
    while(testcase--){
        if(days[idx] < days[idx-1])
            idx--;
        else
            return false;
    }
    return true;
}

bool sellpossible(vector<ll>&days, ll index){ // 현재 날짜 이전부터 최근 3일간 가격이 상승한 경우
    ll testcase = 2;
    ll idx = index-1;
    while(testcase--){
        if(days[idx] > days[idx-1])
            idx--;
        else
            return false;
    }
    return true;
}


ll TIMING(ll money, vector<ll>&days){
    ll i = 0;
    ll stock = 0;
    for(i=4; i<= SIZE; i++){
        if(buypossible(days, i) == true && money != 0){ // 돈이 있고 3일 연속 가격이 하락세라면 전량 구매
            stock = stock +(money/days[i]);
            money = money % days[i];
        }
        else if(sellpossible(days, i) == true && stock != 0){ // 주식이 있고 3일 연속 상승세라면 전량 매도
            money += stock * days[i];
            stock = 0;
        }
    }
    return money + (stock * days[SIZE]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll money = 0;
    cin >> money;

    vector<ll>days(SIZE+1, 0);
    for(ll i=1; i<=SIZE; i++)
        cin >> days[i];

    ll bnp = BNP(money, days);
    ll timing = TIMING(money, days);

    if(bnp < timing)
        cout << "TIMING\n";
    else if(bnp > timing)
        cout << "BNP\n";
    else
        cout << "SAMESAME\n";
    return 0;
}