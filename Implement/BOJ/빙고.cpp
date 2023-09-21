// https://jypark1111.tistory.com/153
#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 5

using namespace std;

typedef long long ll;

vector<vector<ll> >board(SIZE, vector<ll>(SIZE, 0));
void print(){
    for(ll i=0; i<SIZE; i++){
        for(ll j=0; j<SIZE; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}
void find_number(ll number){
    for(ll i=0; i<SIZE; i++){
        for(ll j=0; j<SIZE; j++){
            if(board[i][j] == number){
                board[i][j] = -1;
                return;
            }
        }
    }
}
ll bingo()
{
    ll x_b = 0;
    ll y_b = 0;
    ll dia = 0;
    ll j = 0;
    ll i = 0;

    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++)
        {
            if(board[i][j] == -1)
                continue;
            else
                break;
        }
        if(j == SIZE){
            x_b ++;
        }
    }

    for(j=0; j<SIZE; j++){
        for(i=0; i<SIZE; i++)
        {
            if(board[i][j] == -1)
                continue;
            else
                break;
        }
        if(i == SIZE){
            y_b ++;
        }
    }
    for(i=0; i<SIZE; i++){
        if(board[i][i] == -1)
            continue;
        else
            break;
    }
    if(i==SIZE)
        dia++;

    for(i=SIZE-1; i>=0; i--){
        if(board[(SIZE-1)-i][i] == -1)
            continue;
        else
            break;
    }
    if(i==-1)
        dia++; 
    return (x_b + y_b + dia);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt" ,"r" ,stdin);

    for(ll i=0; i<SIZE; i++){
        for(ll j=0; j<SIZE; j++)
            cin >> board[i][j];
    }

    ll number = 0;
    ll count = 0;
    for(ll i=0; i<SIZE; i++){
        for(ll j=0; j<SIZE; j++){
            cin >> number;
            find_number(number);
            count++;
            if(bingo()>=3){
                cout << count << "\n";
                return 0;
            }
        }
    }

    return 0;
}