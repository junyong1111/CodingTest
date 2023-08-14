// https://jypark1111.tistory.com/108
#include <iostream>
#include <algorithm>
#define MAXINPUT 41

using namespace std;

typedef long long ll;

ll f[MAXINPUT];
ll recursion;
ll dp;

ll fib(ll n) {
    if (n ==1 or n == 2){
        return 1;
    }
    else {
        recursion ++;  // 재귀 소환 시 1증가
        return (fib(n - 1) + fib(n - 2));
    }
}

ll fibonacci(ll n) {
    if (n == 1 or n== 2)
        return 1;
    if(f[n] == 0){
        // 계산이 필요한 경우만 증가
        dp++;
        f[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return f[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    ll n = 0;
    cin >> n ;

    ll rec = fib(n);
    ll dynamic = fibonacci(n);
    cout << recursion+1 << " " << dp << "\n";
    return 0;
}