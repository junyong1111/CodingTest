// https://jypark1111.tistory.com/148
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll n = 0;
    ll input = 0;
    priority_queue<ll>pq;
    cin >> n;

    for(ll i=0; i<n; i++){
        cin >> input;
        if(input == 0){
            if(pq.size() == 0)
                cout << 0 << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
            pq.push(input);
    }
    
    return 0;
}