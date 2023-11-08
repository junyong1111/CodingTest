#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll n = 0;
    cin >> n;
    vector<ll>v(n, 0);
    for(ll i =0; i<n; i++)
        cin >> v[i];
    sort(v.rbegin(), v.rend());

    ll answer =0 ;
    for(ll i=0; i<n; i++){
        if(v[i] - i >= 0){answer += v[i] -i;}
    }
    cout << answer << "\n";
}