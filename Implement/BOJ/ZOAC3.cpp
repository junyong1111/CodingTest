// https://jypark1111.tistory.com/166
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 3
#define M 5

using namespace std;

typedef long long ll;

vector<vector<char> >leftKey(N, vector<char>(M));
vector<vector<char> >rightKey(N, vector<char>(M+1));
pair<ll, ll>point;
pair<ll, ll>sl_point;
pair<ll, ll>sr_point;

void init(char left, char right){
    leftKey[0][0] = 'q'; leftKey[0][1] = 'w'; leftKey[0][2] = 'e';  leftKey[0][3] = 'r'; leftKey[0][4] = 't';
    leftKey[1][0] = 'a'; leftKey[1][1] = 's'; leftKey[1][2] = 'd';  leftKey[1][3] = 'f'; leftKey[1][4] = 'g';
    leftKey[2][0] = 'z'; leftKey[2][1] = 'x'; leftKey[2][2] = 'c';  leftKey[2][3] = 'v'; leftKey[2][4] = '0';

    rightKey[0][0] = '0'; rightKey[0][1] = 'y'; rightKey[0][2] = 'u'; rightKey[0][3] = 'i';  rightKey[0][4] = 'o'; rightKey[0][5] = 'p';
    rightKey[1][0] = '0'; rightKey[1][1] = 'h'; rightKey[1][2] = 'j'; rightKey[1][3] = 'k';  rightKey[1][4] = 'l'; rightKey[1][5] = '0'; 
    rightKey[2][0] = 'b'; rightKey[2][1] = 'n'; rightKey[2][2] = 'm';  rightKey[2][3] = '0'; rightKey[2][4] = '0'; rightKey[2][5] = '0'; 
    // 빈 자리는 '0'으로 대체 
    // 오른쪽 키보드 B는 살짝 들어와 있다...
    


    for(ll i=0; i<N; i++){
        for(ll j=0; j<M; j++){
            if(leftKey[i][j] != '0' && (leftKey[i][j] == left)){
                sl_point.first = i;
                sl_point.second = j;
            }
        }
    }
    for(ll i=0; i<N; i++){
        for(ll j=0; j<M+1; j++){
            if(rightKey[i][j] != '0' && (rightKey[i][j] == right)){
                sr_point.first = i;
                sr_point.second = j;
            }
        }
    }
}

void print(string key){
    if(key == "left"){
        for(ll i=0; i<N; i++){
            for(ll j=0; j<M; j++){
                if(leftKey[i][j] != '0')
                    cout << leftKey[i][j] << " ";
                }
                cout << "\n";
            }
    }   
    else{
        for(ll i=0; i<N; i++){
            for(ll j=0; j<M; j++){
                if(rightKey[i][j] != '0')
                    cout << rightKey[i][j] << " ";
            }
            cout << "\n";
        }
    }
}


ll findKey(char ch){
    for(ll i=0; i<N; i++){
        for(ll j=0; j<M; j++){
            if(leftKey[i][j] != '0' && (leftKey[i][j] == ch)){
                point.first = i;
                point.second = j;
                return 1;
            }
        }
    }
    // left 키보드에 위치 1
    for(ll i=0; i<N; i++){
        for(ll j=0; j<M+1; j++){
            if(rightKey[i][j] != '0' && (rightKey[i][j] == ch)){
                point.first = i;
                point.second = j;
                return 2;
            }
        }
    }
    return -1;
    // right 키보드에 위치 2
}


ll get_score(string key){
    ll distance = 0;
    if(key == "left"){
        distance = abs(sl_point.second - point.second) + abs(sl_point.first - point.first);
        sl_point = point;
    }
    else{
        distance = abs(sr_point.second - point.second) + abs(sr_point.first - point.first);
        sr_point = point;
    }
    return distance;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    char left, right;
    cin >> left >> right;
    string str;
    cin >> str;
    // ------- input --------

    init(left, right); 
    // step1. 키보드 Setting 


    // step2. find -> 완전탐색 input으로 들어간 문자가 키보드 어디에 위치했는지 좌표 저장 1은 왼쪽 키보드 2는 오른쪽 키보드
    // step3. get_score 시작 위치와 현재 문자의 위치를 계산
    ll answer = 0 ;
    for(ll i=0; i<str.size(); i++){
        if(findKey(str[i]) == 1) // 왼쪽 키보드
            answer += get_score("left");
        else // 오른쪽 키보드
            answer += get_score("right");
        answer++;
    }
    cout << answer << "\n";
    return 0;
}