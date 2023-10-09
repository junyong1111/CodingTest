// https://jypark1111.tistory.com/167
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define MAX_SZ 5
using namespace std;

typedef long long ll;

ll dx[2] = {-1, 1};

bitset<8>wheels[MAX_SZ];

void init(){
    string str;
    ll len = 7;
    for(ll i=1; i<MAX_SZ; i++){
        cin >> str;

        for(ll j=0; j<str.size(); j++){
            if(str[j] == '1')
                wheels[i][j] = 1;
            else
                wheels[i][j] = 0;
        }
    }
}

void print(){
    for(ll i=1; i<MAX_SZ; i++){
        cout << wheels[i] << "\n";
    }

}

bool is_possible(ll number){
    if(number < 1 || number >= MAX_SZ)
        return false;
    return true;
}

bool checkclock(ll number, string str){
    if(str == "left"){
        if(wheels[number][2] != wheels[number+1][6])
            return true; 
        else
            return false;
    }

    else{
        if(wheels[number-1][2] != wheels[number][6])
            return true; 
        else
            return false;
    }

} 


void move(ll number, bool flag){
    ll len = 7;
    if(flag == true){ // 시계방향으로
        if(wheels[number][len] == 1){ 
            wheels[number] = wheels[number] << 1;
            wheels[number][0] = 1;
        }
        else{
            wheels[number] = wheels[number] << 1;
            wheels[number][0] = 0;
        }
    }

    else{ // 반시계 방향으로
        if(wheels[number][0] == 1){
            wheels[number] = wheels[number] >> 1;
            wheels[number][len] = 1;
        }
        else{
            wheels[number] = wheels[number] >> 1;
            wheels[number][len] = 0;
        }

    }
}

void move_clockwise(ll number, bool clock){
    ll left = number + dx[0];
    ll right = number + dx[1];
    ll lcnt = 0; ll rcnt = 0;
    bool flag = clock; // 반시계
    if(is_possible(left) == true){
        for(ll i=left; i>=1; i--){
            if(checkclock(i, "left") == true){ // 서로 방향이 반대면 회전
                lcnt++;
            }
            else{
                break;
            }
        }
        for(ll i=0; i<lcnt; i++){
            move(left-i, flag);
            if(flag == true) flag = false;
            else flag = true;
        }
    } // left 케이스
    flag= clock;
    if(is_possible(right) == true){
        for(ll i=right; i<MAX_SZ; i++){
            if(checkclock(i, "right") == true){
                rcnt++;
            }
            else{
                break;
            }
        }
        for(ll i=0; i<rcnt; i++){
            move(right+i, flag);
            if(flag == true) flag = false;
            else flag = true;
        }
    } 
    if(clock == false)
        move(number, true);
    else
        move(number, false);
    
}

ll get_score(){
    ll answer = 0;
    for(ll i=1; i<MAX_SZ; i++){
        if(wheels[i][0] == 1){
            if(i == 1) answer += i;
            if(i == 2) answer += i;
            if(i == 3) answer += 4;
            if(i == 4) answer += 8;
        }
    }
    return answer;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    init();
    // ---- step1. 톱니바퀴 셋팅 ----

    ll k = 0; ll number =0; ll clock = 0;
    cin >> k;
    while(k--){
        cin >> number >> clock;
        if(clock == 1){ // 시계 방향
            move_clockwise(number, false);
        }
        else{ // 반시계 방향
            move_clockwise(number, true);
        }
    }

    // ---- step3. 총 점수 계산 ----

    ll answer = get_score();
    cout << answer << "\n";

    return 0;
}