// https://jypark1111.tistory.com/165
#include <iostream>
#include <bitset>
#include <string>
#include <set>

#define MAX_SIZE 100000
using namespace std;

typedef long long ll;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll n = 0; // 기차의 수
    ll m = 0; // 명령의 수
    cin >> n >> m;

    bitset<20>bits[MAX_SIZE];

    ll first, second, third;
    for(ll i=0; i<m; i++){
        cin >> first;
        switch (first)
        {
        case 1:
            cin >> second >> third;
            bits[second-1][third-1] = 1; 
            break;
        case 2:
            cin >> second >> third;
            bits[second-1][third-1] = 0; 
            break;
        case 3:
            cin >> second;
            bits[second-1] <<= 1;
            break;
        case 4:
            cin >> second;
            bits[second-1] >>= 1;
            break;
        }
    }

    set<string>unique_bits;

    for(ll i=0; i<n; i++){
        unique_bits.insert(bits[i].to_string());
    }

    cout << unique_bits.size()  << "\n";
    
    
    return 0;
}