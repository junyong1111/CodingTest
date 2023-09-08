// https://jypark1111.tistory.com/144
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool minusCheck(vector<ll>&numbers){
    for(ll i=0; i<numbers.size(); i++){
        if(numbers[i] > 0){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll N = 0;
    cin >> N;
    vector<ll>numbers(N, 0);
    vector<ll>answer(N, 0);
    for(ll i=0; i<N; i++)
        cin >> numbers[i];
    if(minusCheck(numbers) == true){
        cout << *max_element(numbers.begin(), numbers.end()) << "\n";
        return 0;
    }

    answer[0] = numbers[0];
    for(ll i=1; i<N; i++){
        ll temp = numbers[i] + answer[i-1];
        if (temp < 0)
            answer[i] = 0;
        else
            answer[i] = temp;
    }

    cout << *max_element(answer.begin(), answer.end()) << "\n";

    return 0;
}