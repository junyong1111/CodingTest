// https://jypark1111.tistory.com/175
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

ll prefix_sum(pi p1, pi p2, vector<vector<ll> >&arr){
    ll sum = 0;
    for(ll i=p1.first; i<=p2.first; i++){
        for(ll j=p1.second; j<=p2.second; j++){
            sum += arr[i][j];
        }
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    ll n = 0; ll m = 0;
    cin >> n >> m;

    vector<vector<ll> >arr(n+1, vector<ll>(m+1, 0));
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }

    ll k =0 ; cin >> k;
    
    pi p1; pi p2;
    for(ll i=0; i<k; i++){
        cin >> p1.first >> p1.second >> p2.first >> p2.second;
        cout << prefix_sum(p1, p2, arr) << "\n";
    }
    return 0;
}
    