// https://jypark1111.tistory.com/139
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll answer;

bool isPromise(vector<ll> &visit, ll index, ll i){
    for(ll j = index-1; j>=0; j--){
        if(visit[j] == i)
            return false;
    }
    for(ll j = index-1; j>=0; j--){
        if((index + i) == (j + visit[j]) || ((index - i))==((j - visit[j])))
            return false;
    }   
    return true;
}

void NQueen(vector<ll> &visit, ll index)
{
    if(index == visit.size()){
        answer = answer + 1;
        return;
    }
    
    for(ll i = 0; i<visit.size(); i++){
        if(isPromise(visit, index, i) == true){
            visit[index] = i;
            NQueen(visit, index+1);
            visit[index] = -1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt" , "r" ,stdin);

    ll N = 0;
    cin >> N;
    answer = 0;
    vector<ll>visit(N, -1);
    for(ll i=0; i<N; i++){
        visit[0] = i;
        NQueen(visit, 1);
        visit[0] = -1;
    }
    cout << answer << "\n";
    return 0;
}