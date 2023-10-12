// https://jypark1111.tistory.com/157

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
ll dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};

void print(vector<vector<string> >&map){
    for(ll i=0; i<map.size(); i++){
        for(ll j=0; j<map[i].size(); j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
}

bool indexCheck(vector<vector<string> >&map, ll x, ll y){
    if(x < 0 || x >= map.size())
        return false;
    if(y < 0 || y >= map.size())
        return false;
    return true;
}


ll findmine(vector<vector<string> >&map, ll x, ll y){
    ll mine = 0;
    ll new_x;
    ll new_y;
    for(ll i=0; i<8; i++){ // 8방향을 탐색하면서 지뢰 갯수 확인
        new_x = x + dx[i];
        new_y = y + dy[i];
        if(indexCheck(map, new_x, new_y) == true && map[new_y][new_x] == "*"){
            mine++;
        }
    }
    return mine;
}

void gameover(vector<vector<string> >&map, vector<vector<string> >&answer){
    for(ll i=0; i<map.size(); i++){ // gameover 모든 지뢰 표시
        for(ll j=0; j<map.size(); j++){
            if(map[i][j] == "*")
                answer[i][j] = "*";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll n = 0;
    cin >> n;

    vector<vector<string> >map(n, vector<string>(n, "."));
    vector<vector<string> >answer = map;

    string str;
    for(ll i=0; i<n; i++){ // map 생성
        cin >> str;
        for(ll j=0; j<str.size(); j++){
            if(str[j] == '*')
                map[i][j] = "*";
        }
    }
    
    for(ll i=0; i<n; i++){ // 해당 위치를 오픈했을 때 지뢰가 아닌경우 근처 지뢰 갯수 표시
        cin >> str;
        for(ll j=0; j<str.size(); j++){
            if(str[j] == 'x'){
                if(map[i][j] == ".")
                    answer[i][j] = '0' + findmine(map, j, i);
                else // 지뢰를 밝은 경우 모든 지뢰 표시
                    gameover(map, answer);
            }
        }
    }
    print(answer);
    return 0;
}